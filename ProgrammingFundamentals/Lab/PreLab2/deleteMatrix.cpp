/*
Mô tả tiếng Việt:

Hãy hiện thực hàm void deleteMatrix(int**& matrix, int r) thực hiện giải phóng ô nhớ cho một mảng động 2 chiều có r hàng. matrix được gán bằng giá trị NULL sau khi thực hiện hàm.

Đầu vào: Mảng động hai chiều matrix có số hàng r cần giải phóng ô nhớ.

English version:

Implement the function void deleteMatrix(int**& matrix, int r) that can free memory for a dynamic two-dimensional array consisting of r rows. matrix should be set to NULL after function's execution.

Input: The dynamic two-dimensional array, matrix, consists of r rows.

For example:

Test	Input	Result
1
2 2
1 1
1 1
SUCCESSFUL

*/

void deleteMatrix(int**& matrix, int r) {
    // TODO;
    for(int i = 0; i < r; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}