;************************************************************************
; Even more bare than the previous program, not even an include file.
; Pin 12 is no longer on, this program activates Pin 11
;************************************************************************

.device ATmega328P
.equ DDRB  = 0x04;
.equ PORTB = 0x05;

  jmp   main
main:
  sbi   DDRB,  3
  cbi   PORTB, 3
loop:
  rjmp  loop
