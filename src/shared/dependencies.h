//? ------------------------------------------------------------------------------------------
//*! This file contains all the common definitions and includes for the project.
//? ------------------------------------------------------------------------------------------

#ifndef PROJECT_GLOBAL_DEPENDENCIES
#define PROJECT_GLOBAL_DEPENDENCIES

//? ---------------------- Framework --------------------------
#include <Arduino.h>

//* ---------------------- Libraries --------------------------
//* I2C devices:
#include <SPI.h>
#include <Adafruit_I2CDevice.h>
//* OLED I2C display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//* WiFi
#include <WiFi.h>
#include <WiFiManager.h>
//* Watchdog
#include <esp_task_wdt.h>
//* EEPROM
#include <EEPROM.h>
#include <LittleFS.h>
//* Over the Air update
#include <ArduinoOTA.h>
//* SD Card
#include <FS.h>
#include <SD.h>
#include <SD_MMC.h>
//* Fancy LED WS2812B
#include <Adafruit_NeoPixel.h>

//* ----------------------- SHARED ----------------------------
//* Constants
#include "constants.h"
//* Interfaces
#include "interfaces.h"
//* Macros
#include "macros.h"
//* Pinout
#include "pinout.h"
//* Library Objects
#include "library_objects.h"
//* Variables
#include "variables.h"

//* ---------------------- PROJECT FIRMWARE IMPLEMENTATIONS --------------------------
//* Utilities:
//* Components:
#include "components/SDCARD/setup.h"
#include "components/LEDS/setup.h"
#include "components/DISPLAY/setup.h"
#include "components/ESP32/setup.h"
//* Services:
#include "services/wifi.h"
//* Routines:
#include "routines/update_screen.h"

#endif
