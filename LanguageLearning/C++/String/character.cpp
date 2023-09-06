// length = 0 => null string and empty string
// length # 0 và phần tử là kí tự trống => blank string

string variable_name;

// Truy xuất

variable_name[i]

// end string with '\0' null character

#include<iostream>
using namespace std;

int main(){
    string s = "Khoa hoc va Ky thuat May tinh !";
    cout << s << endl;

    int i = 0;
    while (s[i] != '\0')
    {
        cout << s[i];
        i++;
    }
    
    cout << endl;

    return 0;
}