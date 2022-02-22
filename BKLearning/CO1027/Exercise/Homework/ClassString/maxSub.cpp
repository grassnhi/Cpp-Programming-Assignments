/*
Write a program read an s string from keyboard, find and return the longest symetrical sub-string of s.

Input:  String s.

Output: The longest symmetrical sub-string from s. 
In case where there are more than one highest string, return the string with 
the smallest starting character index.
*/

#include <iostream>
#include <string>

using namespace std;

string longestPalindroes(string str){
    int start = 0, max = 1;

    for( int i = 0; i < str.length(); ){
        int j = i, k = i;

        while(k < str.length() - 1 && str[k] == str[k+1]){
            k++;
        }

        i = k + 1;
        
        while(k < str.length() - 1 && j > 0 && str[k+1] == str[j-1]){
            --j;
            ++k;
        }

        int len = k - j + 1;

        if(len > max){
            max = len;
            start = j;
        }
    }

    return str.substr(start, max);
}

int main()  {
    string s;
    cin >> s;

    cout << longestPalindroes(s);
    
    return 0;
}