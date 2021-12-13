#include <iostream>
using namespace std;

int main() {
    string s('a'); // Error!!!
    // The right one: string s("a");
    cout << s;
    return 0;
}
// Error!!!