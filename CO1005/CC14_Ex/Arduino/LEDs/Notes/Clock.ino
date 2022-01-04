
int second = 0;
int minute = 0;
int hour = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 12; i++){
    pinMode(i, OUTPUT);
  }
}

void display_second(){
  int value = second / 5;
  switch(value){
    case 0:
    digitalWrite(11, LOW);
    digitalWrite(0, HIGH);
    break;

    case 1:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    break;

    case 2:
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    break;

    case 3:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    break;

    case 4:
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    break;

    case 5:
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    break;

    case 6:
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    break;

    case 7:
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    break;

    case 8:
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    break;

    case 9:
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    break;

    case 10:
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    break;

    case 11:
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    break;
  }
}
void display_minute(){
  int value = minute / 5;
  switch(value){
    case 0:
    digitalWrite(11, LOW);
    digitalWrite(0, HIGH);
    break;

    case 1:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    break;

    case 2:
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    break;

    case 3:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    break;

    case 4:
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    break;

    case 5:
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    break;

    case 6:
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    break;

    case 7:
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    break;

    case 8:
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    break;

    case 9:
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    break;

    case 10:
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    break;

    case 11:
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    break;
  }
}
void display_hour(){
  switch(hour){
    case 0:
    digitalWrite(11, LOW);
    digitalWrite(0, HIGH);
    break;

    case 1:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    break;

    case 2:
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    break;

    case 3:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    break;

    case 4:
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    break;

    case 5:
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    break;

    case 6:
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    break;

    case 7:
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    break;

    case 8:
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    break;

    case 9:
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    break;

    case 10:
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    break;

    case 11:
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  display_second();
  display_minute();
  display_hour();

  second++;

  if(second == 60){
    minute++;
    second = 0;
  }

  if(minute == 60){
    hour++;
    minute = 0;
  }

  if(hour == 12){
    hour = 0;
  }
  
  delay(1000);
}