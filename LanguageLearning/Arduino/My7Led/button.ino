int pinled [] = {0,1,2,3,4,5,6};
int pinCount;

int state = 0;
int counter = 0;

const int pinBut = 4;
unsigned char onOff = 0;

# define N0_OF_BUTTONS 3
# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED 0
# define BUTTON_IS_RELEASED 1

int buttonBuffer [ N0_OF_BUTTONS ] = {1, 1, 1};
int debounceButtonBuffer1 [ N0_OF_BUTTONS ] = {1, 1, 1};
int debounceButtonBuffer2 [ N0_OF_BUTTONS ] = {1, 1 , 1};

static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ] = {0, 0 , 0};
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ] = {1, 1, 1};

void setup(){
  for (int i = 0; i < 7; i++){
      pinMode(pinled [i], OUTPUT);
  }

  pinMode(pinBut, INPUT_PULLUP);

  for (int i = 0; i < 7; i++){
      digitalWrite(i, LOW);
  }
}

void button_reading ( void )
{
  for ( int i = 0; i < N0_OF_BUTTONS ; i++)
  {
    debounceButtonBuffer2 [i] = debounceButtonBuffer1 [i];
    debounceButtonBuffer1 [i] = digitalRead(11 + i);
    if ( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])
    {
      buttonBuffer [i] = debounceButtonBuffer1 [i];
      if ( buttonBuffer [i] == BUTTON_IS_PRESSED )
      {
        if ( counterForButtonPress1s [i] < DURATION_FOR_AUTO_INCREASING )
        {
          counterForButtonPress1s [i ]++;
        }
        else
        {
          flagForButtonPress1s [i] = 1;
          //todo
        }
      }
      else
      {
        counterForButtonPress1s [i] = 0;
        flagForButtonPress1s [i] = 0;
      }
    }
  }
}

unsigned char is_button_pressed ( uint8_t index )
{
  if ( index >= N0_OF_BUTTONS ) return 0;
  return ( buttonBuffer [ index ] == BUTTON_IS_PRESSED );
}

unsigned char is_button_pressed_1s ( unsigned char index )
{
  if ( index >= N0_OF_BUTTONS ) return 0xff;
  return ( flagForButtonPress1s [ index ] == 1);
}

void display(int index){
  switch(index){
    case 0:
      digitalWrite(1, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 1:
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 2:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 3:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 4:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 5:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    case 6:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      break;
    case 7:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;
    case 8:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;
    case 9:
      digitalWrite(1, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      break;
  }
}

void loop() {
  switch (state){
    case 0:
      display(rand() % 10);
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
