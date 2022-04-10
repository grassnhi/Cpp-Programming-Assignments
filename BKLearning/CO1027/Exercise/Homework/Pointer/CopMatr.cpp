/*
Implement the function 

    int** deepCopy(int** matrix, int r, int c) 
    
that return a copy of a matrix consisting of  r rows and c colmuns.

Input: 
    Pointer arr points to the one-dimensional array that needs to be copied.

Output: 
    Pointer newArr points to the destination array.

Note: 
    After finishing execution, the one-dimensional array that needs to be copied 
    and the destination array use the two distinct data memory.
*/

#include <iostream>

using namespace std;

int** deepCopy(int** matrix, int r, int c) {
    // TODO
    if( r <= 0 || c <= 0 ){
        return nullptr;
    }
    int **newMatrix = new int*[r];
    for(int i = 0; i < r; i++){
        newMatrix[i] = new int[c];
        for(int j = 0; j < c; j++){
            newMatrix[i][j] = matrix[i][j];
        }
    }
    return newMatrix;
}

int main(){
    int** m = new int*[2];

    m[0] = new int[2];

    m[0][0] = 1; 
    m[0][1] = 2;

    m[1] = new int[2]; 

    m[1][0] = 1;
    m[1][1] = 3;

    int** n = deepCopy(m, 2, 2);

    cout << n[0][0] << ' ' << n[0][1] << '\n' << n[1][0] << ' ' << n[1][1];
}