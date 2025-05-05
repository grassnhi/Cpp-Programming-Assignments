/*
Mô tả tiếng Việt:

Hãy hiện thực hàm int** deepCopy(int** matrix, int r, int c) trả về một bản sao của matrix gồm r hàng và n cột. 

Đầu vào: Con trỏ matrix trỏ đến mảng hai chiều có kích thước r x c.

Đầu ra: Con trỏ trỏ đến mảng hai chiều được sao chép.

Lưu ý: sau thực thi, con trỏ trả về phải trỏ đến vùng nhớ được cấp phát mới và khi matrix truyền vào có kích thước 0, hàm trả về nullptr.

English version:

Implement the function int** deepCopy(int** matrix, int r, int c) that return a copy of a matrix consisting of  r rows and c colmuns.


Input: Pointer arr points to the one-dimensional array that needs to be copied.

Output: Pointer newArr points to the destination array.

Note: After finishing execution, the one-dimensional array that needs to be copied and the destination array use the two distinct data memory.


For example:

Test	Result
int** m = new int*[2];
m[0] = new int[2]; m[0][0] = 1; m[0][1] = 2;
m[1] = new int[2]; m[1][0] = 1; m[1][1] = 3;
int** n = deepCopy(m, 2, 2);
cout << n[0][0] << ' ' << n[0][1] << '\n' << n[1][0] << ' ' << n[1][1];
1 2
1 3

*/

int** deepCopy(int** matrix, int r, int c) {
    // TODO
    if(c <= 0 || r <= 0){
        return nullptr;
    }
    
    int** newM = new int*[r];
    for(int i = 0; i < r; i++){
        newM[i] = new int[c];
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            newM[i][j] = matrix[i][j];
        }
    }
    
    return newM;
}