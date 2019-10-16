// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Simple blink example to demostrate the use of the example library "Blink"

#include <Blink.h>

Blink blink(8);

void setup(){
  blink.begin();
  blink.switch_on(true);
}

void loop(){
  blink.toggle();
  delay(500);
}
