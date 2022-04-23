/*
In this assignment, students will write a program of the voltage signal going through a LED light 
on the Arduino circuit. This voltage signal shows the brightness of the LED light at that time. 
Students will be provided with a file containing the input data. 
The value of the electrical resistance will be inserted in this file.

The input data of the program is stored in a file. This file contains the kind of int data in the following format:
R
Where:
R: the value of electrical resistance for the formula used to measure the voltage signal
The formula for the measurement of the voltage signal is as follows::
V (voltage) = R * (5.0/1023.0)

The program will output the brightness of the light directly to the screen depending 
on the voltage signal listed below

- If the voltage signal is less than 1.4. The LED light is off

- If the voltage signal is more than or equal to 1.4 and less than 2.5 volts. 
The LED light will h avedim brightness

- If the voltage signal is more than or equal to 2.5 and less than 5 volts. 
The LED light will be of medium brightness

- If the voltage signal is equal to 5 volts. The LED light will be of maximum brightness

- If the voltage signal is more than 5 volts. The LED light will be short-circuited

*/

// include section and declare library used

#include <iostream>
using namespace std;

int main()
{      

// declare and read the input (provided)

    int R;

    float V;

    cin >> R;

    //the main body, where students add, adjust the code to complete the program

    //The formula for the measurement 

    V = R * (5.0/1023.0);

    // the light is off

    if (V < 1.4 )

        cout << "The LED light is off " << endl;

    // The light will have dim brightness

    else if (V >= 1.4 && V < 2.5)

        cout << "The LED light will have dim brightness" << endl;

    // The light will be of medium brightness

    else if (V >= 2.5 && V < 5)

        cout << "The LED light will be of medium brightness" << endl;

    // The LED light will be of maximum brightness

    else if (V == 5)

        cout << "The LED light will be of maximum brightness" << endl;

    else

        cout << "The LED light will be short-circuited" <<endl;


    //(provided)

    return 0;

}