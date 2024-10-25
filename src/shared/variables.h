#if !defined(PROJECT_GLOBAL_VARIABLES)
#define PROJECT_GLOBAL_VARIABLES

//* ---------------------- GLOBAL COMPONENT VARIABLES ----------------------
//* OLED display
bool display_started = false;
//* ESP32
bool state_wifi_esp32 = false;
bool state_hall_esp32 = false;
//* TIMER
#define TIMESTEP 50
#define STEPS_TO_SEC 1000 / TIMESTEP
#define STEPS_TO_MIN 60000 / TIMESTEP
long loopTimer = 0;
long globalTimer = 0;
double loopCounter = 0;
uint32_t displayTimer = 0;         // Display refresh timer
uint32_t connectTimer = 0;         // Variable for 808 connecting status
uint32_t sensorTimer = 0;          // Delay between sensor measurements
uint32_t transmitAlertsTimer = 0;  // Delay between alerts
uint32_t transmitSensorsTimer = 0; // Delay between sensor transmits
uint32_t idleWarningTimer = 0;     // Delay between inactivity warnings
uint32_t notificationTimer = 0;    // Delay between indicator LED transitions
uint32_t GPSTimer = 0;             // Delay between GPS measurements
uint32_t wifiRetry = 0;            // Delay between wifi reconnections if dropped out
uint32_t debounceTimer = 0;        // Delay between interrupt measurements
uint32_t gnssTimeout = 0;          // Waiting time for GPS reset if missing position
bool idleWarning = false;
uint8_t lastInterruptPin = 99; // default value must be different from available pins
//* Hardware timer (for siren turn-off)
hw_timer_t *timer = NULL;
bool alarmState = false;
//* NTP date and time
bool timeZoneGSM = false;
bool timeZoneWiFi = false;
String date_NTP = "";
String time_NTP = "";
//* SDcard
String path_sdcard;

#endif // PROJECT_GLOBAL_VARIABLES
