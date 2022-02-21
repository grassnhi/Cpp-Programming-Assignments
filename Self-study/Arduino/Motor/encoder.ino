const int enc = 2;
int counter = 0;

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0, counterpulse, HIGH);
}

void loop(){
  Serial.println(counter);
}