/*
LED Controller 2

Improve your program to make the LED connected to pin 13 turn on if a character ’O’ is
received. However, the LED is turned off only when receiving character ’F’.
*/

void setup(){
    Serial.begin (115200);
    Serial.println ("LED Controller 2 ");
}

void loop () {
	if( Serial. available ()) {
		char temp = Serial.read ();

		Serial.print("I received: ");
		Serial.println( temp );

		if(temp == 'O') 
            digitalWrite(13, HIGH);

		if(temp == 'F') 
            digitalWrite(13, LOW);
	}
}