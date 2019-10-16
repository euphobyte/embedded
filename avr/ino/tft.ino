#include <SPI.h>
#include <TFT.h>

#define cs 8
#define dc 10
#define rst 9

TFT scr = TFT(cs, dc, rst);

void setup(){
  scr.begin();
  scr.background(0,255,255);
  scr.stroke(255,0,0);
  scr.text("Hello World!", 20, 20);
}

void loop(){}
