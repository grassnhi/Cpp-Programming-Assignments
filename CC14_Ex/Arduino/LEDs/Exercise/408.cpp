//Analog Clock Project

#include <stdio.h>
#include <stdlib.h>

int second = 0;
int minute = 0;
int hour = 0;

void setup()
{
  for(int i = 0; i < 12; i++){
  	pinMode(i, OUTPUT);
  }
}

void displayOnClock(int num){
  if(num <= 12){
	digitalWrite(num-1, HIGH); 
  }
}

void clearClock(){
 for(int i = 0; i <= 12; i++){
   digitalWrite(i, LOW);
 }
}

void loop()
{
  for(int i = 0; i < 12; i++){
    displayOnClock(i + 1);
    delay(1000);
  }
  
  clearClock();
  delay(1000);
}