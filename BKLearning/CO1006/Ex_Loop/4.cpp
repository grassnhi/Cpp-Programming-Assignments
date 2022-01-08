/*
Write a program that computes and prints x raised to the power n and power -n by repetitive multiplication.

Input:
The first line contains integer n, n >= 0
The second line contains real numbers x, x≠0

Output:
xn x−n

Note: 
Each value in output round up to 2 digits after decimal point, separated by 1 space character 
and no character after last value
Do not use cmath or math.h library
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

float power( int n, float x){
    int i=0;
    float rs =1;

    for(i=0; i<n; i++){
        rs = rs * x;
    }

    return rs;

}
int main()
{
    int n;
    float x;

    cin >> n >> x;

    cout << fixed << setprecision(2) << power(n,x) << " " << 1.00/power(n,x);
}

    
