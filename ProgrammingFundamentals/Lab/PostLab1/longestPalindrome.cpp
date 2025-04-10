/*
[Tiếng Việt]

 

Viết chương trình đọc vào chuỗi s từ bàn phím, tìm và trả về chuỗi con có tính chất đối xứng dài nhất có trong s.

Đầu vào:

Chuỗi s.

Đầu ra:

Chuỗi con có tính chất đối xứng dài nhất có trong s. Trong trường hợp có nhiều chuỗi con dài nhất có cùng độ dài, trả về chuỗi con có vị trí bắt đầu nhỏ nhất.

 

 

[English ]

 

Write a program read an s string from keyboard, find and return the longest symetrical sub-string of s.

Input:

String s.

Output:

The longest symmetrical sub-string from s. In case where there are more than one highest string, return the string with the smallest starting character index.

 
*/

#include <iostream>
#include <string>
using namespace std;

void expand(const string& s, int left, int right, int& start, int& maxlen){
    int n = s.length();
    while(left >= 0 && right <= n && s[left] == s[right]){
        if(right - left + 1 > maxlen){
            maxlen = right - left + 1;
            start = left;
        }
        left--;
        right++;
    }
}

string longestPalindrome(string s){
    if(s.length() == 0){
        return "";
    }
    int start = 0;
    int maxlen = 1;
    for(int i = 0; i < s.length(); i++){
        expand(s, i, i, start, maxlen);
        expand(s, i, i+1, start, maxlen);
    }
    return s.substr(start, maxlen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
