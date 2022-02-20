#define MAX_SPEED 255
#define MIN_SPEED 75

/*
const int trig = 2;
const int echo_head = 3;
const int echo_left = 4;
const int echo_right = 5;
*/

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;

const int enc_left = 2;
const int enc_right = 3;

int counter_left = 0;
int counter_right = 0;
unsigned long now;

void countpulse_left() {
  counter_left++;
}

void countpulse_right() {
  counter_right++;
}

void setup(){
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    /*
    pinMode(trig,OUTPUT);
    pinMode(echo_head,INPUT);
    pinMode(echo_left,INPUT);
    pinMode(echo_right,INPUT);
    */

    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);

    pinMode(enc_left, INPUT);
    pinMode(enc_right, INPUT);

    attachInterrupt(enc_left - 2, countpulse_left, RISING);
    attachInterrupt(enc_right - 2, countpulse_right, RISING);
}

/*
float distance(int echo) {
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(5);
  digitalWrite(trig,0);
  unsigned long duration = pulseIn(echo,HIGH);
  float cal = duration/2/29.412;
  return cal;
}
*/

void motor_left_run(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, x);
  analogWrite(IN2, abs(MAX_SPEED*x - speed));
}

void motor_right_run(int speed, bool x) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, x);
  analogWrite(IN3, abs(MAX_SPEED*x - speed));
}

void motor_left_stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor_right_stop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop()
{
  /*
  float head = distance(echo_head);
  float left = distance(echo_left);
  float right = distance(echo_right);
  */

  /*
  Serial.print("head = ");
  Serial.println(head);
  Serial.print("left = ");
  Serial.println(left);
  Serial.print("right = ");
  Serial.println(right);
  Serial.println();
  */
  
  /*
  if (head > 10) {
    motor_left_run(MAX_SPEED,1);
    motor_right_run(MAX_SPEED,1);
  } else {
      if (left <= 10 && right <= 10) {
        motor_left_stop();
        motor_right_stop();
      } else if ((left <= 10 && right > 10) || (left > 10 && right > 10)) {
        motor_left_stop();
        motor_right_run(MAX_SPEED,1);
      } else if (left > 10 && right <= 10) {
        motor_left_run(MAX_SPEED,1);
        motor_right_stop();
      }
  }
  */
  
  motor_left_run(255, 1);
  //motor_right_run(255, 1);
  if (millis() % 5000 == 0 && now != millis()) {
    Serial.print(millis());
    Serial.print(' ');
    Serial.println(counter_left);
    now = millis();
    counter_left = 0;
  }
  
  /*if (!digitalRead(encoder)) {
    countpulse();
  }*/
}