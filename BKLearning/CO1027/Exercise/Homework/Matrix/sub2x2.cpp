/*
Given a two-dimensional array whose each element is integer, its size is M x N.

Implement the following function:
        int subMatrix(int arr[][1000], int row, int col);
Where   arr, row and col are the given two-dimensional array, 
        its number of rows and its number of columns. 
        
A sub-array whose size is 2x2 is called as HN4 if the sum of all elements of it is an odd number. 
Find the number of sub-array of the given array.

Note: Libraries iostream, vector, and string have been imported, and namespace std has been used.
*/

#include <iostream>
#include <string>

using namespace std

int main(){
    int arr[][1000] = {{66,16,71},{25,81,61},{2,10,34}};

    cout << subMatrix(arr,3, 3);

    return 0;
}