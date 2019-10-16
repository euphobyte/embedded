// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.

byte num[] = {0x3F, 0x30, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int clk = 13;
int dat = 11;

void setup(){
  pinMode(clk, OUTPUT);
  pinMode(dat, OUTPUT);
  startb();
  // 10.. ....
  writeValue(0x00);
  stopb();
  startb();
  // 11.. ....
  writeValue(0x00);
  writeValue(num[1]);
  writeValue(num[2]);
  writeValue(num[3]);
  writeValue(num[4]);
  stopb();
}

void loop(){
}

void startb(){
  digitalWrite(clk, HIGH);
  digitalWrite(dat, HIGH);
  digitalWrite(dat, LOW);
  digitalWrite(clk, LOW);
}

void stopb(){
  digitalWrite(clk, LOW);
  digitalWrite(dat, LOW);
  digitalWrite(clk, HIGH);
  digitalWrite(dat, HIGH);
}

void writeValue(byte val){
  for(int i=0; i < 8; i++){
    digitalWrite(clk, LOW);
    digitalWrite(dat, val & (1 << i));
    digitalWrite(clk, HIGH);
  }
  digitalWrite(clk, LOW);
  digitalWrite(clk, HIGH);
}
