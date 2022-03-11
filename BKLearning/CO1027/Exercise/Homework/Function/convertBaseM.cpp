/*
Given two natural numbers n and m. Write a function that converts n to base m and returns that value, given that m is in {2, 4, 8}. Student must provide a default argument of value 2 for the second parameter(m).

Input:
    int n:  a natural number n that needs to be converted
    int m:  the new base which n is converted to. 
            The default argument of this parameter must be 2 when defining the function.

Output:
    int: the value of n in base m

Note: 
    the input guarantees that the return value will not cause integer overflow
*/

#include <iostream>

using namespace std;

int convertToBaseM(int n){
    int dec = n, remainder = 0, binary = 0, product = 1;
    while (dec != 0) {
        remainder = dec % 2;
        binary = binary + (remainder * product);
        dec = dec / 2;
        product *= 10;
    }
    return binary;

}
int convertToBaseM(int n, int m){
    int dec = n, remainder = 0, base = 0, product = 1;
    while (dec != 0) {
        remainder = dec % m;
        base = base + (remainder * product);
        dec = dec / m;
        product *= 10;
    }
    return base;
}

int main(){
    int n;
    cin >> n;
    cout << convertToBaseM(n, 4) << '\n';
    cout << convertToBaseM(n, 8) << '\n';
    cout << convertToBaseM(n);
}