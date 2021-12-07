//One Way Traffic Light

#include <stdio.h>
#include <stdlib.h>

void setup(){
    for (int i = 8; i < 11; i++) {
       pinMode(i, OUTPUT);
	}
}

void display( int i){
    switch(i){
      case 0:
      	digitalWrite(8, HIGH);
      	digitalWrite(9, LOW);
      	digitalWrite(10, LOW);     
      break;
      
      case 5:
        digitalWrite(8, LOW);
  		digitalWrite(9, HIGH);
  		digitalWrite(10, LOW);
      break;
      
      case 7:
      	digitalWrite(8, LOW);
  		digitalWrite(9, LOW);
  		digitalWrite(10, HIGH);
      break;
     }
}
void loop(){
 for (int i = 0; i < 10; i++) {
   display(i);
   delay(1000);
}
}