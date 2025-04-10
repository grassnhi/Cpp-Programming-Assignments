/*
Mô tả tiếng Việt:

Cho mảng 2 chiều chứa các số nguyên, kích thước M x N.

Hiện thực hàm:

int diagonalDiff(int arr[][1000], int row, int col, int x, int y);
Trong đó; arr, row và col lần lượt là mảng 2 chiều, số hàng, số cột của mảng; x và y biểu thị ô có số hàng là x và số cột là y trong mảng đã cho (0≤x<row và 0≤y<col). Tổng của một đường chéo là tổng tất cả các phần tử nằm trên đường chéo đó. Tìm giá trị tuyệt đối của hiệu giữa hai đường chéo đi qua ô có số hàng x và số cột y.

Ghi chú: (Các) thư viện iostream, vector và string đã được khai báo, và namespace std đã được sử dụng.

English version:

Given a two-dimensional array whose each element is an integer, its size is M x N.

Implement the following function:

int diagonalDiff(int arr[][1000], int row, int col, int x, int y);
Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. ; x and y represent the cell whose index of the row is x and index of the column is y (0≤x<row và 0≤y<col). The sum of a diagonal is the sum of all elements on it. Find the absolute value of the difference between the sums of two diagonal containing the cell which is represented by x and y of the given array.

Note: Libraries iostream, vector, and string have been imported, and namespace std has been used.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Dùng cho hàm abs
using namespace std;

int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sumMain = 0, sumAnti = 0;

    // Tính tổng đường chéo chính (diagonal từ trên trái xuống dưới phải)
    int i = x, j = y;
    // Đi lên trên bên trái
    while (i >= 0 && j >= 0) {
        sumMain += arr[i][j];
        --i;
        --j;
    }
    // Đi xuống dưới bên phải
    i = x + 1;
    j = y + 1;
    while (i < row && j < col) {
        sumMain += arr[i][j];
        ++i;
        ++j;
    }

    // Tính tổng đường chéo phụ (diagonal từ trên phải xuống dưới trái)
    i = x;
    j = y;
    // Đi lên trên bên phải
    while (i >= 0 && j < col) {
        sumAnti += arr[i][j];
        --i;
        ++j;
    }
    // Đi xuống dưới bên trái
    i = x + 1;
    j = y - 1;
    while (i < row && j >= 0) {
        sumAnti += arr[i][j];
        ++i;
        --j;
    }

    // Trả về giá trị tuyệt đối của hiệu
    // return abs(sumMain - sumAnti);

    // Tính giá trị tuyệt đối của hiệu:
    int diff = sumMain - sumAnti;
    if (diff < 0)
        diff = -diff;

    return diff;
}

// Test ví dụ:
int main() {
    int arr1[][1000] = {{55,85,47,58},{31,4,60,67},{94,69,71,73},{51,62,64,90}};
    cout << diagonalDiff(arr1, 4, 4, 1, 2) << endl; // Output: 20

    int arr2[][1000] = {{88,72,65,37},{82,84,34,12},{74,46,88,44}};
    cout << diagonalDiff(arr2, 3, 4, 1, 0) << endl; // Output: 26

    return 0;
}
