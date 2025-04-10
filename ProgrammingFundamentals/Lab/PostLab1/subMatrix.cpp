/*

Mô tả tiếng Việt:

Cho mảng 2 chiều chứa các số nguyên, kích thước M x N.

Hiện thực hàm:

int subMatrix(int arr[][1000], int row, int col);
Trong đó; arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng. Một mảng con kích thước 2x2 thuộc mảng đã cho được gọi là HN4 nếu tổng tất cả các phần tử trong nó là một số lẻ. Tìm số mảng con HN4 trong mảng đã cho.

Ghi chú: (Các) thư viện iostream, vector và string đã được khai báo, và namespace std đã được sử dụng.

English version:

Given a two-dimensional array whose each element is integer, its size is M x N.

Implement the following function:

int subMatrix(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. A sub-array whose size is 2x2 is called as HN4 if the sum of all elements of it is an odd number. Find the number of sub-array of the given array.

Note: Libraries iostream, vector, and string have been imported, and namespace std has been used.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int subMatrix(int arr[][1000], int row, int col) {
    int count = 0;

    // Duyệt qua tất cả các ma trận con 2x2
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < col - 1; j++) {
            int sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            if (sum % 2 != 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int arr1[][1000] = {
        {66,16,71},
        {25,81,61},
        {2,10,34}
    };
    cout << subMatrix(arr1, 3, 3) << endl; // Output: 1

    int arr2[][1000] = {
        {44,45,89},
        {82,91,34},
        {83,87,33},
        {65,51,66}
    };
    cout << subMatrix(arr2, 4, 3) << endl; // Output: 4

    return 0;
}
