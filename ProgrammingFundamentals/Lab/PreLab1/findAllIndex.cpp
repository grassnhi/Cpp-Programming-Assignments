/*
[Tiếng Việt ]

Hiện thực hàm findAllIndex(string s1, string s2) để in ra tất cả các vị trí xuất hiện của kí tự đầu tiên của chuỗi s2 trong chuỗi s1. Nếu không tìm thấy in ra -1. Các vị trí tìm thấy sẽ cách nhau một khoảng trắng, sau vị trí cuối cùng, không in thêm bất kỳ ký tự nào (kể cả khoảng trắng, dấu xuống hàng)


Gợi ý: Sử dụng hàm string::find trong thư viện <string>.

 

 

[English ]

Implement findAllIndex(string s1, string s2) to print all positions of the first character of string s2 in string s1. If not found, print -1. The found positions will be separated by a space, after the last position, do not print any more characters (including spaces, carriage returns)

Hint:  Use the string::find function in the <string> library.
*/

#include <iostream>
#include <string>
using namespace std;

void findAllIndex(string s1, string s2) {
    if (s2.empty()) {
        cout << -1;
        return;
    }
    
    char target = s2[0]; // Lấy ký tự đầu tiên của s2
    bool found = false;
    
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == target) {
            if (found) {
                cout << " ";
            }
            cout << i;
            found = true;
        }
    }
    
    if (!found) {
        cout << -1;
    }
}

int main() {
    string s1 = "Truong Dai Hoc Bach Khoa.";
    string s2 = "a";
    findAllIndex(s1, s2); // Output: 8 16 23
}
