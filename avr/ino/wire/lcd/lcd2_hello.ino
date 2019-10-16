// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Example of custom minimalistic library to output debug info to an 16 x 2 LCD screen via a Wire interface.

#include <Wire.h>
#include "Lcd2.h"

Lcd2 lcd;

void setup(){
  lcd.begin();
  lcd.setpos(BOT_LFT);            // Position cursor at the bottom left corner of the display
  lcd.write("Hello World!");
  lcd.setpos(TOP_RGT - 4);        // Position cursor at the top right corner (-4) of the display
  lcd.writeHex(0x0ABC);           // 4 position hex number to display
}

void loop(){}
