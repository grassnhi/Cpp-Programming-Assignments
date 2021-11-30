/*
Write a program to tabulate sin(x), cos(x) and tan(x) for x = 5, 10, 15,…, 85 degrees. 
Note: 

x is an integer number, runs from 5 to 85, each value separated by 5 units.
We have to convert x from degrees to radians before using standard functions sin(x), cos(x), tan(x) 
of math.h library. For this exercise only, we let π=3.14 

Input: None

Output:
For each value of x, 3 values sin(x), cos(x) and tan(x) are outputted, round up to 2 digits 
after decimal point, each separated by 1 space character, newline character after last value,
except when x = 85 degree then no newline character
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
    double x;
    int i;
    
    for(i=5; i<=85; i+=5){
        x = i*3.14/180;
        cout << fixed << setprecision(2) << sin(x) << " " << cos(x) << " " << sin(x)/cos(x) << endl;
    }    
}