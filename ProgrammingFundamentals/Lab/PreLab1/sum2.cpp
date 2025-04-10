/*
[Tiếng Việt]

Viết hàm sum2 để tính tổng giá trị các phần tử trong mảng số nguyên.

Tham số:

int* array: mảng số nguyên
int size: số phần tử trong mảng
int& result: tham số để lưu kết quả cuối cùng sau khi tính toán


[English]

Write the function sum2 that calculates the total of all elements in an integer array

Parameters:

int* array: an array of integers
int size: the number of elements in the array
int& result: a parameter to return the calculated value to the caller
*/

#include <iostream>

using namespace std;

void sum2(int* array, int size, int& result) {
    result = 0; // Khởi tạo kết quả
    for (int i = 0; i < size; ++i) {
        result += array[i]; // Cộng dồn từng phần tử
    }
}

int main() {
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
    int result;
    sum2(array, size, result);
    cout << result << endl;

    delete[] array; // Giải phóng bộ nhớ
    return 0;
}
