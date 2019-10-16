;**************************************************************************************
; Install required packages in Linux:
; sudo apt-get install avra avrdude
; Assemble code:
; $ avra blink.asm
; Send to Arduino:
; $ avrdude -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -F -U flash:w:blink.hex
; Bit 4 of PORTB is PB4 which is Pin12. Just set it to output and low which actually
; turns on the LED on the button/led module.
;**************************************************************************************
.include "m328Pdef.inc"

main:
  sbi   DDRB,  4
  cbi   PORTB, 4
loop:
  rjmp  loop
