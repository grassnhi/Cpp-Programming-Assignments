# define N0_OF_BUTTONS 3
# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED 0
# define BUTTON_IS_RELEASED 1
int buttonBuffer [ N0_OF_BUTTONS ] = {1, 1, 1};
int debounceButtonBuffer1 [ N0_OF_BUTTONS ] = {1, 1, 1};
int debounceButtonBuffer2 [ N0_OF_BUTTONS ] = {1, 1 , 1};
static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ] = {0, 0 , 0};
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ] = {1, 1, 1};


int check_btn_1 = 0;
int check_btn_2 = 0;
int check_btn_3 = 0;


int state = 0;
int value = 10;
int max_value = 10;
int pre_value = 10;
int check_set_value = 0;

int timer1_counter = 10;
int timer1_flag = 0;

int timer0_counter = 100;
int timer0_flag = 0;

int led_buffer[2] = {1, 2};
int index_led = 1;


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

void display7SEG(int num) {
  byte led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
  for (int i = 0; i < 7; i++) {
    digitalWrite( 2 + i, (led7seg[num] >> i) & 1);
  }
}

void update7SEG ( int index ) {
  switch ( index ) {
    case 1:
      // Display the first 7 SEG with led_buffer [0]
      digitalWrite( 10, HIGH);
      digitalWrite(  9, LOW);
      display7SEG(led_buffer[0]);
      break ;
    case 2:
      // Display the third 7 SEG with led_buffer [2]
      digitalWrite( 10, LOW);
      digitalWrite(  9, HIGH);
      display7SEG(led_buffer[1]);
      break ;
  }
}

void updateClockBuffer(int num) {
  led_buffer[0] = num / 10;
  led_buffer[1] = num % 10;
}


void setup() {
  // put your setup code here, to run once:
  //Button
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  //ENABLE LED
  pinMode( 10, OUTPUT); // led 1
  pinMode( 9, OUTPUT);  // led 2


  pinMode( 8, OUTPUT);//g
  pinMode( 7, OUTPUT);//f
  pinMode( 6, OUTPUT);//e
  pinMode( 5, OUTPUT);//d
  pinMode( 4, OUTPUT);//c
  pinMode( 3, OUTPUT);//b
  pinMode( 2, OUTPUT);//a


  pinMode(1, OUTPUT);


  digitalWrite( 10, HIGH);
  digitalWrite(  9, LOW);
  updateClockBuffer(value);
}

void loop() {
  switch (state) {
    case 0:
      digitalWrite( 1, HIGH);
      if (timer1_flag == 1) {
        index_led++;
        if (index_led > 2)index_led = 1;
        timer1_counter = 10;
        timer1_flag = 0;
        update7SEG(index_led);
      }
      if (timer0_flag == 1) {
        timer0_counter = 100;
        timer0_flag = 0;
        value--;
        if (value < 0) value = max_value;
        updateClockBuffer(value);
      }
      if (is_button_pressed(0) && check_btn_1 == 0)
      {
        check_btn_1++;
      }
      else if (is_button_pressed_1s(0) && check_btn_1 == 1) {
        check_btn_1++;
      }
      else if ((!is_button_pressed(0) && check_btn_1 == 1) || (!is_button_pressed(0) && check_btn_1 == 2))
      {
        timer0_counter = 100;
        timer0_flag = 0;
        timer1_counter = 10;
        timer1_flag = 1;
        pre_value = max_value;
        max_value = 0;
        updateClockBuffer(max_value);
        state = 1;
        check_set_value = 0;
        check_btn_1 = 0;
      }
      break;
    case 1:
      digitalWrite( 1, LOW);
      if (is_button_pressed(0) && check_btn_1 == 0)
      {
        check_btn_1++;
      }
      else if (is_button_pressed_1s(0) && check_btn_1 == 1) {
        check_btn_1++;
      }
      else if ((!is_button_pressed(0) && check_btn_1 == 1) || (!is_button_pressed(0) && check_btn_1 == 2))
      {
        timer0_counter = 100;
        timer0_flag = 0;
        timer1_counter = 10;
        timer1_flag = 1;
        state = 0;
        check_btn_1 = 0;
        if(check_set_value == 0){
          max_value = pre_value;
        }
        value = max_value;
      }
      if (is_button_pressed(1) && check_btn_2 == 0)
      {
        check_btn_2++;
      } else if (is_button_pressed_1s(1) && check_btn_2 == 1) {
        check_btn_2++;
      } else if ((!is_button_pressed(1) && check_btn_2 == 1) || (!is_button_pressed(1) && check_btn_2 == 2)) {
        if (max_value < 100)max_value++;
        check_btn_2 = 0;
        check_set_value = 1;
        updateClockBuffer(max_value);
      }
      if (is_button_pressed(2) && check_btn_3 == 0)
      {
        check_btn_3++;
      } else if (is_button_pressed_1s(2) && check_btn_3 == 1) {
        check_btn_2++;
      } else if ((!is_button_pressed(2) && check_btn_3 == 1) || (!is_button_pressed(2) && check_btn_3 == 2)) {
        if (max_value > 0) max_value--;
        check_btn_3 = 0;
        check_set_value = 1;
        updateClockBuffer(max_value);
      }
      if (timer1_flag == 1) {
        index_led++;
        if (index_led > 2)index_led = 1;
        timer1_counter = 10;
        timer1_flag = 0;
        update7SEG(index_led);
      }
      if (timer0_flag == 1) {
        timer0_counter = 100;
        timer0_flag = 0;
      }
      break;
  }
  if (timer0_counter > 0) {
    timer0_counter--;
    if (timer0_counter == 0) timer0_flag = 1;
  }
  if (timer1_counter > 0) {
    timer1_counter--;
    if (timer1_counter == 0) timer1_flag = 1;
  }
  button_reading();
  delay(10);
}
