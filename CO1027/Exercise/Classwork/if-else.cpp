#include<iostream>
using namespace std;

int main() {

    int a, b, max;
    
    cout << "Enter two integer numbers: ";
    cin >> a >> b;
    
    if (a > b)
		max = a;
    else
		max = b;

    printf("The maximum value between %d and %d is %d\n", a, b, max);
    
    return 0;
}