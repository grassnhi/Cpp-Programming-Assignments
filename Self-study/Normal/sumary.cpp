#include <iostream>
using namespace std;

int main(){
    int n, sum = 0, sumary = 0;
    
    cout << "Enter a positive integer number: " << endl;
    cin >> n;

    if(n < 0){ 
        cout << "It is a wrong number!\n" << "Enter a positive integer number: " << endl;
        cin >> n;
    }

    for(int i = 0; i <= n; i++){
        sum += i;
    }

    cout << "The sum of the numbers from 0 to n is: " << sum << endl;

    sumary = (n + 1)*n / 2;
    cout << "Sumary: " << sumary;

    return 0;
}