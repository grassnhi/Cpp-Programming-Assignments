#include <iostream>
using namespace std;

int main(){
    int n, sum = 0, odd = 0, even = 0;
    
    cout << "Enter a positive integer number: " << endl;
    cin >> n;

    if(n < 0){ 
        cout << "It is a wrong number!\n" << "Enter a positive integer number: " << endl;
        cin >> n;
    }

    sum = (n + 1)*n / 2;

    for(size_t i = 0; i < n; i++){
        if(i % 2 == 0){ 
            even += i;
        }
        else{ 
            odd += i;
        }
    }

    cout << "The sum of the numbers from 0 to n is: " << sum << endl;
    cout << "The sum of even numbers from 0 to n is: " << even << endl;
    cout << "The sum of odd numbers from 0 to n is: " << odd << endl;

    return 0;

}