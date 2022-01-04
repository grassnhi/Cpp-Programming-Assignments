#include <iostream>
using namespace std;

int main() {
    int count = 0, num;

    while( count <= 10){
    cout << "Enter a number: ";    
    cin >> num;

    if (num > 76){
         cout << "you lose!\n";
         break;
    }
    else
       cout << "Keep on trucking!\n";

    count++;
}
//break jumps to here
    return 0;
}