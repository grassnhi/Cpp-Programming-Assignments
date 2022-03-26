#include <avr/interrupt.h>

#define SOUND_SPEED 34320
#define MAX_SPEED 255
#define MIN_SPEED 0
#define TIME_PER_BIT 4e-6

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 7;
const int IN4 = 6;
const int trig = 8;
const int echo = 2;
const int encoder = 2;

volatile double distanceCentimeter, pulsePerSecond;
volatile unsigned long timerPoint = 0, now = 0;
volatile int fixSensor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  cli();  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK1 = 0;

  TCCR1B |= (1 << CS11) | (1 << CS10);
  TCNT1 = 40536;
  TIMSK1 = (1 << TOIE1);
  sei();

  //attachInterrupt(echo - 2, distance, HIGH);
  attachInterrupt(encoder - 2, countPulse, RISING);
}

ISR (TIMER1_OVF_vect) {
  TCNT1 = 40536;
  /*fixSensor++;
  if (fixSensor % 10 == 0) {
    digitalWrite(trig, HIGH);
    fixSensor = 0;
  }*/
}

void countPulse() {
  //counter++;
  pulsePerSecond = 1 / ((65536 + TCNT1 - now) % 65536 * TIME_PER_BIT);
  now = TCNT1;
}

void motorLeft_Run(int speed, bool x) {
  speed = constrain(speed, 0, 255);
  digitalWrite(IN1, x);
  analogWrite(IN2, abs(255*x - speed));
}

void motorRight_Run(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN3, x);
  analogWrite(IN4, abs(MAX_SPEED*x - speed));
}

void distance() {
  digitalWrite(trig, LOW);
  distanceCentimeter = ((TCNT1 - timerPoint) * TIME_PER_BIT * SOUND_SPEED) / 2;
  timerPoint = TCNT1;
  digitalWrite(trig, HIGH);
  // Serial.println(timerPoint);
}

void loop() {
  // Serial.println(distanceCentimeter);
  /*if (distanceCentimeter > 50) {
    motorLeft_Run(255, 1);
    motorRight_Run(255, 1);
  } else {
    motorLeft_Run(255, 0);
    motorRight_Run(100, 0);
  }*/
  //motorLeft_Run(255, 1);
  motorRight_Run(255, 1);
  Serial.print(75);
  Serial.print(" ");
  Serial.println(pulsePerSecond);
}