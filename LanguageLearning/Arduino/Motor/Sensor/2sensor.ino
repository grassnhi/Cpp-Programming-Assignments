const int trig1 = 8;
const int echo1 = 9;
const int trig2 = 6;
const int echo2 = 7;

int sensor(int trig, int echo){
    digitalWrite(trig, LOW);
    digitalWrite(trig, HIGH);  
    delayMicroseconds(5);

    digitalWrite(trig, LOW);

    float duration = pulseIn(echo, HIGH);

    return duration/2/29.412;
}

void setup(){
    Serial.begin(9600);
    
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT)
}

void loop(){
    Serial.print(sensor(trig1, echo1));
    Serial.print("  ");
    Serial.println(sensor(trig2, echo2));
}