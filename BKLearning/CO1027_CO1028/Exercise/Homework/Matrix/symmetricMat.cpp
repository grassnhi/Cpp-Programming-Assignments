/*
Given a two-dimensional array whose each element is integer, its size is N x N.

Implement the following function:
        bool isSymmetric(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and 
its number of columns. A matrix is called as symmetric matrix if for all i, j; 
the value of the element on row i, column j is equal to the value of the element on row j, column i.

Check whether the given array is symmetric matrix or not; return true if it is, otherwise return false.

Note: Libraries iostream and string have been imported, and namespace std has been used.
*/

#include<iostream>
using namespace std; 

bool isSymmetric(int arr[][1000], int row, int col){
   
    bool symmetr = true;

    for(int i= 0; i< row; i++){
	    for (int j = i+1; j < row; j++){
	   	    if(arr[i][j] != arr[j][i]){
	      	 	symmetr = false;
	       		break;
	 		}
  	    }

	    if(!symmetr)
	    	break;
    }

    return symmetr;	      
}

int main( ){
    int arr[][1000] = {{1,9,6}, {4,5,3}, {6,3,9}};

    cout << isSymmetric(arr,3,3);

    return 0;
}
