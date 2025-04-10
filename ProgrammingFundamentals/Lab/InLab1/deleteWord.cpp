/*
[Tiếng Việt ]

Hiện thực hàm deleteWord(string s, string s1) với chức năng in ra chuỗi s sau khi xóa tất cả các chuỗi s1 có trong s.



[English ]

Implement deleteWord(string s, string s1) function with function to print string s after deleting all strings s1 contained in s.
*/

#include <iostream>
#include <string>
using namespace std;

void deleteWord(string s, string s1) {
    int pos = s.find(s1);
    while (pos != -1) { // lặp đến khi không còn s1 trong s
        s.erase(pos, s1.length());
        pos = s.find(s1); // tìm lại sau khi xóa
    }
    cout << s;
}

int main() {
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai ";
    deleteWord(s, s1); // Output: Truong DHoc Bach Khoa, SGon
}
