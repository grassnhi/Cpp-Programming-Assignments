#include<iostream>
using namespace std;

int main(){
    string s1, s2, s3;

    s1 = "KHMT";
    s2 = "KTMT";
    s3 = s1 + " " + s2;

    char c = s2[1];
    cout << c;

    return 0;
}