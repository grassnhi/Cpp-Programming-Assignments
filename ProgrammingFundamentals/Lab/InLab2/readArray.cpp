/*
Mô tả tiếng Việt:

Hãy hiện thực hàm readArray() được khai báo như sau:

int** readArray()

Hàm này sẽ đọc dữ liệu cho một ma trận 2 chiều, mỗi chiều có 10 phần tử. Các phần tử của ma trận sẽ được nhập vào từ bàn phím (từ phần tử a[0][0] cho đến a[9][9]). Tuy nhiên nếu phần tử a[i][j] được nhập là 0 thì tất cả các phần tử còn lại trên hàng (a[i][k], j<k<10) đều được tự động gán là là 0, chương trình sẽ đọc tiếp phần tử a[i+1][0] từ bàn phím. Hàm readArray sẽ trả về một con trỏ tới mảng 2 chiều đã nhập này.

Đầu vào: Các phần tử có trong mảng 2 chiều, mỗi phần tử là một số nguyên dương có giá trị không vượt quá 1000.

Đầu ra: Con trỏ tới mảng 2 chiều vừa tạo

English version:

Implement the function readArray() that is declared as below syntax:

 

int** readArray()

The function reads a two-dimensional matrix each of which consists of 10 elements. These elements are entered from the keyboard (from a[0][0] to a[9][9]). If a[i][j] is assigned to 0, all remained element of the row (a[i][k], j<k<10) will automatically assigned to 0, and the function will continue to input the next-row element from the keyboard. Moreover, this function also returns a pointer which points to the two-dimensional matrix just entered.

Input:  The positive integer matrix's elements which not surpass 1000.

Output: The pointer that points to  the two-dimensional matrix just entered.

 




 

For example:

Test	Input	Result
1
1 2 3 4 5 6 7 8 9 10
0
1 0
2 0
3 0
4 5 0
6 7 0
8 0
9 0
10 11 12 13 14 0
1 2 3 4 5 6 7 8 9 10
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
3 0 0 0 0 0 0 0 0 0
4 5 0 0 0 0 0 0 0 0
6 7 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0 0
9 0 0 0 0 0 0 0 0 0
10 11 12 13 14 0 0 0 0 0
2
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

*/

int** readArray()
{
   //TODO
   const int ROWS = 10;
   const int COLS = 10;
   
   int** matrix = new int*[ROWS];
   for(int i = 0; i < ROWS; i++){
       matrix[i] = new int[COLS];
   }
   
   
   
   for(int i = 0; i < ROWS; i++){
       bool terminate = false;
       for(int j = 0; j < COLS; j++){
           if(!terminate){
               cin >> *(*(matrix + i) + j);
               if (*(*(matrix + i) + j) == 0) {
                   terminate = true;
                   for (int k = j + 1; k < COLS; ++k) {
                       *(*(matrix + i) + k) = 0;
                   }
               }
           }else{
               break;
           }
       }
   }
   
   return matrix;
}