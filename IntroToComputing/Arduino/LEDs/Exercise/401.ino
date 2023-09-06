//Two Toggling LEDs

#include <stdio.h>
#include <stdlib.h>

void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop()
{
digitalWrite ( 0 , HIGH );
  delay(1000);
digitalWrite ( 0 , LOW );
    delay(1000);
digitalWrite ( 1 , HIGH );
    delay(1000);
digitalWrite ( 1 , LOW );
     delay(1000);
}