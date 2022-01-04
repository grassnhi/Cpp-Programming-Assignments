#include <iostream>
using namespace std;

int main() {
    for(int i=1; i<=5; i++){
        if(i<3)
            continue;
             // skip following code and then continue with the following i

        else
            break;
             // quit all loop
        cout << "coucou" << endl;
    }
    return 0;
}