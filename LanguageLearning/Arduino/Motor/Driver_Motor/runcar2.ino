#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define MAX_SPEED 255 
#define MIN_SPEED 0

const int trig = 8;
const int echo =9;

void setup()
{
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

float sensor(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH); 
  delayMicroseconds(5);

  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  return duration/2/29.412; 
}

void motorRightStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motorLeftStop(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rightHead(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH); //+ =>hướng
  analogWrite(IN2, 255 - speed);//- => tốc độ
}

void rightBack(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

void leftHead(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, HIGH);
  analogWrite(IN3, 255 - speed);
}

void leftBack(int speed){
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, LOW);
  analogWrite(IN3, speed);
}

void loop()
{
  float distance = sensor();
  Serial.println(distance);
//
//  rightHead(MAX_SPEED);
//  leftHead(MAX_SPEED);

  if(distance > 50){
      rightHead(MAX_SPEED);
      leftHead(MAX_SPEED);
  }else{
      rightHead(MAX_SPEED);
      leftHead(MIN_SPEED);
      delay(10000);
      if(distance < 10){
        motorRightStop();
        motorLeftStop();
      }
  }
  // if(distance < 10){  
  //       motorRightStop();
  //       motorLeftStop();
  // }
  // else if(distance > 30){
  //     rightHead(MAX_SPEED);
  //     leftHead(MAX_SPEED);
  //   }
  //   else{
  //     rightHead(MAX_SPEED);
  //     leftBack(150);
  //     delay(500);
  // }
}