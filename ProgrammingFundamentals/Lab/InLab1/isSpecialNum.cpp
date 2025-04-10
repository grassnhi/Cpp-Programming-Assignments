/*
[Tiếng Việt]

Một số tự nhiên n được gọi là đặc biệt khi và chỉ khi n là số nguyên tố và tổng các chữ số của n cũng là số nguyên tố. Viết hàm kiểm tra một số tự nhiên có đặc biệt hay không.

Đầu vào:

int n: số tự nhiên cần kiểm tra có phải số đặc biệt không
Đầu ra:

bool: trả về true nếu n là số đặc biệt, ngược lại trả về false


[English]

A natural number n is special if and only if n is a prime number and the sum of all the digits of n is also a prime number. Write a function that determines if a natural number is a special or not.

Input:

int n: a natural number n. 0 <= n <= 1000

Output:

bool: return true if n is special, return false otherwise

For example:
*/

#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số đặc biệt
bool isSpecialNumber(int n) {
    if (!isPrime(n)) return false;

    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    return isPrime(sum);
}
