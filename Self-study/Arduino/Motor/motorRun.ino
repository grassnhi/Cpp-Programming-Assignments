#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define MAX_SPEED 255 
#define MIN_SPEED 0

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
 
void motorRightStop( ) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motorLeftStop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void motorRightHead(int speed) { 
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}


void motorRightBack(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

void motorLeftHead(int speed) { 
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, HIGH);
  analogWrite(IN3, 255 - speed);
}

void motorLeftBack(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, LOW);
  analogWrite(IN3, speed);

}
 
void loop()
{
 //motorRightHead(90);
 motorRightBack(200);

 
//motorLeftBack(100);

 motorLeftHead(250);
}