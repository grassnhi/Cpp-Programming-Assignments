/*
Write a program that asks the user to type 5 integers 
(the value of 5 integers are in range [-1000000; 1000000]) and writes the average of the 5 integers. 
This program uses only 2 variables.
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a=0, b;

    cin >> b;
    a=a+b;
    
    cin >> b;
    a=a+b;
    
    cin >> b;
    a=a+b;
    
    cin >> b;
    a=a+b;
    
    cin >> b;
    a=a+b;

    cout<<fixed<<setprecision(2)<<"The average of 5 integers: "<<a/5.0;

    return 0;
}