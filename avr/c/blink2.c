/********************************************************************************
* Alternate blinking between Leds connected to Pin11 (B3) and Pin12 (B4)
* Set Bit |= bitvalue Clear Bit &=~ and Toggle Bit ^=
* | means OR, & means AND, ~ means invert and ^ means EXCLUSIVE OR
* F_CPU is needed by the delay function.
* Blink.c shows how to compile and send code to the MCU using Linux.
********************************************************************************/

#define F_CPU 16000000UL

#include<avr/io.h>
#include<util/delay.h>

int main(void){
  DDRB |= _BV(DDB3);
  DDRB |= _BV(DDB4);
  PORTB |= _BV(PORTB3);
  while(1){
    PORTB ^= _BV(PORTB3);
    PORTB ^= _BV(PORTB4);
    _delay_ms(200);
  }
}
