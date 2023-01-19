#include<iostream>
using namespace std;

int main(){
    string s1 = "KHMT";
    string s2 = "KTMT";

    bool b;

    b = s1 == s2;
    cout << b << endl;

    b = s1 != s2;
    cout << b << endl;

    b = s1 < s2;
    cout << b << endl;

    b = s1 <= s2;
    cout << b << endl;

    b = s1 > s2;
    cout << b << endl;

    b = s1 >= s2;
    cout << b << endl;

    return 0;
}