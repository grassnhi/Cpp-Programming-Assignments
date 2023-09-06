/*
Palindrome is a string (string) that if you reverse the order of characters in the string, 
we still get the old string. 

For example: “ABCBA”, “RADAR”, “otto”, “i am ma i”, “C”.

The palindrome function checks if a string is the given palindrome.

a/ Write a C++ program that uses a while loop to read multiple strings and 
call the above function to check whether the input strings are palindrome or not. 
The loop will terminate when the user reads into a string starting with *.

b/ Write a function palindromeRecursion using recursive calling technique 
to check a string is palindrome or not.

Input:
    Character strings s with a length of no more than 1000 characters

Output:
    Each line returns the value of the palindrome and palindromeRecursion functions 
    (see example for more details)
*/

#include<iostream>
#include<string>
using namespace std;
/* END of library */
bool palindrome(string strg);
bool palindrome(string strg){
    int begin = 0;
    int end = strg.length() - 1;
    while(strg[begin] == strg[end] && begin <= end){
        begin++;
        end--;
    }
    if(strg[begin] != strg[end]){
        return false;
    }else
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
    
    while (cin >> s) {
        if(s == "*"){
            break;
        }
        if(palindrome(s)){
            cout << "true ";
        }else
            cout << "false ";
        if(palindromeRecursion(s)){
            cout << "true";
        }else
            cout << "false";
        cout << endl;
    }   
    // END YOUR EMPLEMENTATION [2]
    return 0;
}
