// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Simple example to scan the devices connected to an MCU via the serial wire interface.
// Connect a serial wire device.
// Upload this code to the MCU and start monitoring the Serial output.
// Example output: Device found at: 3A

#include <Wire.h>

int res = -1;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  for(int i=0; i < 127; i++){
    Wire.beginTransmission(i);
    res = Wire.endTransmission();
    if(res == 0){
      Serial.print("Device found at: ");
      Serial.println(i,HEX);
    }
    delay(5);
  }
}

void loop(){}
