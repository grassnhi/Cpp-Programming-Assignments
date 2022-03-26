// 0 -> 2
// 1 -> 3

int counter = 0;
void count(){
  counter++;
  Serial.println(counter);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0, count, RISING);
  
}

void loop() {
  
}