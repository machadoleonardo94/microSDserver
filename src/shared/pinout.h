//? ------------------------------------------------------------------------------------------
//*! This file contains all the hardware pinout definitions for the project.
//? ------------------------------------------------------------------------------------------

#ifndef PROJECT_GLOBAL_PINOUT
#define PROJECT_GLOBAL_PINOUT

#include "shared/dependencies.h"

//* ---------------------- Saveboat V2 Project Pinout ----------------------
//* ANALOG OUT:
//* ANALOG IN:
//
//* DIGITAL IN:
#define digital_in_dht22 4
#define digital_input_sd_on 13
#define digital_in_fire_ir 39
#define MCP_input_flood 0       // GPA0
#define MCP_input_cellar_pump 1 // GPA1
#define MCP_input_mainSwitch 2  // GPA2
#define MCP_input_overTemp 3    // GPA3
#define MCP_input_underVolt 4   // GPA4
#define MCP_GPIO_A5 5           // GPA5
#define MCP_GPIO_A6 6           // GPA6
#define MCP_GPIO_A7 7           // GPA7

//* DIGITAL OUT:
#define LED_output 12
#define MCP_output_enable_buzzer 8     // GPB0
#define MCP_output_enable_dht22 9      // GPB1
#define MCP_output_enable_openDrain 10 // GPB2
#define MCP_output_sleep_SIM7670 11    // GPB3
#define MCP_output_power_SIM7670 12    // GPB4
#define MCP_GPIO_B5 13                 // GPB5
#define MCP_GPIO_B6 14                 // GPB6
#define MCP_GPIO_B7 15                 // GPB7
#define digital_out_mux_addr0 14
#define digital_out_mux_addr1 27
#define digital_out_mux_addr2 26
#define digital_out_mux_addr3 25
//* SPI
#define CS_pin 5
#define SPI_CLK 18
#define MISO_pin 19
#define MOSI_pin 23
//* INTERRUPTS:
#define interruptA 34
#define interruptB 35
#define interruptA_GPIO GPIO_NUM_34
#define interruptB_GPIO GPIO_NUM_35

//* HARDWARE COMMUNICATION PORTS, INDEPENTENT OF VERSION
//* SERIAL PORTS:
#define tx_celular 16
#define rx_celular 17
//! Absolutely DO NOT use pins 6-10, as they are used in the flash memory access
// #define tx_gnss 10
// #define rx_gnss 9
//* CAN PORTS:
// Check libdeps/esp32dev/NMEA2000_esp32/NMEA2000_esp32.h for pin references
// #define ESP32_CAN_TX_PIN GPIO_NUN_32
// #define ESP32_CAN_RX_PIN GPIO_NUN_33
//* I2C PINS:
#define i2c_sda 21
#define i2c_scl 22

#endif // PROJECT_GLOBAL_PINOUT
