//Traffic Light with Timer

#include <stdio.h>
#include <stdlib.h>

void setup(){
    for (int i = 0; i < 14; i++) {
       pinMode(i, OUTPUT);
	}
}

void displayNumber(int i){
  if (i == 0){
   	digitalWrite(4, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    
  }else if(i == 1){
  	digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);	 

  }else if(i == 2){
    digitalWrite(2, LOW);    
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);

    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

  }else if(i == 3){
    digitalWrite(3, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

  }else if(i == 4){
    digitalWrite(3, HIGH);    
    digitalWrite(4, HIGH);
    
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 5){
    digitalWrite(0, LOW);
    
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  
  }else if(i == 6){
    digitalWrite(0, LOW);
    
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 7){
    digitalWrite(0, LOW);
    
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  
  }else if(i == 8){
    digitalWrite(0, HIGH);
    
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  
  }else if(i == 9){
    digitalWrite(0, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
void loop(){
  for (int i = 0; i < 10; i++) {
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
  
    displayNumber(i);
    delay(1000);
}
}