/* 
Write a program that converts the number of days into years, weeks and days. 
Example: 1532 days = 4 years + 10 weeks + 2 days. 
Student needs to assign value to number of days and display the result as example. Assume a year has 365 days.
Input: one line contains number n - the number of days ( 0≤n≤1000000).
*/

#include<iostream>
using namespace std;

int main()
{
    int n, y, d, w;

    cin >> n;

    y = n / 365;
    d = n % 365;
    w = d / 7;
    d = d % 7;
    
    cout<< n << " days = "<< y << " years + "<< w << " weeks + " << d << " days.";

    return 0;

}