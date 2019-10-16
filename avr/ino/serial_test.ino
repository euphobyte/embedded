// FOR EDUCATIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION
// Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.
// Send, every 10 seconds, ascii code for digits 0 through 9 at 9600 baud. 
// Reset at 9, back to 0, flash internal LED.

int count = 48;

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(){
  count++;
  if(count == 58){
    count = 48;
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
  }
  Serial.write(count);
  delay(10000);
}
