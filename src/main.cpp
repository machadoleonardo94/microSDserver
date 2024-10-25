//* ---------------------- IMPORTS ----------------------
//* Shared:
#include "shared/dependencies.h"

//* --------------------------------------------------------
//* ---------------------- Void Setup ----------------------
//* --------------------------------------------------------
void setup()
{
    //* --- INIT COMPONENT SETUP ---
    serialMon.begin(115200);
    setup_WIFI();
    setup_ESP32();
    setup_LEDS(); //* Enables debug WS2812B LED
    setup_display();
    setup_sdcard(); //* Enables microSD card for datalog
    //  check_backlog_files();

    /*
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SD, "/index.html", "text/html"); });
    server.serveStatic("/", SD, "/");
    server.begin();
    */
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
        updateDisplay();
        // Serial.println("ping");
    }
}