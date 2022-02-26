/*
A string is a palindrome if it reads the same forward and backward. 
For example: "eye", "noon", "abcba", ...

Write a function to check if a given string is a palindrome

Input: 
    const char* str: the string to be checked. str only contains lowercase letters
Output:
    bool: true if str is a palindrome, false otherwise
*/

#include <iostream>

using namespace std;

bool isPalindrome(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i);
    
    for (int j = 0; j < i / 2; j++) {
        if (str[j] != str[i - j - 1]) {
            return false;
        }
    }
    return true;
}

int main(){
    const char* str = "abba";
cout << isPalindrome(str);

}