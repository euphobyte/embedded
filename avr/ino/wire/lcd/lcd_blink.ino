// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Connect serial wire lcd charatar module.
// Blink backlight by toggeling bit 4 of the serial wire port.  A serial wire address of 0x3A is assumed for the module.

#include <Wire.h>

void setup(){
  Wire.begin();
}

void loop(){
  Wire.beginTransmission(0x3A);
  Wire.write(0x08);
  Wire.endTransmission();
  delay(500);
  Wire.beginTransmission(0x3A);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(500);
}
