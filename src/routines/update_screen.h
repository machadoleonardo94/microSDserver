#ifndef SCREEN_ROUTINE
#define SCREEN_ROUTINE

#include "shared/dependencies.h"
#include "components/DISPLAY/setup.h"
#include "components/DISPLAY/constants.h"

// #include "utilities/WIFI.h"

#define _width 128
#define _height 64

void updateDisplay();
void connectWiFiScreen();

void updateDisplay()
{
    // Display the IP address
    display.clearDisplay();
    display.setCursor(0, LINE3); // Adjust vertical position
    display.print("IP: ");
    display.print(WiFi.localIP());
    display.display();
}

void connectWiFiScreen()
{
    display.clearDisplay();
    display.setTextSize(1); // Set text size to 2 (you can adjust the size as needed)
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, LINE1);
    display.print("    WiFi setup  ");
    display.setCursor(0, LINE2);
    display.print("  Draw pretty screen  ");
    display.display();
}

#endif