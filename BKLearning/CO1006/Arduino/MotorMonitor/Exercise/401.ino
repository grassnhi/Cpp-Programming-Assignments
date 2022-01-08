/*
LED Controller 1

Implement a short program to make the LED connected to pin 13 turn on if a character
’O’ is received. Other characters, the LED is turned off.

Hint: Use the if statement: if(temp == ‘O’) . . . . else . . .
*/

void setup(){

Serial.begin (115200);
Serial.println ("LED Controller 1 ");

}

void loop () {
	if( Serial. available ()) {
		char temp = Serial. read ();
		Serial.print("I received: ");
		Serial.println( temp );

		if(temp == 'O') 
            digitalWrite(13, HIGH);
		else
            digitalWrite(13, LOW);
	}
}