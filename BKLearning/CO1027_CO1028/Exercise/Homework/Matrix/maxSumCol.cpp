/*
Given a two-dimensional array whose each element is integer, its size is M x N.

Implement the following function: int findMaxColumn(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows 
and its number of columns. 

Find the index of the column which has the greatest sum of all elements on it.

Note: The first column of the given array is numbered by 0. 
If there are more than one column whose sum is the greatest, choose the column with the greatest index.

Note: Libraries iostream and climits have been imported, and namespace std has been used.
*/

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int findMaxColumn(int arr[][1000], int row, int col)
{
	int maxSum = -1, idx = -1;

	for (int i = 0; i < col; i++) {
		int sum = 0;

		for (int j = 0; j < row; j++) {
			sum += arr[j][i];
		}

		if (sum >= maxSum) {
			maxSum = sum;
			idx = i;
		}
	}

	return idx;
}

int main()
{

	int arr[][1000] = {{-92,78,-2,-58,-37},{44,-4,30,-69,22}};

    cout << findMaxColumn(arr, 2,5);

	return 0;
}
