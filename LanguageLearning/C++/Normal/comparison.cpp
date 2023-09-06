#include <iostream>
using namespace std;

int main(){
    int a = 100;
    int b = 200;
    int c = 100;

    cout << (a < b) << endl;
    cout << (a <= b) << endl;

    cout << (a > b) << endl;
    cout << (a >= b) << endl;

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    cout << (a == c) << endl;
    cout << (a != c) << endl;
    
    return 0;
}