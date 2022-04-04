/*
A 01010101
B 00001000
X 01011101

A |= (1 << n) 

A B X
0 0 0
1 0 1
0 1 1
1 1 1

X 01010101
  00010000
  01010101
X |= (1 << 4)
  00000010
  01010111
X |= (1 << 1)
=> X |= (1 << 4) | (1 << 1)

	01010101
00100000
00000010
00100010
*/

#include <avr/interrupt.h> // thư viện Interrupt của AVR.
 
volatile int temp; 
// khai báo volatile vì nó được sử dụng cả ở chương trình chính và ở chương trình ngắt.

void setup()
{
    Serial.begin(9600);
    
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
}

void loop()
{
   
}
 
 
ISR (TIMER1_OVF_vect) 
{
    TCNT1 = 40536;
    temp++;
}