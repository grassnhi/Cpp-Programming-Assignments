#include<SoftwareSerial.h>
#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

SoftwareSerial ble(0,1);

int servo1Pos,servo2Pos,servo3Pos,servo4Pos,servo5Pos,servo6Pos;//current position
int servo1PPos,servo2PPos,servo3PPos,servo4PPos,servo5PPos,servo6PPos;//previous position
int servo1SP[50],servo2SP[50],servo3SP[50],servo4SP[50],servo5SP[50],servo6SP[50];//storing position
int speedDelay = 20;
int index = 0;
int dataln;
int m = 0;

void setup(){
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);
  ble.begin(9600);
  Serial.begin(9600);
  //move arms to initial position
  servo1PPos = 90;
  servo1.write(servo1PPos);
  servo2PPos = 100;
  servo2.write(servo2PPos);
  servo3PPos = 120;
  servo3.write(servo3PPos);
  servo4PPos = 95;
  servo4.write(servo4PPos);
  servo5PPos = 60;
  servo5.write(servo5PPos);
  servo6PPos = 110;
  servo6.write(servo6PPos);
}

void loop(){
  if(ble.available()>0){
    dataln = ble.read();
    switch(dataln){
      case 1: m = 1; break;
      case 2: m = 2; break;
      case 3: m = 3; break;
      case 4: m = 4; break;
      case 5: m = 5; break;
      case 6: m = 6; break;
      case 7: m = 7; break;
      case 8: m = 8; break;
      case 9: m = 9; break;
      case 10: m = 10; break;
      case 11: m = 11; break;
      case 12: m = 12; break;
      case 13: m = 13; break;
      case 14: m = 14; break;
      case 15: m = 15; break;
      case 16: m = 16; break;
    }
     Serial.print(dataln);
    //move robot arms
    //move servo1 in + direction
    while(m == 1){
       if(ble.available()>0){
        m = ble.read();
       }
       servo1.write(servo1PPos);
       servo1PPos ++;
       delay(speedDelay);
  }  
     //move servo1 in - direction
     while(m == 2){
        if(ble.available()>0){
          m = ble.read();
        }
        servo1.write(servo1PPos);
        servo1PPos --;
        delay(speedDelay);
     }
      //move servo2 in + direction
    while(m == 3){
       if(ble.available()>0){
        m = ble.read();
       }
       servo2.write(servo2PPos);
       servo2PPos ++;
       delay(speedDelay);
  }  
     //move servo2 in - direction
     while(m == 4){
        if(ble.available()>0){
          m = ble.read();
        }
        servo2.write(servo2PPos);
        servo2PPos --;
        delay(speedDelay);
     }
      //move servo3 in + direction
    while(m == 5){
       if(ble.available()>0){
        m = ble.read();
       }
       servo3.write(servo3PPos);
       servo3PPos ++;
       delay(speedDelay);
  }  
     //move servo3 in - direction
     while(m == 6){
        if(ble.available()>0){
          m = ble.read();
        }
        servo3.write(servo3PPos);
        servo3PPos --;
        delay(speedDelay);
     }
      //move servo4 in + direction
    while(m == 7){
       if(ble.available()>0){
        m = ble.read();
       }
       servo4.write(servo4PPos);
       servo4PPos ++;
       delay(speedDelay);
  }  
     //move servo4 in - direction
     while(m == 8){
        if(ble.available()>0){
          m = ble.read();
        }
        servo4.write(servo4PPos);
        servo4PPos --;
        delay(speedDelay);
     }
      //move servo5 in + direction
    while(m == 9){
       if(ble.available()>0){
        m = ble.read();
       }
       servo5.write(servo5PPos);
       servo5PPos ++;
       delay(speedDelay);
  }  
     //move servo5 in - direction
     while(m == 10){
        if(ble.available()>0){
          m = ble.read();
        }
        servo5.write(servo5PPos);
        servo5PPos --;
        delay(speedDelay);
     }
      //move servo6 in + direction
    while(m == 11){
       if(ble.available()>0){
        m = ble.read();
       }
       servo6.write(servo6PPos);
       servo6PPos ++;
       delay(speedDelay);
  }  
     //move servo6 in - direction
     while(m == 12){
        if(ble.available()>0){
          m = ble.read();
        }
        servo6.write(servo6PPos);
        servo6PPos --;
        delay(speedDelay);
     }
     //if arm speed slider is changed
     if(dataln > 101 & dataln < 250){
      speedDelay = dataln/10; //change servo speed
     }
     //if button "SAVE" is pressed
     if (m == 13){
      servo1SP[index] = servo1PPos;
      servo2SP[index] = servo2PPos;
      servo3SP[index] = servo3PPos;
      servo4SP[index] = servo4PPos;
      servo5SP[index] = servo5PPos;
      servo6SP[index] = servo6PPos;
      index ++;
      m = 0;
     }
     //if button "RUN" is pressed
     if(m == 14){
      runSteps();
      //if button "RESET" is pressed
      if(dataln != 14){
        memset(servo1SP,0,sizeof(servo1SP)); //clear array data to 0
        memset(servo2SP,0,sizeof(servo2SP));
        memset(servo3SP,0,sizeof(servo3SP));
        memset(servo4SP,0,sizeof(servo4SP));
        memset(servo5SP,0,sizeof(servo5SP));
        memset(servo6SP,0,sizeof(servo6SP));
        index = 0;
      }
     }
  }
}

//Automatic mode custom function - run saved steps
void runSteps(){
  while(dataln != 15){
    for(int i=0;i<=index-2;i++){
      if(ble.available()>0){
        dataln = ble.read();
        if(dataln == 16){        //If button "PAUSE" is pressed
          while(dataln != 14){   //Wait until "RUN" is pressed again
            if(ble.available()>0){
              dataln = ble.read();
              if(dataln == 15){
                break;
              }
            }
          }
        }
        //If speed slider is changed
        if(dataln > 100 & dataln < 150){
          speedDelay = dataln/10; 
        }       
      }
      //servo 1
      if(servo1SP[i] == servo1SP[i+1]){}
      if(servo1SP[i] > servo1SP[i+1]){
        for(int j=servo1SP[i];j>=servo1SP[i+1];j--){
          servo1.write(j);
          delay(speedDelay);
        }
      }
      if(servo1SP[i] < servo1SP[i+1]){
        for(int j=servo1SP[i];j<=servo1SP[i+1];j++){
          servo1.write(j);
          delay(speedDelay);
        }
      }
       //servo 2
      if(servo2SP[i] == servo2SP[i+1]){}
      if(servo2SP[i] > servo2SP[i+1]){
        for(int j=servo2SP[i];j>=servo2SP[i+1];j--){
          servo2.write(j);
          delay(speedDelay);
        }
      }
       if(servo2SP[i] < servo2SP[i+1]){
        for(int j=servo2SP[i];j<=servo2SP[i+1];j++){
          servo2.write(j);
          delay(speedDelay);
        }
      }
       //servo 3
      if(servo3SP[i] == servo3SP[i+1]){}
      if(servo3SP[i] > servo3SP[i+1]){
        for(int j=servo3SP[i];j>=servo3SP[i+1];j--){
          servo3.write(j);
          delay(speedDelay);
        }
      }
       if(servo3SP[i] < servo3SP[i+1]){
        for(int j=servo3SP[i];j<=servo3SP[i+1];j++){
          servo3.write(j);
          delay(speedDelay);
        }
      }
       //servo 4
      if(servo4SP[i] == servo4SP[i+1]){}
      if(servo4SP[i] > servo4SP[i+1]){
        for(int j=servo4SP[i];j>=servo4SP[i+1];j--){
          servo4.write(j);
          delay(speedDelay);
        }
      }
       if(servo4SP[i] < servo4SP[i+1]){
        for(int j=servo4SP[i];j<=servo4SP[i+1];j++){
          servo4.write(j);
          delay(speedDelay);
        }
      }
       //servo 5
      if(servo5SP[i] == servo5SP[i+1]){}
      if(servo5SP[i] > servo5SP[i+1]){
        for(int j=servo5SP[i];j>=servo5SP[i+1];j--){
          servo5.write(j);
          delay(speedDelay);
        }
      }
       if(servo5SP[i] < servo5SP[i+1]){
        for(int j=servo5SP[i];j<=servo5SP[i+1];j++){
          servo5.write(j);
          delay(speedDelay);
        }
      }
       //servo 6
      if(servo6SP[i] == servo6SP[i+1]){}
      if(servo6SP[i] > servo6SP[i+1]){
        for(int j=servo6SP[i];j>=servo6SP[i+1];j--){
          servo6.write(j);
          delay(speedDelay);
        }
      }
       if(servo6SP[i] < servo6SP[i+1]){
        for(int j=servo6SP[i];j<=servo6SP[i+1];j++){
          servo6.write(j);
          delay(speedDelay);
        }
      }
    }
  }
}
