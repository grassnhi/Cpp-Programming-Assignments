/*
Write and run a program that reads an integer n (-1000000 ≤ n ≤ 1000000) 
from the keyboard and displays whether the number is odd or not? 
You MUST NOT use IF statement.
*/

#include<iostream>
using namespace std;

int main()
{
    int a;

    cin >> a ;

    int u=a %2;

    string rs= (u != 0) ? "Odd":"Even";
    
    cout <<rs;

    return 0;
}