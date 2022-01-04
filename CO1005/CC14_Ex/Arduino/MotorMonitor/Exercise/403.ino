/*
Robot Controller

When a character W, S, A and D is sent, the robot moves forward, backward, left and right,
respectively. With all other characters, the robot stops moving.
*/

void setup(){
    Serial.begin (115200);

  	pinMode(8, OUTPUT);
  	pinMode(9, OUTPUT);
  	pinMode(10, OUTPUT); 
  	pinMode(11, OUTPUT);
  	pinMode(12, OUTPUT); 
  	pinMode(13, OUTPUT);
}

void forward (int speed){
    digitalWrite(8, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  
    analogWrite(9, speed);
    analogWrite(10, speed);
}

void backward (int speed ) {
 	digitalWrite(8, LOW);
  	digitalWrite(13, LOW);
  	digitalWrite(11, HIGH);
  	digitalWrite(12, HIGH);
  
  	analogWrite(9, speed);
  	analogWrite(10, speed);
}

void turnleft (int speed){ 
 	digitalWrite(8, LOW);
  	digitalWrite(13, HIGH);
  	digitalWrite(11, LOW);
  	digitalWrite(12, LOW);
  
  	analogWrite(10, speed);
}

void turnright (int speed) {
 	digitalWrite(8, HIGH);
  	digitalWrite(13, LOW);
  	digitalWrite(11, LOW);
  	digitalWrite(12, LOW);
  
  	analogWrite(9, speed); 
}

void loop () {
  	if( Serial. available() ){
		char temp = Serial. read (); 
		Serial.print ("I received : "); 
		Serial.println ( temp);

		if (temp == 'W')
			forward (100);

		else if (temp == 'S')
			backward (100);
  
    	else if (temp == 'A')
			turnleft (100);
  	
    	else if (temp == 'D')
			turnright (100);
  	
    	else{
      		digitalWrite(6, LOW);
      		digitalWrite(7, LOW);
      		digitalWrite(8, LOW);
      		digitalWrite(11, LOW);
      		digitalWrite(12, LOW);
     		digitalWrite(13, LOW);
   	    }
    }
}