// ++ a and a++
// b = ++ a means a = a + 1; b = a; (b = a + 1;) => a = new value first
// b = a ++ means b = a; a = a +1; (b = a first, then a = new value)

#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = ++a*5;
    // a = a + 1 first, then b = (a + 1)*5 = 6*5 = 30
    cout << b;
    return 0;
}