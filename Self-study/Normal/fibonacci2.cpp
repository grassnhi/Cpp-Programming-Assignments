#include <iostream>

using namespace std;

int Fibonacci(int n){
    int f1 = 1, f2 = 1;
    
    if( n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    int i = 3, f;

    while (i <= n)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        i++;
    }

    return f;
}

int main(){
    int n;

    cout << "Enter n > 0: ";
    cin >> n;

    cout << "Fibonacci of " << n << " is: " << Fibonacci(n);

    return 0;
}
 