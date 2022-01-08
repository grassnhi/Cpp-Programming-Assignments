/*
Write a program that inputs an array of N real numbers, and then finds and prints 
the largest element in the array. N should be an input parameter.

Input:
The first line contains integer N, N >= 1
The second line contains N real numbers

Output:
The largest element in the array, round up to 2 digits after decimal point
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
using namespace std;

float maximum(float arr[], int n)
{
    int i;
    float max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
 
int main()
{
    int n, i;
    float num[100];

    cin >> n;

    for(i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    
    cout << fixed << setprecision(2) << maximum(num, n);

    return 0;
}
