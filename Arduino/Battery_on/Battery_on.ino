#include <Arduino.h>


int led = 12;

void setup() {               
  pinMode(led, OUTPUT);    
}

void loop() {
  
  digitalWrite(led, LOW);  
  delay(500);           
  
  digitalWrite(led, HIGH);  
  delay(15000);            
}
