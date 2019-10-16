;************************************************************************
; Blink alternating led connected to Pin 11 and Pin 12. 
;************************************************************************

.device ATmega328P
.equ  DDRB  = 0x04;
.equ  PORTB = 0x05;

  jmp   main

delay_ms:             ; execute the loop 50 * 255 * 255 about half a second 
  ldi   r17, 50
  ldi   r18, 0xff
  ldi   r19, 0xff
delay1:
  dec   r19
  brne  delay1
  dec   r18
  brne  delay1
  dec   r17
  brne  delay1
  ret

main:
  sbi   DDRB, 3     ; Pin 11 (PB3) Output
  sbi   DDRB, 4     ; Pin 12 (PB4) Output
loop:
  cbi   PORTB, 3
  sbi   PORTB, 4
  rcall delay_ms
  sbi   PORTB, 3
  cbi   PORTB, 4  
  rcall delay_ms
  rjmp  loop
