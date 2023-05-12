const int trig = 8;
const int echo1 = 9;
const int echo2 = 7;
const int echo3 = 5;

float sensor(int echo){
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
    pinMode(echo1, INPUT);
    pinMode(echo2, INPUT);
    pinMode(echo3, INPUT);
}

void loop(){
    Serial.print(sensor(echo1));
    Serial.print("  ");
    Serial.print(sensor(echo2));
    Serial.print("  ");
    Serial.println(sensor(echo3));
}