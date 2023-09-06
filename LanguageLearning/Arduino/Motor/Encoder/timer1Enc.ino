#include <avr/interrupt.h> // thư viện Interrupt của AVR.
 
volatile int temp; 
// khai báo volatile vì nó được sử dụng cả ở chương trình chính và ở chương trình ngắt.

float velo;
float timer;

int save = TCNT1;
void velocity(){
    timer = (TCNT1 - save)*0.000004;
    velo = 1 / timer;
    save = TCNT1;
}
// lưu TCNT1 cố định -> thời gian = (TCNT1- lưu)*0.4us 
// xuất vân tốc mỗi 1ms? nhưng phải chính xác?
//  
void setup()
{
    
    Serial.begin(9600);

    pinMode(2, INPUT);
    
    cli();                                  // tắt ngắt toàn cục
    
    /* Reset Timer/Counter1 */
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    
    /* Setup Timer/Counter1 */
    TCCR1B |= (1 << CS11) | (1 << CS10);    // prescale = 64
    TCNT1 = 40536;                          // thời gian cần ngắt là 0.1s
    TIMSK1 = (1 << TOIE1);                  // Overflow interrupt enable 
    sei();                                  // cho phép ngắt toàn cục

    attachInterrupt(0, velocity, RISING);
}

void loop()
{
   Serial.print(timer);
   Serial.print(" ; ");
   Serial.println(velo);
}
 
 
ISR (TIMER1_OVF_vect) 
{
    TCNT1 = 40536;
    temp++;
}