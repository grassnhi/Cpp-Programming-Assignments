/*
Two strings s1 and s2 will be called "friend" if we can perform left shift k times 
(k is a non-negative number) to transform s1 into s2.

A left shift can be described as:
    Move all characters in the string to the left for one time.
    Simultaneously, move the first character of the string to the last position

For example: The string "abcd" and the string "bcda" are friend strings 
            because when the string "abcd" shifts left once we get the string "bcda"

Given two strings s1, and s2, write a function to check if s1 and s2 is "friend"

Input: two strings s1 and s2: const char* type (only contains lower-case letters)

Output: a boolean value (true if s1 and s2 are "friend")

Note: Students are not allowed to use additional libraries. 
        The libraries are already included: iostream, cstring (string.h).

*/

#include<iostream>
#include<cstring>

using namespace std;

bool isFriend (const char* str1, const char* str2){
    if (strlen(str1) != strlen(str2)) return false;
    else {
        char* temp = (char*) str1;
        char* test = new char[1]; // extract the first character
        int i = 0;
        while (i < strlen(str1)){
            if (strcmp(temp,str2) == 0) return true;
            else {
                i++;
                test[0] = temp[0];
                for (int j = 0; j < strlen(str1)-1; j++){
                    temp[j] = temp[j+1];
                }
                temp[strlen(str1)-1] = test[0];
            }
        }
        return false;
    }
}


int main(){
    char str1[] = "abcdxyzt";
    char str2[] = "bcdxyzua";
    cout << isFriend(str1, str2);
    return 0;
}
