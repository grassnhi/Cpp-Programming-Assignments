const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;

void setup(){
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void motor_left_head(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);

  digitalWrite(IN1, HIGH);
  analogWrite(IN2, MAX_SPEED - speed);
}

void motor_left_back(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);

  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

/*
void motor_left_run(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, x);
  analogWrite(IN2, abs(MAX_SPEED*x - speed));
}
*/

void motor_right_head(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);

  digitalWrite(IN4, HIGH);
  analogWrite(IN3, MAX_SPEED - speed);
}

void motor_right_back(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);

  digitalWrite(IN4, LOW);
  analogWrite(IN3, speed);
}

/*
void motor_right_run(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, x);
  analogWrite(IN3, abs(MAX_SPEED*x - speed));
}

*/
void motor_left_stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor_right_stop(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop(){
    motor_left_head(255, 5);
    motor_left_back(200, 5);
    motor_right_head(150, 5);
    motor_right_back(100, 5);
}
