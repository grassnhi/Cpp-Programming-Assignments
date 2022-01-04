/*
Write a program that inputs an array of N real numbers, and then finds and prints the number of 
positive values and the number of negative ones among them. N should be an input parameter.

Input:
The first line contains integer N, N >= 1
The second line contains N real numbers

Output:
The number of positive values and the number of negative values, separated by 1 space character, 
no character after last value

Note:
0.0 counts as positive value
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int main()
{
    int i, n, pos=0, neg=0;
    float num[100];
    cin >> n;
    
    for(i = 0; i < n; ++i)
    {
        cin >> num[i];
        if (num[i] >= 0)
            pos += 1;
        else neg += 1;
    }
    cout << pos << " " << neg;
    return 0;
}
