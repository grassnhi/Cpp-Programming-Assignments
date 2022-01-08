#include <iostream>
using namespace std;

int main(){
    int n;
    
    cout << "Enter a positive integer number: " << endl;
    cin >> n;

    if(n < 0){
        cout << "It is a wrong number!\n" << "Enter a positive integer number: " << endl;
        cin >> n;
    }
    
    cout << "Even number: " << endl;
    for(int i = 0; i <= n; i += 2){
        cout << i << " ";
    }

    cout << "\nOdd number: " << endl;
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }

    return 0;
}