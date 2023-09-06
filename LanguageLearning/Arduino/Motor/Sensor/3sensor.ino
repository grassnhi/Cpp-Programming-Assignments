const int trig1 = 8;
const int echo1 = 9;
const int trig2 = 6;
const int echo2  = 7;
const int trig3= 4;
const int echo3 = 5;

float sensor(int trig, int echo){
    digitalWrite(trig, LOW);
    digitalWrite(trig, HIGH);  
    delayMicroseconds(5);

    digitalWrite(trig, LOW);

    float duration = pulseIn(echo, HIGH);

    return duration/2/29.412;
}                 
                                                                                                                    
void setup(){
    Serial.begin(9600);
    
    pinMode(trig1, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(trig2, OUTPUT);
    pinMode(echo2, INPUT);
    pinMode(trig3, OUTPUT);
    pinMode(echo3, INPUT);
}

void loop(){
    Serial.print(sensor(trig1, echo1));
    Serial.print("  ");
    Serial.print(sensor(trig2, echo2));
    Serial.print("  ");
    Serial.println(sensor(trig3, echo3));
}