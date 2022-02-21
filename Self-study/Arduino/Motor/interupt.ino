int led_W = 8;

void tat_led(){
  digitalWrite(led_W, !digitalRead(led_W));
}

void setup() {
  pinMode(led_W, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, tat_led, LOW);
}

void loop() {
  digitalWrite(led_W, HIGH); 
}