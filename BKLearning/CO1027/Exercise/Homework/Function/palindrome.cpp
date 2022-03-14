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
bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    int begin = 0;
    int end = s.length() - 1;
    if (end == begin || end - begin == 1) return true;
    else
    {
        if (s[begin] == s[end])
        {
            s.erase(0, 1);
            s.erase(s.length()-1, s.length());
            return palindromeRecursion(s);
        }
        return false;
    }
   
    // END YOUR EMPLEMENTATION [1]
}

int main()
{
    // BEGIN YOUR IMPLEMENTATION [2]
    string s;
    cin >> s;
    if (s[0] == '*') return 0;
    else
    {
        do
        {
            int i = 0;
            int j = s.length() - 1;
            while (s[i] == s[j] && i <= s.length()/2)
            {
                i++;
                j--;
                
            }
            if (s[i] != s[j]) cout << "false" << " ";
            else cout << "true" << " ";
            if(palindromeRecursion(s))
            {
                cout << "true";
            }
            else cout << "false";
            cout << "\n";
            cin >> s;
        }
        while(s[0] != '*');
    }
     
    // END YOUR EMPLEMENTATION [2]
    return 0;
}
int main(){
    const char* str = "abba";
cout << isPalindrome(str);

}