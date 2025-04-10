/*
Mô tả tiếng Việt:

Cho mảng 2 chiều chứa các số nguyên, kích thước M x N.

Hiện thực hàm:

int findMaxColumn(int arr[][1000], int row, int col);
Trong đó; arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng. Tìm chỉ số của cột có tổng tất cả các phần tử lớn nhất.

Lưu ý: Cột đầu tiên được đánh chỉ số 0. Nếu có nhiều hơn một cột có tổng lớn nhất, ta chọn cột có chỉ số lớn nhất.

Ghi chú: (Các) thư viện iostream và climits đã được khai báo, và namespace std đã được sử dụng.

English version:

Given a two-dimensional array whose each element is integer, its size is M x N.

Implement the following function:

int findMaxColumn(int arr[][1000], int row, int col);
Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. Find the index of the column which has the greatest sum of all elements on it.

Note: The first column of the given array is numbered by 0. If there are more than one column whose sum is the greatest, choose the column with the greatest index.

Note: Libraries iostream and climits have been imported, and namespace std has been used.

*/

#include <iostream>
#include <climits>
using namespace std;

int findMaxColumn(int arr[][1000], int row, int col) {
    int maxSum = INT_MIN;
    int maxIndex = -1;
    
    // Duyệt từng cột
    for (int j = 0; j < col; ++j) {
        int sum = 0;
        for (int i = 0; i < row; ++i) {
            sum += arr[i][j]; // Cộng các phần tử trên cột j
        }
        // So sánh tổng hiện tại với maxSum
        if (sum >= maxSum ) {
            maxSum = sum;
            maxIndex = j;
        }
    }
    
    return maxIndex;
}

// Ví dụ kiểm tra:
int main() {
    int arr1[][1000] = {{-44,64,-6},{87,92,-19},{-92,53,-38},{-39,-92,21}};
    cout << findMaxColumn(arr1, 4, 3) << endl; // Output: 1
    
    int arr2[][1000] = {{-92,78,-2,-58,-37},{44,-4,30,-69,22}};
    cout << findMaxColumn(arr2, 2, 5) << endl; // Output: 1
    
    return 0;
}
