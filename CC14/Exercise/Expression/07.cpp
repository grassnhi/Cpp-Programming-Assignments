// Strange operations

#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6, c, d;

    c = a,b; // c = a;
    d = (a,b); // d = b;
    
    cout << c << ' ' << d; 
    // c = 5 and d = 6
    return 0;
}