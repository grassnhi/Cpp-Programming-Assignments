/*
[Tiếng Việt ]

Cho một số thập phân dương làm đầu vào, chúng ta cần triển khai hàm

 

 

long int decimalToBinary(int decimal_number){}
 

để chuyển đổi số thập phân dương đã cho thành số nhị phân tương đương.

Xin lưu ý rằng bạn không thể sử dụng từ khóa for, while, goto (ngay cả trong tên biến, comment).

 

Đối với bài tập này, chúng ta có #include <iostream> và sử dụng namespace std;

 

[English ]

Given a positive decimal number as input, we need to implement function

 

long int decimalToBinary(int decimal_number){}
 

to convert the given positive decimal number into equivalent binary number.

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream> and using namespace std;
*/

#include <iostream>
using namespace std;

long int decimalToBinary(int decimal_number) {
    if (decimal_number == 0)
        return 0;
    return decimalToBinary(decimal_number / 2) * 10 + (decimal_number % 2);
}

int main() {
    cout << decimalToBinary(20); // Output: 10100
    return 0;
}
