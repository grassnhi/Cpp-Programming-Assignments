/*
Mô tả tiếng Việt:

Hiện thực hàm int* flatten(int** matrix, int r, int c) trả về một mảng một chiều được “làm phẳng” từ mảng hai chiều có kích thước r x c (bằng cách nối các hàng của mảng hai chiều lại với nhau). 

Đầu vào: Mảng hai chiều có kích thước r x c.

Đầu ra: Mảng một chiều sau khi được “làm phẳng” từ mảng hai chiều đầu vào.

English version:

Implement the function int* flatten(int** matrix, int r, int c) tht returns a one-dimensional array flatten from a two-dimensional matrix of size r x c (by concating all the matrix rows).

Input: The two-dimensional matrix of size r x c

Output: The one-dimensional array flatten from the previous two-dimensional matrix.

For example:

Test	Input	Result
1
2 3
1 2 3
4 5 6
1 2 3 4 5 6
2
2 3
1 2 3
4 0 0
1 2 3 4 0 0
3
3 3
1 2 3
4 5 6
2 9 -99
1 2 3 4 5 6 2 9 -99
4
3 4
1 2 3 4
4 5 6 0
-1 8 8 100
1 2 3 4 4 5 6 0 -1 8 8 100
5
4 4
1 2 4 4
4 5 3 0
2 5 1 6
7 7 8 4
1 2 4 4 4 5 3 0 2 5 1 6 7 7 8 4
1
4 1
1
4
2
3
1 4 2 3
7
1 4
1 2 4 4
1 2 4 4

*/

int* flatten(int** matrix, int r, int c) {
    //TODO
    int* arr = new int[r * c];
    
    int index = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            *(arr + index) = *(*(matrix + i) + j);
            index++;
        }
    }
    
    return arr;
}