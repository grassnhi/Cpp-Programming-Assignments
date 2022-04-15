/*
Consider the following statement:
            clockType myClock (5, 12, 40);

This statement declares a variable name myClock belongs to type ClockType with 3 input variables. 

    Complete the constructor with 3 parameters in the class given in the answer box so that 
the time can be printed correctly.

    Complete the constructor with 0 parameters that set the value of three attributes to 0.
Note: 
    hr, min, sec need to satisfy the following conditions. 
    If the input parameter does not satisfy the condition below, 
    we assign the value 0 to the corresponding member variable:

            0 <= hr < 24
            0 <= min < 60
            0 <= sec < 60
*/

#include <iostream>

using namespace std;



int main(){
    ClockType myClock;
    myClock.printTime();
}