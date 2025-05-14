/*
Mô tả tiếng Việt:

 

Cho một mảng động hai chiều matrix có kích thước r x c. Hiện thực hàm int** insertCol(int**& matrix, int r, int c, int* colArr, int col) tiến hành chèn mảng rowArr (có kích thước r) vào cột thứ col của matrix. 

Đầu vào: Mảng 2 chiều matrix có kích thước r x c, cột cần chèn colArr và vị trí chèn col.

Đầu ra: Mảng 2 chiều matrix sau khi được chèn, đầu ra phải được điều chỉnh trên biến matrix truyền vào.

 

English version:

Given a dynamic two-dimensional array of size r x c. Implement the function int** insertCol(int**& matrix, int r, int c, int* colArr, int col) that can insert the colArr array (with the size r) into the column position, col, of the matrix.

Input: The two-dimensional matrix of size r x c, the insert column rowArr and the insert position col.

Output: The two-dimensional matrix after insert.

 

 

 

For example:

Test	Input	Result
1
2 3
1 2 3
4 5 6
2
7 8
1 2 7 3
4 5 8 6

*/

int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    // TODO
    int** newM = new int*[r];
    for(int i = 0; i < r; i++){
        newM[i] = new int[c+1];
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j <= c; j++){
            if(j < col){
                newM[i][j] = matrix[i][j];
            }else if(j == col){
                newM[i][j] = colArr[i];
            }else{
                newM[i][j] = matrix[i][j-1];
            }
        }
    }
    
    // for (int i = 0; i < r; i++) {
    //     delete[] matrix[i];
    // }
    // delete[] matrix;

    matrix = newM;

    return matrix;
}

int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    // TODO
    int** newM = new int*[r];
    for(int i = 0; i < r; i++){
        *(newM + i) = new int[c + 1];
        for(int j = 0; j <= c; j++){
            if(j < col){
                *(*(newM + i) + j) = matrix[i][j];
            }else if(j == col){
                *(*(newM + i) + j) = colArr[i];
            }else{
                *(*(newM + i) + j) = matrix[i][j-1];
            }
        }
    }
    for(int i = 0; i < r; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = newM;
    return matrix;
}