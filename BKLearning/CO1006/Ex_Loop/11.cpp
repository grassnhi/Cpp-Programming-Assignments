/*
Write a program that inputs a square integer matrix of order n and transposes it and then prints it out. 
Transposing a square matrix means: aij↔aji for all i,j. n should be an input parameter.

Input:
The first line contains integer n, n >= 1
For the next n line, each line contains n integer numbers, separated by 1 space character

Output:
The transpose of the input matrix. n row: each row includes n values of that row, 
seperated by 1 space character, newline character after last value

Note: 
No newline after last value of the last row
You should store the input matrix in a 2-dimensional array
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int main()
{
    const int n = 10;

    int a[n][n];
    int i,j;
    for( i=0 ; i <n; i++){
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for( i=0 ; i <n; i++){
        for (j = 0; j < n; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }
    return 0;
    
}