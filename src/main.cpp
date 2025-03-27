//* ---------------------- IMPORTS ----------------------
//* Shared:
#include "shared/dependencies.h"

// OTA Hub via GitHub
#define OTAGH_OWNER_NAME "machadoleonardo94"
#define OTAGH_REPO_NAME "OTA-Hub-diy-example_project"
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
    wifi_client.setCACert(OTAGH_CA_CERT); // Set the api.github.cm SSL cert on the WiFiSecure modem
    OTA::init(wifi_client);

    // Check OTA for updates
    OTA::UpdateObject details = OTA::isUpdateAvailable();
    details.print();
    if (OTA::NO_UPDATE != details.condition)
    {
        Serial.println("An update is available!");
        // Perform OTA update
        OTA::InstallCondition result = OTA::performUpdate(&details);
        // GitHub hosts files on different server, so we have to follow the redirect, unfortunately.
        if (result == OTA::REDIRECT_REQUIRED)
        {
            wifi_client.setCACert(OTAGH_REDIRECT_CA_CERT); // Now set the objects.githubusercontent.com SSL cert
            OTA::continueRedirect(&details);               // Follow the redirect and performUpdate.
        }
    }
    else
    {
        Serial.println("No new update available. Continuing...");
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
        Serial.println(".");
    }
}