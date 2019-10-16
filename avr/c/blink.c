/*************************************************************************************
* In order to compile this program in Linux install the following packages:
* $ sudo apt-get install avr-libc avrdude gcc-avr
* To create object file:
* $ avr-gcc -Os -mmcu=atmega328p -o blink.bin blink.c
* To create hex file for avrdude:
* $ avr-objcopy -j .text -j .data -O ihex blink.bin blink.hex
* Then burn the hex file via USB to the Arduino:
* $ avrdude -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -F -U flash:w:blink.hex
*************************************************************************************/

#define F_CPU 16000000UL

#include<avr/io.h>
#include<util/delay.h>

int main(void){
  DDRB |= (1 << DDB3);
  while(1){
    PORTB |= (1 << PORTB3);
    _delay_ms(500);
    PORTB &= ~(1 << PORTB3);
    _delay_ms(500);
  }
}
