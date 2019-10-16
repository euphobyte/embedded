// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Implementation file of the example class "Blink" 

#include "Blink.h"

Blink::Blink(uint8_t pin){
  led_pin = pin;
}

void Blink::begin(void){
  digitalPort(led_pin, OUTPUT);
}

void Blink:switch_on(boolean val){
  status = val;
  digitalWrite(led_pin, status);
}

void Blink:toggle(void){
  status = ~status;                         // Bitwise invert current status
  digitalWrite(led_pin, status);  
}
