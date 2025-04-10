/*
Mô tả tiếng Việt:

Cho mảng 2 chiều chứa các số nguyên, kích thước N x N.

Hiện thực hàm:

bool isSymmetric(int arr[][1000], int row, int col);
Trong đó; arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng. Một ma trận được gọi là đối xứng nếu với mọi i, j; giá trị của phần tử ở hàng i, cột j luôn bằng giá trị của phần tử ở hàng j, cột i. Kiểm tra xem mảng này có phải là một ma trận đối xứng hay không; trả về true nếu mảng này là ma trận đối xứng; ngược lại, trả về false.

Ghi chú: (Các) thư viện iostream và string đã được khai báo, và namespace std đã được sử dụng.

English version:

Given a two-dimensional array whose each element is integer, its size is N x N.

Implement the following function:

bool isSymmetric(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. A matrix is called as symmetric matrix if for all i, j; the value of the element on row i, column j is equal to the value of the element on row j, column i. Check whether the given array is symmetric matrix or not; return true if it is, otherwise return false.

Note: Libraries iostream and string have been imported, and namespace std has been used.
*/

#include <iostream>
#include <string>
using namespace std;

bool isSymmetric(int arr[][1000], int row, int col) {
    // Kiểm tra điều kiện ma trận vuông
    if (row != col) return false;
    
    // Duyệt qua tất cả các cặp phần tử (i, j) với i < j để kiểm tra đối xứng
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (arr[i][j] != arr[j][i]) {
                return false; // Nếu không bằng nhau => không đối xứng
            }
        }
    }
    return true; // Tất cả các phần tử đối xứng
}

// Ví dụ kiểm tra:
int main() {
    int arr1[][1000] = {{1,4,6}, {4,5,3}, {6,3,9}};
    cout << isSymmetric(arr1, 3, 3) << endl; // Output: 1 (true)
    
    int arr2[][1000] = {{1,9,6}, {4,5,3}, {6,3,9}};
    cout << isSymmetric(arr2, 3, 3) << endl; // Output: 0 (false)
    
    return 0;
}
