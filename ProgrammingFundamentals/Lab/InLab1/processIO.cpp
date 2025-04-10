/*
Viết hàm void process(string fileName) đọc một file đuôi txt, dòng đầu gồm 2 số N và M cách nhau bởi 1 khoảng trắng.

N dòng theo sau, mỗi dòng gồm M số thực cách nhau bởi 1 khoảng trắng.

Trả về giá trị lớn nhất của mỗi dòng và giá trị lớn nhất trong tất cả các số.
Các thư viện đã được include: iostream, fstream, string.

Đầu vào:
Biến "fileName" là tên file chứa dữ liệu đầu vào.

Đầu ra:

Giá trị lớn nhất của mỗi dòng và giá trị lớn nhất của tất cả các số, cách nhau bởi ký tự khoảng trắng.



Write a function void process(string fileName) that reads a txt file, the first line consists of 2 numbers N and M separated by a space.

N lines follow, each containing M real numbers separated by 1 space.

Print the maximum value of each line and the maximum value of all numbers.

Included libraries: iostream, fstream, string.

Input:

The variable "fileName" is the name of the file containing the input data.
Output:
The maximum value of each line and the maximum value of all numbers, separated by a space character.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void process(string fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        int N, M;
        file >> N >> M;
        double globalMax = numeric_limits<double>::lowest();
        for (int i = 0; i < N; i++) {
            double localMax = numeric_limits<double>::lowest();
            for (int j = 0; j < M; j++) {
                double value;
                file >> value;
                if (value > localMax) {
                    localMax = value;
                }
            }
            cout << localMax << " ";
            if (localMax > globalMax) {
                globalMax = localMax;
            }
        }
        cout << globalMax;
        file.close();
    }
}

void process_NHI(string fileName)   {
    // TODO
    ifstream file(fileName);
    if (file.is_open()) {
        int N, M;
        file >> N >> M;
        double globalMax = -1e18;
        for (int i = 0; i < N; i++) {
            double localMax = -1e18;
            for (int j = 0; j < M; j++) {
                double value;
                file >> value;
                if (value > localMax) {
                    localMax = value;
                }
            }
            cout << localMax << " ";
            if (localMax > globalMax) {
                globalMax = localMax;
            }
        }
        cout << globalMax;
        file.close();
    }
}