//Finalize the Analog Clock

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
    digitalWrite(num-1, HIGH);
  }
}

void clearClock(){
 for(int i = 0; i < 12; i++)
 digitalWrite(i, LOW);
}

void loop()
{
	displayOnClock(hour);
 	displayOnClock(minute / 5);
	displayOnClock(second / 5);
    
	delay(1000);

 	second = (second + 1) % 60;
	minute = (minute + second / 59) % 60;
 	hour = (hour + minute / 59) % 12;

 	clearClock();
}