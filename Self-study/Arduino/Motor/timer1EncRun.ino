#include <avr/interrupt.h> // thư viện Interrupt của AVR.

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define MAX_SPEED 255 
#define MIN_SPEED 0

float velo;
float timer;

volatile int temp = 0; 

int save = TCNT1;

void velocity(){
    if( temp == 0){
      timer = (TCNT1 - save)*0.000004;
      velo = 1 / timer;
      save = TCNT1;
    }
    else{
      if( TCNT1 > save){
        timer = (TCNT1 - save)*0.000004 + 25000*(temp)*0.000004;
        velo = 1/ timer;
        save = TCNT1;
        temp = 0;
      }else{
        timer = (65536 - save + TCNT1 - 40536)*0.000004 + 25000*(temp-1)*0.000004;
        velo = 1/ timer;
        save = TCNT1;
        temp = 0;
      }
    }
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

    cli();                                 
    
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    
    TCCR1B |= (1 << CS11) | (1 << CS10);    
    TCNT1 = 40536;                          
    TIMSK1 = (1 << TOIE1);                  
    sei();  

  pinMode(2, INPUT);
  attachInterrupt(0, velocity, RISING);
}
 
void motorRightStop( ) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motorLeftStop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void motorLeftHead(int speed) { 
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}


void motorLeftBack(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

void motorRightHead(int speed) { 
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, HIGH);
  analogWrite(IN3, 255 - speed);
}

void motorRightBack(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, LOW);
  analogWrite(IN3, speed);
}
 
void loop()
{
 motorRightHead(200);
 //motorRightBack(200);
//motorLeftBack(200);
 //motorLeftHead(200);

    Serial.print(timer);
    Serial.print(" ");
    Serial.println(velo);
}


ISR (TIMER1_OVF_vect) 
{
    TCNT1 = 40536;
    temp++;
}