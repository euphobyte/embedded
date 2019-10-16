// FOR EDUCATIONAL PURPOSES ONLY
// Simple example of a keyboard interface, created in the ide.
// Only reading scan codes.
// VCC=brown GND=gray CLK=yellow DAT=red

int dat = 4;
int clk = 3;
int keyb = 0;
String scan = "";
int pos = 0;

void setup(){
  pinMode(dat, INPUT_PULLUP);
  pinMode(clk, INPUT_PULLUP);
  attachInterrupt(1, isr, FALLING);
  Serial.begin(9600);
}

void loop(){}

void isr(){
  int val = digitalRead(dat);
  scan += (val == 1 ? "1" : "0");
  if(((pos > 0) && (pos < 9)) && (val == 1))
      keyb |= _BV(pos - 1);
  pos++;
  if(pos > 10){
    Serial.print(keyb, HEX);
    Serial.print(" / ");
    Serial.println(scan);
    scan = "";
    pos = 0;
    keyb = 0;
  }
}
