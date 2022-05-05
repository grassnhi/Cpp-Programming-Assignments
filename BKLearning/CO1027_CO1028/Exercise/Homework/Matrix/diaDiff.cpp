/*
Given a two-dimensional array whose each element is an integer, its size is M x N.

Implement the following function:
        int diagonalDiff(int arr[][1000], int row, int col, int x, int y);
Where arr, row and col are the given two-dimensional array, its number of rows and 
its number of columns. ; x and y represent the cell whose index of the row is x and 
index of the column is y (0≤x<row và 0≤y<col). The sum of a diagonal is the sum of all elements on it. 

Find the absolute value of the difference between the sums of two diagonal containing the cell 
which is represented by x and y of the given array.

Note: Libraries iostream, vector, and string have been imported, and namespace std has been used.
*/

#include <bits/stdc++.h>

using namespace std;

int diagonalDiff(int arr[][1000], int row, int col, int x, int y){
        int d1 = 0, d2 = 0;

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
		        if( j == i + (y-x))
				d1 += arr[i][j];

		        if( i +j == (x+y))	
				d2 += arr[i][j];
		}
	}

	return abs(d1 - d2);
}

int main()
{
	int arr[][1000] = {{55,85,47,58},{31,4,60,67},{94,69,71,73},{51,62,64,90}};

        cout << diagonalDiff(arr,4,4,1,2);

	return 0;
}
