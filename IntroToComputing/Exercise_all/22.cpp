#include <iostream>
using namespace std;

int main() {
    string str = "Dr Cat Can Code";
    
    string strOutput(str, 2, 4);

    cout << "|" << strOutput << "|";
    return 0;
}