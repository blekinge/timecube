#include <Arduino.h>

#include "BatteryController.h"
#include "MPU.h"
#include "WifiCreds.h"
#include "MyWifi.h"
#include "Http.h"

void setup(void) {

  Serial.begin(9600);

  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  setupBattery();

  Serial.println("Battery setup; starting MPU");

  setupMPU();

  Serial.println("MPU has been setup, starting wifi");

  setupWifi(ssid, password);

  Serial.println("Wifi setup");
  delay(100);
  
}

byte sideup = 0;


void loop() {

  /* Get new sensor events with the readings */
  byte currentSideUp = getSideUp(sideup);

  if (currentSideUp > 0 && currentSideUp != sideup) {
    sideChanged(currentSideUp);
    sideup = currentSideUp; 
  }

  delay(500);
}

void sideChanged(byte sideUp) {
  String httpResult = httpGetRequest(sideUp);
  Serial.print(sideUp);
  Serial.println(" is now up");
  Serial.println(httpResult);

}
