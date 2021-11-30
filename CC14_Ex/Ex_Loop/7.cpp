/*
The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13,…, where the first two terms are 0 and 1, 
and each term thereafter is the sum of the two preceding terms, that is, Fibn=Fibn−1+Fibn−2.
Using this information, write a program that calculates the nth number in a Fibonacci sequence, 
where n is entered into the program by the user.

Input: 
Integer n, 90 >= n >= 1

Output:
The calculated value
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long fn = 0, f1 = 1, f0 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < 2) {
            fn = i;
        }
        else {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
    }
    cout << fn;
    return 0;
}