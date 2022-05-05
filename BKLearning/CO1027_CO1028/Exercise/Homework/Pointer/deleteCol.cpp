/*
Given a dynamic two-dimensional array of size r x c. 
Implement the function 
        bool deleteCol(int**& matrix, int r, int c, int col) 
that can remove a column from the matrix.

Input: 
    The two-dimensional matrix of size r x c and the remove position col.

Output: 
    The two-dimensional matrix after removing the column.

Note: 
    If the final column of the matrix is removed, the function will return nullptr value 
    as well as deallocate the memory previously used by the matrix.
*/

bool deleteCol(int**& matrix, int r, int c, int col) {
    if ((r<=0 or c<=0) or (col >= c) or col<0){ 
        matrix=nullptr;
        delete []matrix;
        return 0;
    }else{
        if(c == 1) {
            matrix = nullptr;
            delete []matrix; 
            return 1;
        }else{
            for( int i=0 ; i < r ; i++){
                for( int j=col ; j < c ; j++){
                    matrix[i][j] = matrix[i][j+1];
                }
            }
            return 1;
        }
    }
}