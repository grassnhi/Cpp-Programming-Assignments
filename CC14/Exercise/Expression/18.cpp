#include <iostream>
using namespace std;

int main() {
    int a = 6, b = 7, c = 8, d = 9;
    cout << ( a > 5 == b < 10 && c >= 5 != ++d <= 10);
    return 0;
}

// => output = 0