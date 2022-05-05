/*
Implement the function cutString(string s, int index) to print the substring of string s 
from index position to the end (index from 0).

Hint:  Use the string::substr function in the <string> library.
*/
#include <string>
#include <iostream>

using namespace std;

void cutString(string s, int index){
    if(index > s.length() || index <0){
        return;
    }else
    cout << s.substr(index);
}

int main(){
    string s = "Truong Dai Hoc Bach Khoa.";
    cutString(s, 100);
}
