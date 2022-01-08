#include <iostream>
using namespace std;

int main(){
    int n;
    
    cout << "Enter a postive integer number: " << endl;
    cin >> n;

    if(n < 0){ 
        cout << "It is a wrong number!\n" << "Enter a positive integer number: " << endl;
        cin >> n;
    }
    
    float sum = 0;

    for(size_t i = 1; i <= n; i++){
        sum += 1 * 1.0000f / i;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}