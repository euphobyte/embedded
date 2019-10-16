# Shift Register

|Pin|Function||Function|Pin|
|-:|-|-|-:|:-|
|1|Q1||VCC|16|
|2|Q2||Q0|15|
|3|Q3||DAT|14|
|4|Q4||OE|13|
|5|Q5||LAT|12|
|6|Q6||CLK|11|
|7|Q7||RST|10|
|8|GND||Q7S|9|


- OE (output enable) is active low, so it needs to be tied to ground to enable the output.
- RST (reset) is also active low, so not to reset means it needs to be tied top +5V.
- Connect 5V power source to pins 1 (+5V) and 8 (Ground).
- Bits are clocked in by clocking in (CLK) input data bits (DAT).  There is an internal register which can hold 8 bits.
- When the LAT (latch) pin is pulled high, the output pins (Q0 - Q7) are set in accordance to the content of the internal register.
- When more than 8 bits are clocked in, they can be daisy changed to the next shift register via Q7S.
