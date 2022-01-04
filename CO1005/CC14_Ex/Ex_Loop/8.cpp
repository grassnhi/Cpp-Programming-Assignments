/*
The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13,…, where the first two terms are 0 and 1, 
and each term thereafter is the sum of the two preceding terms, that is, Fibn=Fibn−1+Fibn−2.

Using this information, write a program that computes and stores the Fibonacci sequence 
in an integer array F, such that  F[i] will store the (i+1)th number in a Fibonacci sequence. 
The size of the array is an input parameter which is entered by the user.

Input: 
Integer size, 90 >= size >= 1

Output:
Every value of the array, each value separated by 1 space character, no character after the last value
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int main()
{
    long long n, arr[100];
    long long fn = 0, f1 = 1, f0 = 0;

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        if (i < 2) {
            fn = i;
            arr[i] = fn;
            
            cout << arr[i] << " ";
        }

        else {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
            arr[i] = fn;

            cout << arr[i] << " ";
        }
    }
    
    return 0;    
}
