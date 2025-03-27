//* ---------------------- IMPORTS ----------------------
//* Shared:
#include "shared/dependencies.h"

// OTA Hub via GitHub
#define OTAGH_OWNER_NAME "machadoleonardo94"
#define OTAGH_REPO_NAME "microSDserver"
#include <OTA-Hub-diy.hpp>

// Networking
static const char *WIFI_SSID = "Silvia";
static const char *WIFI_PASS = "1011121314";
#include <WiFiClientSecure.h>
WiFiClientSecure wifi_client;

void setup()
{
    //* --- INIT COMPONENT SETUP ---
    serialMon.begin(115200);
    setup_WIFI();
    setup_ESP32();
    setup_LEDS(); //* Enables debug WS2812B LED
    setup_display();

    WiFi.begin(WIFI_SSID, WIFI_PASS);

    if (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("WiFi failure");
        ESP.restart();
    }

    // Initialise OTA
    wifi_client.setCACert(OTAGH_CA_CERT); // Set the api.github.cm SSL cert on the WiFi Client
    OTA::init(wifi_client);

    // 1. Check for updates, by checking the latest release on GitHub
    // .. (n.b. get more control on OTA Hub Pro!)
    OTA::UpdateObject details = OTA::isUpdateAvailable();
    details.print();

    if (OTA::NO_UPDATE == details.condition)
    {
        Serial.println("No new update available. Continuing...");
    }
    else
    // 2. Perform the update (if there is one)
    {
        OTA::InstallCondition result = OTA::performUpdate(&details);

        if (result == OTA::REDIRECT_REQUIRED)
        {
            // Step 3: Follow GitHub's redirect to get the asset files
            // .. (n.b. this is faster and easier over on OTA Hub Pro!)
            wifi_client.setCACert(OTAGH_REDIRECT_CA_CERT); // Set the objects.githubusercontent.com SSL cert
            OTA::continueRedirect(&details);               // Follow the redirect and performUpdate.
        }
    }

    //* Finished startup routine.
    loopTimer = millis();
}

//* -------------------------------------------------------
//* ----------------------  Loop ----------------------
//* -------------------------------------------------------
void loop()
{
    ArduinoOTA.handle();
    //? Dá comida pro cachorro não morder
    esp_task_wdt_reset();
    if (millis() - loopTimer > 1000)
    {
        loopTimer = millis();
        // updateDisplay();
        Serial.printf("Updated firmware yey \n");
    }
}