/*
Given a string s representing a sentence consisting only of a-z and A-Z and space character.
Your task is to implement a function with following prototype:
string reverseSentence(string s);
The function returns the reverse sentence of sentence s.
The testcases ensure that there is only one space character between two adjacent words, and the sentences do not begin or end with any space characters.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- Using loop keywords (for, while, do) are not allowed, even in comments and variable names.
- You can write helper functions.

*/

#include<iostream>

using namespace std;

string reverseSentence(string s) {
    size_t pos = s.find(' ');
    if (pos == string::npos) {
        return s;
    }
    return reverseSentence(s.substr(pos + 1)) + ' ' + s.substr(0, pos);
}



int main(){
    cout << reverseSentence("data structure and algorithm is scary");
}