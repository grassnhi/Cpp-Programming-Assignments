int pinled [] = {2,3,4,5,6,7,8};

int state = 0;
int counter = 0;
  
void setup(){
    for (int i = 2; i < 9; i++) {
       pinMode(pinled [i], OUTPUT);
  }
}

void displayNumber(int i){
  if (i == 0){
    digitalWrite(2, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    
  }else if(i == 1){
    digitalWrite(5, LOW);  
    digitalWrite(8, LOW);
    
    digitalWrite(8, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
  
  }else if(i == 2){
    digitalWrite(3, HIGH);
    digitalWrite(8, HIGH);
    
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  
  }else if(i == 3){
    digitalWrite(3, HIGH);    
    digitalWrite(6, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
  
  }else if(i == 4){
    digitalWrite(4, HIGH);    
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 5){
    digitalWrite(5, HIGH);    
    digitalWrite(6, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 6){
    digitalWrite(5, HIGH);
    
    digitalWrite(7, LOW);
    digitalWrite(2, LOW);
    digitalWrite(8, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 7){
    digitalWrite(4, LOW);    
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);

    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  
  }else if(i == 8){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  
  }else if(i == 9){
    digitalWrite(6, HIGH);
    
    digitalWrite(8, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}

/*
void display7SEG(int num) {
  byte led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
  for (int i = 0; i < 7; i++) {
    digitalWrite( 2 + i, (led7seg[num] >> i) & 1);
  }
}
*/

void loop() {
  switch (state){
    case 0:
      for (int i = 0; i < 10; i++) {
        displayNumber(i);
        if(counter != 100) 
        counter++;
        else{
            counter = 0;
        }
      }
      state = 1;  
      break;
    case 1:
      if(counter != 100) 
        counter++;
      else{
        counter = 0;
        state = 0;
      }
      break;
  }
  delay(10);
}
