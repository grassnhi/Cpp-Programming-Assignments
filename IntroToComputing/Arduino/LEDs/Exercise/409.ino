//Analog Clock with Second

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
  if(num == 0)
    digitalWrite(11, HIGH);
  else{
    digitalWrite(num - 1, HIGH);
  }
}

void clearClock(int i){
 for( i = 0; i < 12; i++)
 digitalWrite(i, LOW);
}

void loop()
{
 for(int i = 0; i < 12; i++){
    displayOnClock(i);
    delay(5000);
  	clearClock(i);
 }
}