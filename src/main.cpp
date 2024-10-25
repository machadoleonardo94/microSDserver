//* ---------------------- IMPORTS ----------------------
//* Shared:
#include "shared/dependencies.h"

FtpServer ftpSrv;

void setup()
{
    //* --- INIT COMPONENT SETUP ---
    serialMon.begin(115200);
    setup_WIFI();
    setup_ESP32();
    setup_LEDS(); //* Enables debug WS2812B LED
    setup_display();
    if (setup_sdcard())
        ftpSrv.begin("esp32", "esp32");

    //* Finished startup routine.
    loopTimer = millis();
}

//* -------------------------------------------------------
//* ----------------------  Loop ----------------------
//* -------------------------------------------------------
void loop()
{
    ArduinoOTA.handle();
    ftpSrv.handleFTP();
    //? Dá comida pro cachorro não morder
    esp_task_wdt_reset();
    if (millis() - loopTimer > 1000)
    {
        loopTimer = millis();
        updateDisplay();
        // Serial.println("ping");
    }
}