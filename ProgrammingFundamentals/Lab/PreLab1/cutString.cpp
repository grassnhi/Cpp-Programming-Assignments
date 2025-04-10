/*
[Tiếng Việt]
Hiện thực hàm cutString(string s, int index) để in ra chuỗi con của chuỗi s từ vị trí index đến hết (index tính từ 0). Nếu index không hợp lệ cho chuỗi thì không in ra gì cả.

Gợi ý : Sử dụng hàm string::substr trong thư viện <string>. 

[English ]
Implement the function cutString(string s, int index) to print the substring of string s from index position to the end (index from 0). If the index is invalid for the string, the function will not print anything.

Hint:  Use the string::substr function in the <string> library.
*/
#include <iostream>
#include <string>
using namespace std;

void cutString(string s, int index) {
    if (index >= 0 && index < s.length()) {
        cout << s.substr(index) << endl;
    }
    // Nếu index không hợp lệ, không in gì cả
}

int main() {
    string s = "Truong Dai Hoc Bach Khoa.";
    cutString(s, 7); // Output: Dai Hoc Bach Khoa.
    
    cutString(s, 25); // Index invalid → Không in gì

    return 0;
}
