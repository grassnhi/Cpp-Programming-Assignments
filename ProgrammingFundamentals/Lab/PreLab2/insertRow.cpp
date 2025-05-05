/*
Mô tả tiếng Việt:
Cho một mảng động hai chiều matrix có kích thước r x c. Hiện thực hàm void insertRow(int**& matrix, int r, int c, int* rowArr, int row) tiến hành chèn mảng rowArr (có kích thước c) vào hàng thứ row của mảng matrix.
Đầu vào: Mảng 2 chiều matrix có kích thước r x c, hàng cần chèn rowArr và vị trí chèn row.

Đầu ra: Mảng 2 chiều matrix sau khi được chèn.

English version:

Given a dynamic two-dimensional array of size r x c. Implement the function void insertRow(int**& matrix, int r, int c, int* rowArr, int row) that can insert the rowArr array (with the size c) into the row position, row, of the matrix.

Input: The two-dimensional matrix of size r x c, the insert row rowArr and the insert position row.

Output: The two-dimensional matrix after insert.


For example:

Test	Input	Result
1
2 3
1 2 3
4 5 6
2
7 8 9
1 2 3
4 5 6
7 8 9

*/

void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // TODO
    int** newM = new int*[r+1];
    for(int i = 0; i <= r; i++){
        newM[i] = new int[c];
    }
    for(int i = 0; i <= r; i++){
        if(i < row){
            newM[i] = matrix[i];
        }else if(i == row){
            newM[i] = rowArr;
        }else{
            newM[i] = matrix[i-1];
        }
    }
    
    matrix = newM;
}