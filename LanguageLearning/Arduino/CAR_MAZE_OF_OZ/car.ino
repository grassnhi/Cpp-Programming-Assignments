#include "carMazeOfOz.h"

#define STEP_TIME_64 4e-6
#define TIMER1_STEP_CYCLE 65536

const byte trig = 8;

carMazeOfOz car;

volatile float speedValueLeft, speedValueRight;
volatile float speedValueLeft_SAMPLE[11], speedValueRight_SAMPLE[11];
volatile unsigned long timerPoint = 0, currentEncoderLeft = 0, currentEncoderRight = 0;

// Your variables is in the area below
//--------------------------------------------------//





//--------------------------------------------------//

void setup() {
  Serial.begin(9600);
  car.setPin();
  car.setInterrupt();
  attachInterrupt(0, ENC_LEFT_ISR, RISING);
  attachInterrupt(1, ENC_RIGHT_ISR, RISING);
}

void ENC_LEFT_ISR() {
  static byte i = 0;
  speedValueLeft_SAMPLE[10] -= speedValueLeft_SAMPLE[i];
  speedValueLeft_SAMPLE[i] = (TCNT1 - currentEncoderLeft + TIMER1_STEP_CYCLE) % TIMER1_STEP_CYCLE;
  speedValueLeft_SAMPLE[10] += speedValueLeft_SAMPLE[i];
  speedValueLeft = 255254.4 / (speedValueLeft_SAMPLE[10] / 10);
  car.setSpeedLeft(speedValueLeft);
  i = (i + 1) % 10;
  currentEncoderLeft = TCNT1;
}

void ENC_RIGHT_ISR() {
  static byte i = 0;
  speedValueRight_SAMPLE[10] -= speedValueRight_SAMPLE[i];
  speedValueRight_SAMPLE[i] = (TCNT1 - currentEncoderRight + TIMER1_STEP_CYCLE) % TIMER1_STEP_CYCLE;
  speedValueRight_SAMPLE[10] += speedValueRight_SAMPLE[i];
  speedValueRight = 255254.4 / (speedValueRight_SAMPLE[10] / 10);
  car.setSpeedRight(speedValueRight);
  i = (i + 1) % 10;
  currentEncoderRight = TCNT1;
}

// Your functions is in the area below
//--------------------------------------------------//





//--------------------------------------------------//

void loop() {
  digitalWrite(trig, LOW);
  car.setSpeedLeft(speedValueLeft);
  car.setSpeedRight(speedValueRight);
  car.configureSpeed(speedValueLeft, speedValueRight);
  
  // Your code is in the area below
  //--------------------------------------------------//
  //-----Example code-----//
  if (car.getDistanceHead() < 50) {
    if (car.getDistanceHead() < 20) {
      car.setMotorLeft(255, 0);
      car.setMotorRight(255, 1);
    } else {
      car.setMotorLeft(150, 1);
      car.setMotorRight(150, 1);
    }
  } else {
    car.setMotorLeft(200, 1);
    car.setMotorRight(200, 1);
  }
  
  // Use Serial Monitor or Plotter in Arduino IDE to display the values on the screen
  Serial.print(car.getDistanceHead());
  Serial.print(" ");
  Serial.print(car.getSpeedLeft());
  Serial.print(" ");
  Serial.println(car.getSpeedRight());
  //-----Example code-----//
  
  
  
  
  
  //--------------------------------------------------//
}