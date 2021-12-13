// String: getline()

#include <iostream>
using namespace std;

int main() {
    string msg;
    cout << "Enter a String: " << endl;
    getline(cin, msg);
    // Input: the string is entered by user and stored in msg
    cout << "The String just entered is: " << msg << endl;
    return 0;
}