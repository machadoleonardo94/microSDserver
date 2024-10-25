#if !defined(SETUP_SDCARD)
#define SETUP_SDCARD

//* Dependências
#include "shared/dependencies.h"
#include "components/SDCARD/features/sdcardFunctions.h"

void setup_sdcard()
{
    serialMon.println("[SD CARD] SETUP STARTED!");

    //* Pin mode initialization:
    pinMode(digital_input_sd_on, INPUT);
    if (digitalRead(digital_input_sd_on))
    {
        serialMon.println("No SD card attached");
        return;
    }

    if (!SD.begin(CS_pin))
    {
        serialMon.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        serialMon.println("No readable SD card attached");
        return;
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    serialMon.printf("SD Card Size: %lluMB\n", cardSize);
    serialMon.println("[SD CARD] SETUP FINISHED!");
}

#endif // SETUP_SDCARD
