// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Class definition header file for example class "Blink"
// Tiny example of a custom library
// This is a library for turning on or off of a single LED.

#include <Arduino.h>

class Example{
  private:
    uint8_t led_pin = -1; 
    boolean status = false;
  public:
    void Blink(uint8_t);
    void begin(void);
    void switch_on(boolean);
    void toggle(void);
};
