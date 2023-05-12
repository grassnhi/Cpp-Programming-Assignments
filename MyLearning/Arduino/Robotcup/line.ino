#define A  7
#define AA  6
#define B  4
#define BB  5
#define PWMA  10
#define PWMB  9
//42.79 10.7 90 90
float Kp = 52.6, Ki = 0, Kd =21.4, PID_value;
short error, I = 0, P, D, pp = 0, s[4] = { 0, 0, 0, 0};
byte l = 145, r = 145;
long a, truoc = 10000;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A5, INPUT);

    pinMode(A, OUTPUT);
    pinMode(AA, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(BB, OUTPUT);

    pinMode(PWMA, INPUT_PULLUP);
    pinMode(PWMB, INPUT_PULLUP);

}

void read() {
    s[0] = digitalRead(A0) * 1000;
    s[1] = digitalRead(A1) * 100;
    s[2] = digitalRead(A2) * 10;
    s[3] = digitalRead(A3);
    a = truoc * 10000 + s[0] + s[1] + s[2] + s[3];
    truoc = 10000 + s[0] + s[1] + s[2] + s[3];
    switch (a) {
        case 110010001: error = 101; break;
        case 100110001: error = -101; break;
        case 100010001: error = 101; break;
        
        case 110010011: error = 2; break;
        case 101110011: error = -2; break;
        case 100110011: error = 2; break;
        
        case 100110111: error = 3; break;
        case 111110111: error = -3; break;
        case 101110111: error= 3; break;

        case 111001000: error = 4; break;
        case 100011000: error = -4; break;
        case 110001000: error = -4; break;

        case 110011001: error = 0; break;
        case 111111001: error = 0; break;
        case 100001001: error = 0; break;
        case 100000000: error =0; break;

        case 111000110: error = 1; break;
        case 100110110: error = -1; break;
        case 111101101: error = 1;break;
        case 110111101: error = -1;break;
        case 110011101: error = -1;break;

        case 110011011: error =1;break;
        case 110111011: error =1;break;
        case 101111011: error = -1;break;

        case 110011100: error = -2; break;
        case 111101100: error = 2; break;
        case 111001100: error = -2;break;

        case 111001110: error = -3; break;
        case 111111110: error = 3; break;
        case 111101110: error = -3;break;
/*
        case 110001111:
        case 111001111:
        case 111101111:
        case 111111111:{
    s[0] = digitalRead(A0) * 1000;
    s[1] = digitalRead(A1) * 100;
    s[2] = digitalRead(A2) * 10;
    s[3] = digitalRead(A3);
     a = s[0] + s[1] + s[2] + s[3];
     while (a != 1001 && a!= 1100 && a != 1000 && a !=0011 && a != 0001){
    analogWrite(PWMA, 255);
    analogWrite(PWMB, 0);
    digitalWrite(A, LOW);
    digitalWrite(AA, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(BB, LOW); 
    s[0] = digitalRead(A0) * 1000;
    s[1] = digitalRead(A1) * 100;
    s[2] = digitalRead(A2) * 10;
    s[3] = digitalRead(A3);
     a = s[0] + s[1] + s[2] + s[3];
          }
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    digitalWrite(A, LOW);
    digitalWrite(AA, LOW);
    digitalWrite(B, LOW);
    digitalWrite(BB, LOW); 
        }break; 
*/
        
        default:/* {
        if(error = 5) error =-5;
        else error = 5; } */
        error = 0;
        break;

    }
}

void PID(){
 //Kd = 10+ analogRead(A5)*0.1;
// Serial.println(Kd);
    P = error;
    I = I + error;
    D = error - pp;
    PID_value = (Kp * P) + (Ki * I) + (Kd * D);
    pp = error;
}

void run(){
   int ll = l - PID_value; 
   int rr = r + PID_value;

    ll = constrain(ll, 0, 145);
    rr = constrain(rr, 0, 145);
 
 //  Serial.println(ll);
 //  Serial.println(rr);
    analogWrite(PWMA, ll);
    analogWrite(PWMB, rr);
    digitalWrite(A, LOW);
    digitalWrite(AA, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(BB, HIGH);
}


void loop() {
    read();
    PID();
    run();
}