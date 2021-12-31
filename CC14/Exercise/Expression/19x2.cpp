#include <iostream>
using namespace std;

int main() {
    int a = 10, c = 5;
    switch(a = 10){
        case 1: c = 8;
        case 2: c = 9;
        case 3: c = 7;
        case 4: c = 6;

    }
    cout << a << " " << c;
    return 0;
}

// a = 10, c = 5 whenever having break or not