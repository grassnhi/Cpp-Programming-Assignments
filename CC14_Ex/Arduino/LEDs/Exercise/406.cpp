// Two Way Traffic Light

#include <stdio.h>
#include <stdlib.h>

void setup(){
    for (int i = 8; i < 14; i++) {
       pinMode(i, OUTPUT);
	}
}

void display( int i){
    switch(i){
      case 0:
      	digitalWrite(8, HIGH);
      	digitalWrite(9, LOW);
      	digitalWrite(10, LOW);
      	digitalWrite(11, LOW);
      	digitalWrite(12, LOW);
      	digitalWrite(13, HIGH);
      break;

      case 3:
        digitalWrite(8, HIGH);
  		digitalWrite(9, LOW);
  		digitalWrite(10, LOW);
  		digitalWrite(11, LOW);
  		digitalWrite(12, HIGH);
  		digitalWrite(13, LOW);
      break;

      case 5:
      	digitalWrite(8, LOW);
  		digitalWrite(9, LOW);
  		digitalWrite(10, HIGH);
  		digitalWrite(11, HIGH);
  		digitalWrite(12, LOW);
  		digitalWrite(13, LOW);
      break;

      case 8:
      	digitalWrite(8, LOW);
  		digitalWrite(9, HIGH);
  		digitalWrite(10, LOW);
  		digitalWrite(11, HIGH);
  		digitalWrite(12, LOW);
  		digitalWrite(13, LOW);
      break;
    }
}

void loop(){
 for (int i = 0; i < 10; i++) {
   display(i);
   delay(1000);
}
}