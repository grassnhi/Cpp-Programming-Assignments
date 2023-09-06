/*
Implement the function 
        void deleteMatrix(int**& matrix, int r) 
that can free memory for a dynamic two-dimensional array consisting of r rows. 
matrix should be set to NULL after function's execution.

Input: 
    The dynamic two-dimensional array, matrix, consists of r rows.
*/

#include <iostream>

using namespace std;

void deleteMatrix(int**& matrix, int r) {
    // TODO;
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }

    delete []matrix;
    
    matrix = NULL;
}