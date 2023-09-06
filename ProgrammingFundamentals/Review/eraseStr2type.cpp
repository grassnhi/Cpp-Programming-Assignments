#include<iostream>

using namespace std;

void erase(string s, int len, int i){
        
        for(int j = i; j < len; j++){
            s[i] = s[i+2];
        }
        
}

int minL(string s){
    int count = 0;
    while(s[count] != '\0'){
        count++;
    }
    int min = 0;
    for(int i = 0; i < count; i++){
        if(s[i] != s[i+1]){
            erase(s, count, i);
            min += 2;
            count = count - min;
        }
    }
    
    return count;
}

int main(){
    string s = "0100101";
    cout << minL(s);
    return 0;
}