#include<iostream>
#include <cstring>
using namespace std;

string deleteWord(string s, string s1){
    int found = s.find(s1);
    if(found > s.length()|| found < 0){
        cout << s;
        return;
    }
    else{
        while (found >= 0){
            s.erase(found, s1.length());
            found = s.find(s1, found);
        }
    }
    
    cout << s;
}

int main(){
	string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
string s1 = "ai";
string s2 = "ong";
replaceString(s, s1, s2);
}

