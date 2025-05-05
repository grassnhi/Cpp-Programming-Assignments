/*
Mô tả tiếng Việt:
Cho một mảng động hai chiều matrix có kích thước r x c. Hiện thực hàm bool deleteRow(int**& matrix, int r, int c, int row) tiến hành xóa hàng thứ row của matrix. 
Đầu vào: Mảng 2 chiều matrix có kích thước r x c và vị trí hàng cần xóa row.

Đầu ra: Mảng 2 chiều matrix sau khi xóa hàng và kết quả xóa thành công hay không.

Lưu ý: Nếu mảng hai chiều xóa đi hàng cuối cùng, mà trận được truyền vào hàm sẽ trả về giá trị nullptr và đồng thời giải phóng toán bộ vùng nhớ của mảng hai chiều được cấp phát trước đó.

English version:

Given a dynamic two-dimensional array of size r x c. Implement the function bool deleteRow(int**& matrix, int r, int c, int row) that can remove a row from the matrix.

Input: The two-dimensional matrix of size r x c and the remove position row.

Output: The two-dimensional matrix after removing the row.

Note: If the final row of the matrix is removed, the matrix parameter will return nullptr value as well as deallocate the memory previously used by the matrix.




For example:

Test	Input	Result
1
2 3
1 2 3
4 5 6
0
4 5 6

*/

bool deleteRow(int**& matrix, int r, int c, int row) {
    // TODO
    if(r <= 0 || c <= 0 || row < 0 || row >= r){
        return false;
    }
    
    if (r == 1) {
        delete[] matrix[0];  
        delete[] matrix; 
        matrix = nullptr;
        return true; 
    }

    int** newM = new int*[r-1];
    for(int i = 0; i < r-1; i++){
        newM[i] = new int[c];
    }
    
    for(int i = 0; i < r; i++){
        if(i < row){
            newM[i] = matrix[i];
        }else if(i > row){
            newM[i-1] = matrix[i];
        }
    }

    matrix = newM;
    
    return true;
}