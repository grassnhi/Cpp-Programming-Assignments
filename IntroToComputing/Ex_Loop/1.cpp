/*
Write a program that inputs an array of N real numbers, and then computes and prints the average value 
of the array elements. N should be an input parameter.

Input:

The first line contains integer N, N >= 1
The second line contains N real numbers
Output:
The average value of the array elements, round up to 2 digits after decimal point
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
    int n, i;
    float num[100], sum=0.00, average;

    cin >> n;

    for(i = 0; i < n; ++i)
    {
        cin >> num[i];
        sum += num[i];
    }

    average = sum / n;
    cout << fixed << setprecision(2) << average;

    return 0;
    
}