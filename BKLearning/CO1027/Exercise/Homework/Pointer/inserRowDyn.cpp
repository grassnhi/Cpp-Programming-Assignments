/*
Given a dynamic two-dimensional array of size r x c. 

Implement the function 
        void insertRow(int**& matrix, int r, int c, int* rowArr, int row) 
that can insert the rowArr array (with the size c) into the row position, row, of the matrix.

Input: 
    The two-dimensional matrix of size r x c, the insert row rowArr and the insert position row.

Output: 
    The two-dimensional matrix after insert.
*/


void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    
    int newR = r;
    r++;

    for(int i = newR - 1; i >= row; i--){
        matrix[i+1] = matrix[i];
    }

    matrix[row] = rowArr; 
}

void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // TODO
    int r1 = r + 1;
    int** newArr = new int*[r1];
    
    for ( int i = 0; i < r1; i++ )
        newArr[i] = new int[c];
    
    for ( int i = 0; i < row; i++ )
        for ( int j = 0; j < c; j++ )
            newArr[i][j] = matrix[i][j];
    
    for ( int j = 0; j < c; j++ )
        newArr[row][j] = rowArr[j];
    
    for ( int i = row + 1; i < r1; i++ )
        for ( int j = 0; j < c; j++ )
            newArr[i][j] = matrix[i-1][j];
    matrix = newArr;    
}