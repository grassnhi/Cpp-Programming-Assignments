/*
[Tiếng Việt]

Palindrome là một chuỗi (string) mà nếu đảo ngược thứ tự các ký tự trong chuỗi ta vẫn có được chuỗi cũ. Ví dụ : “ABCBA”, “RADAR”, “otto”, “i am ma i”, “C”.

Hàm palindrome kiểm tra một chuỗi có là Palindrome đã được cho phía dưới.


a/ Viết một chương trình C++ sử dụng vòng lặp while đọc vào nhiều chuỗi và gọi hàm trên để kiểm tra các chuỗi đọc vào có phải là palindrome hay không. Vòng lặp sẽ chấm dứt khi người sử dụng đọc vào một chuỗi bắt đầu bằng *.

b/ Viết hàm palindromeRecursion sử dụng kỹ thuật gọi đệ quy.để kiểm tra một chuỗi có phải là palindrome hay không.

Đầu vào:

Các chuỗi ký tự s có độ dài không quá 1000 ký tự

Đầu ra:

Mỗi dòng trả về giá trị của hàm palindrome và palindromRecursion (xem ví dụ để biết thêm chi tiết)

[English]

Palindrome is a string (string) that if you reverse the order of characters in the string, we still get the old string. For example: “ABCBA”, “RADAR”, “otto”, “i am ma i”, “C”.

The palindrome function checks if a string is the given palindrome.

 

a/ Write a C++ program that uses a while loop to read multiple strings and call the above function to check whether the input strings are palindrome or not. The loop will terminate when the user reads into a string starting with *.

b/ Write a function palindromeRecursion using recursive calling technique.to check a string is palindrome or not.

Input:

Character strings s with a length of no more than 1000 characters

Output:

Each line returns the value of the palindrome and palindromeRecursion functions (see example for more details)

For example:

Test	Input	Result
1
abccba
abc
a
*
true true
false false
true true

*/

#include<iostream>
#include<string>
using namespace std;
/* END of library */

bool palindrome(string strg);

bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    if(s.length() <= 1){
        return true;
    }
    if(s.front() != s.back()){
        return false;
    }
    return palindromeRecursion(s.substr(1, s.length() - 2));
    // END YOUR IMPLEMENTATION [1]
}

int main()
{
    hiddenCheck();
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    string s;
    while (true) {
        getline(cin, s);
        if (!s.empty() && s[0] == '*') break;
        cout << boolalpha << palindrome(s) << " " << palindromeRecursion(s) << endl;
    }
  
    // END YOUR IMPLEMENTATION [2]
    return 0;
}