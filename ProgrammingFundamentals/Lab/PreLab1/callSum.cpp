/*
Viết hàm void calSum(string fileName) để tính tổng của các số nguyên không âm được đọc vào từ một file đuôi txt (các số nằm trên 1 hàng phân cách với nhau bằng một khoảng trắng).


Đầu vào:

Biến "fileName" là tên file dữ liệu chứa các số nguyên không âm (các số nằm trên 1 hàng phân cách với nhau bằng một khoảng trắng).

Đầu ra:

Một số nguyên là tổng của các số nguyên đầu vào.



Write a function void calSum(string fileName) to calculate the sum of non-negative integers read from a txt file (numbers in a row separated by a space).

Input:

The variable "fileName" is a data file name containing non-negative integers (numbers in 1 row separated by a space).

Output:

An integer is the sum of the input integers.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void calSum(string fileName) {
    ifstream file(fileName);
    int sum = 0;
    int num;

    if (file.is_open()) {
        while (file >> num) { // Đọc từng số nguyên trực tiếp từ file
            sum += num;
        }
        cout << sum << endl;
        file.close();
    } else {
        cout << "Cannot open file" << endl;
    }
}
