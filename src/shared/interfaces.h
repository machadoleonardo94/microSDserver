#if !defined(PROJECT_GLOBAL_INTERFACES)
#define PROJECT_GLOBAL_INTERFACES

//* ---------------------- 1Wire ----------------------
//* DHT22 - Temperature and Humidity sensor.

//* ---------------------- UART ----------------------
//* Serial port used for USB connection to the PC.
#define serialMon Serial
//* Serial port used by the GNSS module.
#define serialGNSS Serial2
//* Serial port used by the celular module.
#define serialCelular Serial1

//* ---------------------- 4x DIGITAL PIN ----------------------
// all channels used for bat readings.

#endif // PROJECT_GLOBAL_INTERFACES
