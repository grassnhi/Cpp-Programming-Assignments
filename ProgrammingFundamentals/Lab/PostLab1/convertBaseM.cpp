/*
[Tiếng Việt]

Cho hai số tự nhiên n và m. Hãy viết một hàm tính toán và trả về giá trị của n trong hệ m phân, biết giá trị m thuộc {2, 4, 8}. Sinh viên cần thay đổi tham số m để có giá trị mặc định là 2 trong định nghĩa hàm.

Đầu vào: 

int n: số tự nhiên n cần được chuyển đổi sang hệ m phân

int m: hệ cơ số cần chuyển đổi. m phải có đối số mặc định là 2 khi định nghĩa hàm.

Đầu ra:

int: giá trị của n trong hệ m phân

Chú ý: đầu vào sẽ đảm bảo giá trị trả về không bị tràn số

 

[English]

Given two natural numbers n and m. Write a function that converts n to base m and returns that value, given that m is in {2, 4, 8}. Student must provide a default argument of value 2 for the second parameter(m).

Input:

int n: a natural number n that needs to be converted

int m: the new base which n is converted to. The default argument of this parameter must be 2 when defining the function.

Output:

int: the value of n in base m

Note: the input guarantees that the return value will not cause integer overflow
*/

#include <iostream>

using namespace std;

int convertToBaseM(int n, int m = 2) { 
    int result = 0, place = 1; 

    while (n > 0) {
        int remainder = n % m; // Lấy phần dư
        result += remainder * place; // Ghép phần dư vào kết quả
        place *= 10; // Tăng giá trị hàng lên 10 lần
        n /= m; // Chia n cho m để tiếp tục xử lý
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    cout << convertToBaseM(n, 4) << '\n';
    cout << convertToBaseM(n, 8) << '\n';
    cout << convertToBaseM(n) << '\n';

    return 0;
}
