#if !defined(SETUP_ESP32)
#define SETUP_ESP32

#include "shared/dependencies.h"
#include "components/ESP32/features/update_firmware_ota.h"

void setup_ESP32()
{
    serial.println("[ESP32] SETUP STARTED!");

    //* Setup bluetooth
    btStop();

    //* Setup OTA
    setup_OTA();

    //* Setup Watchdog
    esp_task_wdt_init(60, true);
    esp_task_wdt_add(NULL);

    serial.println("[ESP32] SETUP FINISHED!");
}

#endif // SETUP_ESP32