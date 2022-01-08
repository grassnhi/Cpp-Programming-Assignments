//Two Digit Number

#include <stdio.h>
#include <stdlib.h>

// C++ code
//
void setup () {
  for(int i  = 0; i < 14; i++){
  	pinMode(i, OUTPUT);
}
}

void displayNumber1 (int i) {
  if (i >= 0 && i < 10){
    digitalWrite(0, HIGH);
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if (i >= 10 && i < 20){
    digitalWrite(3, LOW);  
   	digitalWrite(6, LOW);
    
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(0, HIGH);
  
  }else if(i == 20){
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(0, LOW);
  }
}

void displayNumber2 (int i) {
  if (i == 0 || i == 10 || i == 20 ){
    digitalWrite(7, HIGH);
    
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    
  }else if(i == 1 || i == 11){
    digitalWrite(10, LOW);  
   	digitalWrite(13, LOW);
    
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(7, HIGH);
  
  }else if(i == 2 || i == 12){
    digitalWrite(8, HIGH);
    digitalWrite(13, HIGH);
    
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(7, LOW);
  
  }else if(i == 3 || i == 13){
    digitalWrite(8, HIGH);    
    digitalWrite(11, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  
  }else if(i == 4 || i == 14){
    digitalWrite(9, HIGH);    
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
  
  }else if(i == 5 || i == 15){
    digitalWrite(10, HIGH);    
    digitalWrite(11, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  
  }else if(i == 6 || i == 16){
    digitalWrite(10, HIGH);
    
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  
  }else if(i == 7 || i == 17){
    digitalWrite(9, LOW);    
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  
  }else if(i == 8 || i == 18){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  
  }else if(i == 9 || i == 19){
    digitalWrite(11, HIGH);
    
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}

void loop () {
	for(int i  = 0; i < 21 ; i++){
      displayNumber1(i);
      displayNumber2(i);
      delay(1000);
	}
}