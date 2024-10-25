#if !defined(CONNECT_WIFI)
#define CONNECT_WIFI

#include "shared/dependencies.h"

void saveCredentials(const char *ssid, const char *password)
{
    EEPROM.begin(512);
    for (int i = 0; i < 32; ++i)
    {
        EEPROM.write(EEPROM_WIFI_SSID_START + i, ssid[i]);
        EEPROM.write(EEPROM_WIFI_PASS_START + i, password[i]);
    }
    EEPROM.commit();
}

void loadCredentials(char *ssid, char *password)
{
    EEPROM.begin(512);
    for (int i = 0; i < 32; ++i)
    {
        ssid[i] = EEPROM.read(EEPROM_WIFI_SSID_START + i);
        password[i] = EEPROM.read(EEPROM_WIFI_PASS_START + i);
    }
    ssid[32] = '\0';
    password[32] = '\0';
}

bool setup_WIFI()
{

    WiFiManager wifiManager;
    wifiManager.setAPCallback([](WiFiManager *myWiFiManager)
                              {
        Serial.println("Entered config mode");
        Serial.println(WiFi.softAPIP());
        Serial.println(myWiFiManager->getConfigPortalSSID()); });

    wifiManager.setSaveConfigCallback([]()
                                      { Serial.println("Should save config"); });

    wifiManager.setConfigPortalTimeout(60); // Set timeout to 1 minute
    wifiManager.setHostname("Safeboat Webserver");

    if (!wifiManager.autoConnect("Safeboat Webserver"))
    {
        Serial.println("Failed to connect and hit timeout");
        return false;
    }

    Serial.println("Connected to WiFi");

    // Save credentials to EEPROM
    saveCredentials(WiFi.SSID().c_str(), WiFi.psk().c_str());

    return true;
}

#endif // CONNECT_WIFI
