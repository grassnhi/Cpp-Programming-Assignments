#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string match(string s1, string s2){
    string s;
    int n = 0, r = 0;
    for(int i = 0; i < s1.length(); i++){
        n = stoi(s1[i]) + stoi(s2[i]) + r;
        r = 0;
        if(n > 10){
            r = n / 10;
            n = n % 10;
        }
        s += to_string(n);
        n = 0;
    }
    
    return s;
    
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    string m1 = match(pwd1, pwd2);
    string m2 = match(pwd1, pwd3);
    string m3 = match(pwd2, pwd3)
    string passList = pwd1 + "," + pwd2 + "," + pwd3 + "," + m1 + "," + m2 + "," + m3 + "," 
                            + match(m1, pwd3) + "," + match(pwd1, m3) + "," + match(m1, m3);
    return passList;
}

int main(){
    string pwd1 = notebook1("tc1-file-ntb1.txt");
    string pwd2 = notebook2("tc1-file-ntb1.txt");
    string pwd3 = notebook3("tc1-file-ntb3.txt");
    string listPwd = generateListPasswords(pwd1, pwd2, pwd3);

    cout << "pwd1: " << pwd1 << endl;
    cout << "pwd2: " << pwd2 << endl;
    cout << "pwd3: " << pwd3 << endl;
    cout << "List passwords: " << listPwd << endl;    

}