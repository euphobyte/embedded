// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Circuit to test PC serial communication
// variables prv (previous) btn (button) sw (switch character to turn LED on or off)
// Pin 9 is connected to a green LED through a 220 Ohm resistor.
// Pin 8 is connected to a button switch module with pull down resistor of 10K Ohm (103 smd).

int prv, btn, sw;

void setup(){
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  prv = LOW;
}

void loop(){
  
  if (Serial.available() > 0){
    sw = Serial.read();
    if(sw == 72)                      // 72 = 'H' (HIGH)
      digitalWrite(9, HIGH);
    if(sw == 76)                      // 76 = 'L' (LOW)
      digitalWrite(9, LOW);
  }
  
  btn = digitalRead(8);
  if(btn != prv){
    if(btn == HIGH)
      Serial.println("Down!");
    else
      Serial.println("Up!");
    prv = btn;
    delay(50);
  }  
}
