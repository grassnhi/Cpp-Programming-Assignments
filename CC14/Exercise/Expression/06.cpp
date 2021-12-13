// True/False and operations

#include <iostream>
using namespace std;

int main() {
    int x = 2, y = 3;
    y = x + (x = 4);
    // x = 4, y = x + x = 4 + 4 =8
    cout << y; // Output = 8
    return 0;
}