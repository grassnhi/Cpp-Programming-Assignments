/*
Given a two-dimensional array whose each element is integer, its size is N x N.

Implement the following function: int diagonalProduct(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and 
its number of columns. 

Find the product of all elements on the main diagonal of this array.

Note: Libraries iostream, and string have been imported, and namespace std has been used.
*/

// C++ Program to find the Product
// of diagonal elements of a matrix

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int diagonalProduct(int arr[][1000], int row, int col){

	int product = 1, n = row;

	for (int i = 0; i < row; i++) {
		product = product * arr[i][i];
    }

	return product;
}

int main()
{
	int arr[][1000] = {{-45,18,-37},{-2,-31,24},{-48,-33,-48}};

    cout << diagonalProduct(arr,3,3);

	return 0;
}
