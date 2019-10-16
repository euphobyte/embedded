/*  FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
    Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
    General purpose sensor code, in this example temperature
    The calculation from raw bytes to actual value has been kept very minimal. Usually this is a more complex process.
    The values are updated every second. Again very minimalistic code.
    In a real environment a sample array should be created, from which the optimal sensor value is determined.
*/  

#include <Wire.h>
#include "lcd2.h"
#define GY_SENSOR   0x01;
#define INIT_REG    0x01;
#define INIT_VAL    0x00;
#define TEMP_REG    0x02;

const char* label = "Temp:\0";                                          // LCD label
const char hex[] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};   // ASCII values of hex characters

lcd2 lcd = new lcd2();

void init_sensor(){                             // Initialize sensor
  Wire.beginTransmission(GY_SENSOR);
  Wire.write(INIT_REG);
  Wire.write(INIT_VAL);
  Wire.endTransmission();  
}

void write_int_lcd(int val){                    // Display raw hex value
  lcd.setpos(BOTTOM_RIGHT - 4);          
  val = val & 0xFFFF;
  lcd.write(hex[((val >> 12) & 0xF)]);
  lcd.write(hex[((val >>  8) & 0xF)]);
  lcd.write(hex[((val >>  4) & 0xF)]);
  lcd.write(hex[(val & 0xF)]);
}

void write_label_lcd(char* lbl){
  lcd.setpos(TOP_LEFT);
  while(*lbl){
    lcd.write(char(*lbl++));
  }
}

void setup(){
  Wire.begin();
  lcd.init();
  write_label_lcd(label);
  init_sensor();
}

void loop(){
  Wire.beginTransmission(GY_SENSOR);
  Wire.write(TEMP_REG);                         // Read 2 temperature bytes from the sensor
  Wire.endTransmission();  
  Wire.requestFrom(GY_SENSOR, 2);
  while(Wire.available() < 2);
  int tmp = Wire.read() << 8 | Wire.read();     // Combine 2 bytes read into single integer tmp
  write_int_lcd(tmp);
  float tf = tmp * 0.1;                         // Convert bytes to actual float value
  lcd.setpos(BOTTOM_LEFT + 2);                
  if(tf < 100.0){                               // Limit max value handled
    int tm = tf * 100;
    lcd.write(hex[(tm / 1000)]);
    lcd.write(hex[((tm % 1000) / 100)]);
    lcd.write(0x2E);                            // decimal character
    lcd.write(hex[((tm % 100) / 10)]);
    lcd.write(hex[(tm % 10)]);
  }
  delay(1000);
}
