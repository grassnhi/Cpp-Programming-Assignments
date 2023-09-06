#include <iostream>
using namespace std;

int main() {
    int c[100];
    int a = 2;

    c[0] = a;
    c[a] = 75;
    c[4] = 10;
    int b = c[a + 2];
    c[c[a]] = c[2] + 5; 
    int d = c[c[a]];

    cout << b << " " << d << endl;
    
    cout << c[2] << " " << c[4] << " "<< c[75];

    return 0;

}