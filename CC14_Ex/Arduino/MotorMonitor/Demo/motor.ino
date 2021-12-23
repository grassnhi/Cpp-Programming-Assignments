// fan
// left motor controller

void setup () {
    pinMode (8 , OUTPUT ) ;
    pinMode (11 , OUTPUT ) ;
    pinMode (9 , OUTPUT ) ;
}

void loop () {
    digitalWrite (11 , HIGH ) ;
    digitalWrite (8 , LOW ) ;
    analogWrite (9 , 100) ;
}