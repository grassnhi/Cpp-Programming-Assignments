const int nutPin = 4;

const int ledPin 8;

unsigned char onoff = 0;

void setup() {

pinMode(ledPin, OUTPUT);

pinMode (nut Pin, INPUT_PULLUP);

bonlinhken

}

void loop() {

if (digitalRead (nutPin) == LOW){

delay (20) ;

if (digitalRead (nut Pin) == LOW){

if (onoff == 0) {

onoff = 1;

digitalWrite(ledPin, HIGH);

else {

onoff = 0;

digitalWrite(ledPin, LOW);