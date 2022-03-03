#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    return "000000000";
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