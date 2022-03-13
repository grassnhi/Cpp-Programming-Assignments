/*
Write a function that finds the most frequent character in a given string and 
how many times that character appears. If there are multiple characters satisfy the condition, 
find the one with the lowest alphabetical order.

Input:
    const char* str: the input string, contains only lowercase and uppercase ASCII letters

Output:
    char& res: the most frequent character in str 
    int& freq: the times that the result character appears in the string

Note: return res as a lowercase letter. 
    Uppercase letters in str is also counted as lowercase letters 
    (e.g the string "aA" contains two letter 'a')
*/

#include <iostream>

using namespace std;

void mostFrequentCharacter(char* str, char& res, int& freq) {
    int len = 0, idx = 0;
    if(!*str) return;
    
    while(str[len] != '\0'){
        len++;
    }
    for(int i = 0; i <= len; i++){
        if(str[i] >= 65 && str[i] <= 90)
            str[i]=str[i]+32;
   }
    int check = 0;
    for(int i = 0; i < len; i++){  
        if(str[i] <= 96 || str[i] > 122){
            check++; 
        }
    }
    if(check == len){
        return;
    }
    
    for(int i = 0; i < len; i++){  
        int count = 0;
        if(str[i] <= 96 || str[i] > 122){
            continue; 
        } 
        for(int j = 0; j < len; j++){  
            if(str[j] == str[i]){  
                count++;  
            }  
        }
        
        if(count > freq){  
            freq = count;  
            res = str[i];
            idx = i;
        }
        else if(count = freq){
            if(str[i] < str[idx]){
                res = str[i];
            }
            else
                res = str[idx];
        }
    }
    
}

int main(){
    string s = "AAZhakkjdsjjgBbakKqkibbbgh";
    char *str = &s[0];
    char res = 0;
    int freq = 0;
    mostFrequentCharacter(str, res, freq);
    cout << res << ' ' << freq;
    }