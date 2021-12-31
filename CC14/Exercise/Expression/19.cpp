#include <iostream>
using namespace std;

int main() {
    int a = 10, c = 5;
    switch(a = 1){
        case 1: c = 8;
        case 2: c = 9;
        case 3: c = 7; break;
        case 4: c = 6;

    }
    cout << a << " " << c;
    return 0;
}

// output: 1 7 => a=1, c=7 => case 3
// 1 6 if not having break at case 3