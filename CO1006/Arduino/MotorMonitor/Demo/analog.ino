// AnalogWrite: 3, 5, 6, 9, 10, and 11.

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop()
{
  for(int i = 0; i < 255; i += 5){
  	analogWrite(3, i);
    delay(100);
  }
}