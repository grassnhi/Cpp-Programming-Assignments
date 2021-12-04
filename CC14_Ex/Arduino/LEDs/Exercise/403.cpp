#include <stdio.h>
#include <stdlib.h>

int pinled [] = {0,1,2,3,4,5,6};
  
void setup(){
    for (int i = 0; i < 7; i++) {
       pinMode(pinled [i], OUTPUT);
	}
}

void displayNumber(int i){
  if (i == 0){
    digitalWrite(0, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    
  }else if(i == 1){
    digitalWrite(3, LOW);  
   	digitalWrite(6, LOW);
    
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(0, HIGH);
  
  }else if(i == 2){
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(0, LOW);
  
  }else if(i == 3){
    digitalWrite(1, HIGH);    
    digitalWrite(4, HIGH);
    
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 4){
    digitalWrite(2, HIGH);    
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 5){
    digitalWrite(3, HIGH);    
    digitalWrite(4, HIGH);
    
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 6){
    digitalWrite(3, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 7){
    digitalWrite(2, LOW);    
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);

    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  
  }else if(i == 8){
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 9){
    digitalWrite(4, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}

void loop(){
  displayNumber(0);
  delay(2000);
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1000);
  }
}