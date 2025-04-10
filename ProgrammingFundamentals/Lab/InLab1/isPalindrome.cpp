/*
[Tiếng Việt]

Một chuỗi được gọi là palindrome nếu chuỗi đó giống với chuỗi được đảo ngược từ chính nó. Ví dụ: “eye”, “noon”, “abcba”...

Hãy viết hàm kiểm tra xem một chuỗi có là palindrome hay không?

Đầu vào:

const char* str: chuỗi cần kiểm tra palindrome. str chỉ bao gồm chữ cái thường
Đầu ra:

bool: true nếu chuỗi str là palindrome, ngược lại false


[English]

A string is a palindrome if it reads the same forward and backward. For example: "eye", "noon", "abcba", ...

Write a function to check if a given string is a palindrome

Input: 

const char* str: the string to be checked. str only contains lowercase letters
Output:

bool: true if str is a palindrome, false otherwise
*/

#include <iostream>
using namespace std;

bool isPalindrome(const char* str) {
    int left = 0;
    int right = 0;

    // Tìm độ dài chuỗi
    while (str[right] != '\0') {
        right++;
    }
    right--; // giảm 1 để trỏ vào ký tự cuối

    // So sánh từ 2 đầu
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Không khớp => không phải palindrome
        }
        left++;
        right--;
    }
    return true; // Nếu duyệt hết mà không sai thì là palindrome
}

bool isPalindrome_NHI(const char* str) {
    // Write your code here
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    int start = 0;
    int end = len - 1;
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    const char* str1 = "abba";
    cout << isPalindrome(str1) << endl; // Output: 1 (true)

    const char* str2 = "axz";
    cout << isPalindrome(str2) << endl; // Output: 0 (false)

    return 0;
}
