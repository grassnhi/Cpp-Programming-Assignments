/*
Given a dynamic two-dimensional array of size r x c. 
Implement the function 
        int** insertCol(int**& matrix, int r, int c, int* colArr, int col) 
that can insert the colArr array (with the size r) into the column position, col, of the matrix.

Input: 
    The two-dimensional matrix of size r x c, the insert column rowArr and the insert position col.

Output: 
    The two-dimensional matrix after insert.
*/

#include <iostream>

using namespace std;

int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    // TODO
    int c1 = c + 1;
    int** newArr = new int*[r];
    
    for ( int i = 0; i < r; i++ )
        newArr[i] = new int[c1];
    
    for ( int i = 0; i < r; i++ )
        for ( int j = 0; j < col; j++ )
            newArr[i][j] = matrix[i][j];
    
    for ( int i = 0; i < r; i++ )
        newArr[i][col] = colArr[i];
    
    for ( int i = 0; i < r; i++ )
        for ( int j = col+1; j < c1; j++ )
            newArr[i][j] = matrix[i][j-1];
    matrix = newArr;   
}

int main(){
    
}