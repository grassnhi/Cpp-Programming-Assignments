/*
[Tiếng Việt]

Hoàn thành hàm recursiveSum sử dụng đệ quy để tính và trả về tổng các phần tử trong một mảng

Đầu vào:

int arr[]: Mảng chứa các số nguyên cần tính tổng.
int size: Số lượng phần tử trong mảng.
Đầu ra: int - Kết quả là tổng các phần tử trong mảng cho trước.

Lưu ý: Sinh viên không được sử dụng các từ khoá sau, kể cả trong tên biến và comment: include, for, while, goto

--------------------------------------------------------------------------------------

[English]

Complete the function recursiveSum using recursion to calculate and return the sum of all elements in an array.

Inputs:

int arr[]: An array containing integers to be summed.
int size: The size of the array.
Output: int - the result is the sum of the elements in the given array.

Note: Students are not allowed to use the following keywords, including in variable names or comments: include, for, while, goto.

 

For example:

Test	Result
int arr[] = {1,2,3,4,5};
int size = 5;
cout << recursiveSum(arr, size);
15
int arr[] = {10, -10, 20, -20, 30, -30};
int size = sizeof(arr) / sizeof(int);
cout << recursiveSum(arr, size);
0

*/

int recursiveSum(int arr[], int size) {
    // TODO
    if (size == 0) return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}