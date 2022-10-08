

#include <Arduino.h>

//TODO this should NOT be hardcoded here
const char* ssid     = "Askov";
const char* password = ";BK46987";
#include "MyWifi.h"


const char * GET = "GET";
const char * POST = "POST";


endpoint_t urls[] = {
  //side1
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/1",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  },

    //side2
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/2",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  },

    //side3
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/3",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  },

    //side4
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/4",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  },

    //side5
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/5",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  },

    //side6
  { GET,
    "http://192.168.2.136:8080/diceServer/v1/side/6",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    "BASIC" //authMethod
  }

};

#include "MPU.h"


/**
   Thoughts:

   1. Get reading of side up
   2. Verify this 3 secs later
   3. Check if this is a new side up
   4. If new side, issue event


   TODOs

 * * event is HTTP call
 * * deep sleep and interrupts
 * *
*/

void setup(void) {
  
  Serial.begin(9600);

  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }


  Serial.println("Adafruit MPU6050 test!");


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
  Serial.print(sideUp);
  Serial.println(" is now up");
  Serial.println(getRequest(urls[sideUp-1]));

}
