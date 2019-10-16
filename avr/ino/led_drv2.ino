// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Minimalistic program to turn array of 64 LEDs on and off.

#define CLK   13
#define MOSI  11
#define CS    10


define control_reg 0x0A;

void cmd(uint8_t, uint8_t);
boolean stat = false;

void setup(){
  pinMode(CS, HIGH);
  pinMode(CLK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(CS, OUTPUT);
}

void loop(){
  sendReg(control_reg, stat);
  stat = ~stat;
  delay(500);
}

void sendReg(uint8_t adr, uint8_t val){
  digitalWrite(CS, LOW);
  shiftOut(MOSI, CLK, MSBFIRST, adr);
  shiftOut(MOSI, CLK, MSBFIRST, val);
  digitalWrite(CS, HIGH);
}
