const int trig = 8;
const int echo = 9;

void setup(){
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH); 
  delayMicroseconds(5);

  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = duration/2/29.412; 

  Serial.println(distance); 
}