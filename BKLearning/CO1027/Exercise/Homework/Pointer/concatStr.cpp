/*
Implement the function char* concatStr(char* str1, char* str2) that return a string merged from two smaller string str1 and str2.
Input: Two string str1 and str2.

Output: The string merged from two smaller string str1 and str2.

Note: The string and string.h library are not allowed to use for this exercise.

*/

#include <iostream>

using namespace std;

char* concatStr(char* str1, char* str2) {
    // TODO
    int len1 = 0, len2 = 0;
    while ( str1[len1] != '\0' ){
        len1++;
    }

    while ( str2[len2] != '\0' ){
        len2++;
    }
    
    char* newstr = new char[len1 + len2];
    
    int pos = 0;
    for ( int i = 0; str1[i] != '\0'; i++ ){
        newstr[pos] = str1[i];
        pos++;
 
    }
    for ( int i = 0; str2[i] != '\0'; i++ )
    {
        newstr[pos] = str2[i];
        pos++;
    }
    newstr[pos] = '\0';
    return newstr;
}

int main(){
    char s1[] = "Hello, ";
    char s2[] = "how are you?";
    char* s = concatStr(s1, s2);
    cout << s;
    delete[] s;
}