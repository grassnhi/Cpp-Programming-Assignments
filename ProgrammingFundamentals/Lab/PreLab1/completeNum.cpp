/*
[Tiếng Việt]

Viết hàm bool completeNum(int N) để kiểm tra xem số nguyên dương N có phải là một số hoàn thiện hay không. N là một số hoàn thiện nếu N bằng tổng tất cả ước số nguyên dương (không bao gồm chính nó) của nó.

Đầu vào: 

int N: số nguyên dương N cần kiểm tra
Đầu ra:

bool: trả về true nếu N là số hoàn thiện, ngược lại trả về false


[English]

Write the function bool completeNum(int N) that checks if a positive integer N is a complete number. N is a complete number if and only if N is equal to the sum of all of its positive divisors (excluding itself)

Input: 

int N: positive integer N to be checked
Output:

bool: return true if N is a complete number, otherwise return false
*/

#include <iostream>
using namespace std;

bool completeNum(int N) {
    int sum = 0;
    for (int i = 1; i <= N / 2; ++i) { // Duyệt đến N/2 thôi, vì không cần xét số lớn hơn N/2
        if (N % i == 0) { // Nếu i là ước số của N
            sum += i;
        }
    }
    return sum == N;
}

int main() {
    int N;
    cin >> N;
    if (completeNum(N)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
