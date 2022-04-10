/*
Implement the function int* flatten(int** matrix, int r, int c) tht returns a one-dimensional array flatten from a two-dimensional matrix of size r x c (by concating all the matrix rows).

Input: The two-dimensional matrix of size r x c

Output: The one-dimensional array flatten from the previous two-dimensional matrix.
*/




int* flatten(int** matrix, int r, int c){
    int *newMatrix = new int[r*c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            *(newMatrix + i * c + j) = matrix[i][j];
        }
    }
    return newMatrix;
}