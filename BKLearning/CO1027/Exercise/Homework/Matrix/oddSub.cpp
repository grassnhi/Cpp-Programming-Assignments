/*
Given a two-dimensional array whose each element is integer, its size is M x N.

Implement the following function:
            int subMatrix(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. 
A sub-array whose size is 2x2 is called as HN4 if the sum of all elements of it is an odd number. 
Find the number of sub-array of the given array.

Note: 
    Libraries iostream, vector, and string have been imported, and namespace std has been used.
*/
#include <iostream>

using namespace std;

int subMatrix(int arr[][1000], int row, int col) {
    int sum = 0, count = 0;
    for(int i = 0; i < row -1; i++){
        for(int j = 0; j < col -1; j++){
            sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            if(sum % 2 != 0){
                count++;
            }
            sum = 0;
        }
    }
    return count;
}

int main(){
    int arr[][1000] = {{66,16,71},{25,81,61},{2,10,34}};
    
    cout << subMatrix(arr,3, 3);
}