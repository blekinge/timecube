
#if !defined( ESP32 )
#error This code is intended to run on the ESP32 platform! Please check your Tools->Board setting.
#endif

// These define's must be placed at the beginning before #include "ESP32_New_TimerInterrupt.h"
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
#define _TIMERINTERRUPT_LOGLEVEL_     4
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <ESP32TimerInterrupt.h>

#define BATTERY_PIN 33

#define TIMER0_BATTERY_ON_MS    500L
#define TIMER0_BATTERY_OFF_MS  1000L

// Init ESP32 timer 0
ESP32Timer ITimer0(0);
ESP32Timer ITimer1(1);


// With core v2.0.0+, you can't use Serial.print/println in ISR or crash.
// and you can't use float calculation inside ISR
// Only OK in core v1.0.6-
bool IRAM_ATTR TimerHandler0(void * timerNo) {
  
  //Sets battery low to turn it on
  digitalWrite(BATTERY_PIN, LOW);

  return true;
}

// With core v2.0.0+, you can't use Serial.print/println in ISR or crash.
// and you can't use float calculation inside ISR
// Only OK in core v1.0.6-
bool IRAM_ATTR TimerHandler1(void * timerNo) {
  
  //Sets battery low to turn it off
  digitalWrite(BATTERY_PIN, HIGH);

  return true;
}


void setupBattery() {

  pinMode(BATTERY_PIN,  OUTPUT);


  // Using ESP32  => 80 / 160 / 240MHz CPU clock ,
  // For 64-bit timer counter
  // For 16-bit timer prescaler up to 1024

  // Interval in microsecs
  if (ITimer0.attachInterruptInterval(TIMER0_BATTERY_OFF_MS * 1000, TimerHandler0))  {
    Serial.print(F("Starting  ITimer0 OK, millis() = ")); Serial.println(millis());
  } else {
    Serial.println(F("Can't set ITimer0. Select another freq. or timer"));
  }
  delay(TIMER0_BATTERY_ON_MS);
  
  // Interval in microsecs
  if (ITimer1.attachInterruptInterval(TIMER0_BATTERY_OFF_MS * 1000, TimerHandler1))  {
    Serial.print(F("Starting  ITimer1 OK, millis() = ")); Serial.println(millis());
  } else {
    Serial.println(F("Can't set ITimer1. Select another freq. or timer"));
  }
}
