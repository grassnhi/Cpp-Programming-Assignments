#include <avr/interrupt.h>

#define MAX_SPEED 255
#define MIN_SPEED 0
#define C 0.2042
#define sensor A0

const int trig = 10;
const int echoHead = 11;
/*const int echoLeft = 4;
const int echoRight = 5;*/
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
const int encoderLeft = 2;
const int encoderRight = 3;

volatile int counterLeft = 0, counterRight = 0;
int speedLeft = 255, speedRight = 100;
volatile double pulsePerSecondLeft, pulsePerSecondRight;
double setPointLeft = 255, setPointRight = 100, error;
double Kp = 0.2, Ki = 0.03, Kd = 0.01;
volatile int nowLeft = 0, nowRight = 0;
bool delayLeft = false, delayRight = false;
int timeDelay = 5000;
unsigned long timeCurrentLeft = 0, timeCurrentRight = 0;
String speedValue;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echoHead, INPUT);
  /*pinMode(echoLeft,INPUT);
  pinMode(echoRight,INPUT);*/
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(encoderLeft, INPUT);
  pinMode(encoderRight, INPUT);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK1 = 0;

  TCCR1B |= (1 << CS11) | (1 << CS10);
  TCNT1 = 40536;
  TIMSK1 = (1 << TOIE1);
  sei();

  attachInterrupt(encoderLeft - 2, countPulseLeft, RISING);
  attachInterrupt(encoderRight - 2, countPulseRight, RISING);
}

ISR (TIMER1_OVF_vect) {
  TCNT1 = 40536;
}

void countPulseLeft() {
  counterLeft++;
  pulsePerSecondLeft = 1 / ((TCNT1 - nowLeft) * 0.000004);
  nowLeft = TCNT1;
}

void countPulseRight() {
  counterRight++;
  pulsePerSecondRight = 1 / ((TCNT1 - nowRight) * 0.000004);
  nowRight = TCNT1;
}

double PID_left(double input) {
  double error = setPointLeft - input;
  unsigned long currentTime = millis();
  static double I = 0;
  static unsigned long previousTime = -1;
  static double lastError;
  double P = Kp * error;
  I += Ki * error * (currentTime - previousTime);
  double D = Kd * (error - lastError) / double(currentTime - previousTime);
  lastError = error;
  previousTime = currentTime;
  return P + I + D;
}

double PID_right(double input) {
  double error = setPointRight - input;
  unsigned long currentTime = millis();
  static double  I = 0;
  static unsigned long previousTime = -1;
  static double lastError;
  double P = Kp * error;
  I += Ki * error * (currentTime - previousTime);
  double D = Kd * (error - lastError) / double(currentTime - previousTime);
  lastError = error;
  previousTime = currentTime;
  return P + I + D;
}

float distanceCentimetre(int echo) {
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(5);
  digitalWrite(trig,0);
  return pulseIn(echo, HIGH)/2/29.412;
}

void motorLeftRun(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1,x);
  analogWrite(IN2,abs(MAX_SPEED*x - speed));
}

void motorRightRun(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4,x);
  analogWrite(IN3,abs(MAX_SPEED*x - speed));
}

void motorLeftStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motorRightStop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

/*void turnLeft() {
  if (millis() - timeCurrentLeft >= timeDelay) {
    timeCurrentLeft = millis();
    if (digitalRead(ledLeft) && distance(echoHead) > 20) {
      digitalWrite(ledLeft, LOW);
      delayLeft = false;
    } else {
      digitalWrite(ledLeft, HIGH);
    }
  }
}

void turnRight() {
  if (millis() - timeCurrentRight >= timeDelay) {
    timeCurrentRight = millis();
    if (digitalRead(ledRight) && distance(echoHead) > 20) {
      digitalWrite(ledRight, LOW);
      delayRight = false;
    } else {
      digitalWrite(ledRight, HIGH);
    }
  } 
}*/

void setSpeedLeft(int speedInput) {
  if(pulsePerSecondLeft < speedInput - 5 && setPointLeft < 254) {
    setPointLeft += 5;
  }
  if (pulsePerSecondLeft > speedInput + 5 && setPointLeft > 1) {
    setPointLeft -= 5;
  }
}

void setSpeedRight(int speedInput) {
  if(pulsePerSecondRight < speedInput - 5 && setPointRight < 254) {
    setPointRight += 5;
  }
  if (pulsePerSecondRight > speedInput + 5 && setPointRight > 1) {
    setPointRight -= 5;
  }
}

void loop() {
  if (Serial.available() > 0) {
    speedValue = Serial.readStringUntil('\n');
  }
  //Serial.print(speedValue);
  //Serial.print(" ");
  //Serial.print(" ");
  
  /*speedLeft = PID_left(speedLeft);
  speedRight = PID_right(speedRight);
  Serial.print(setPointLeft);
  Serial.print(" ");
  Serial.print(pulsePerSecondLeft);
  Serial.print(" ");*/
  
  /*float distanceHead = distanceCentimetre(echoHead);
  Serial.println(distanceHead);
  if (distanceHead > 100) {
    setSpeedLeft(100);
    setSpeedRight(100);
    motorLeftRun(setPointLeft, 0);
    motorRightRun(setPointRight, 0);
  } else {
    setSpeedLeft(70);
    setSpeedRight(90);
    //motorLeftStop();
    //motorRightStop();
    motorLeftRun(setPointLeft, 0);
    motorRightRun(setPointLeft, 0);
  }*/
  motorRightRun(255, 1);
  Serial.println(pulsePerSecondLeft);
}