/*
Mô tả tiếng Việt:

Chuyển vị của một ma trận 2 chiều là một phần quan trọng trong việc tính toán trên ma trận nói riêng và đại số tuyến tính nói chung.

Gọi B là ma trận sau khi chuyển vị của ma trận A thì ma trận B có tính chất là b[i][j] = a[j][i].

Hãy viết hàm int** transposeMatrix(int** matrix, int r, int c) thực hiện phép chuyển vị trên ma trận đã được đề cập bên trên.

Đầu vào:

Con trỏ tới mảng 2 chiều. Mỗi phần tử trong mảng 2 chiều có giá trị trong khoảng (-1000; 1000).
Kích thước mảng 2 chiều là 1 cặp số dương r, c. Trong đó: r là số hàng của ma trận, c là số cột của ma trận. Giá trị n không vượt quá 1000.
Đầu ra: Con trỏ trỏ tới mảng hai chiều sau khi được chuyển vị. trong trường hợp ma trận đầu vào rỗng, trả về con trỏ null.

English version:
Transposition of a two-dimensional matrix is an important term for matrix calculations in particular and linear algebra in general.
A matrix B transposed from a matrix A that satisfied the following formula b[i][j] = a[j][i].
Implement the function int** transposeMatrix(int** matrix, int r, int c) that perform the transposition of the matrix mentioned above.
Input:

The pointer that points to a two-dimensional matrix each of whose elements is in the range (-1000; 1000).
The size of the matrix consists of the number of row r and the number of column n.
Output: The pointer that points to transposed two-dimensional matrix. If the input matrix is empty, return the null pointer.

For example:

Test	Input	Result
1
2 2
1 2
3 4
1 3
2 4
2
1 1
1
1
3
3 3
1 2 3
4 5 6
7 8 9
1 4 7
2 5 8
3 6 9
4
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
5
2 2
10 12
14 16
10 14
12 16
6
2 3
1 2 3
4 5 6
1 4
2 5
3 6
7
1 3
1 2 3
1
2
3
8
3 1
1
1
2
1 1 2
9
0 0
NULL
10
1 2
1 2
1
2

*/

int** transposeMatrix(int** matrix, int r, int c) {
    // TODO
    if(r == 0 || c == 0){
        return nullptr;
    }
    
    int** transM = new int*[c];
    for(int i = 0; i < c; i++){
        transM[i] = new int[r];
    }
    
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            transM[i][j] = matrix[j][i];
        }
    }
    
    return transM;
}