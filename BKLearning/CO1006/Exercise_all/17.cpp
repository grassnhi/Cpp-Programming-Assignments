#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 5; i++){
        if(i < 3)
            continue;

        else
            break;

        cout << "coucou" << endl;
    }

    return 0;
}