/* 
Write and run a program that reads two integers through the keyboard and performs simple 
arithmetic operations (i.e., addition, subtraction, multiplication and division) and displays the results.

Note: when performing division, you must round up the answer to 2 digits and 
print the answer with only 2 digits after decimal.
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float x, y;

    cin >> x >> y;
    
    cout << "5 + 1 = " << x + y <<endl;
    cout << "5 - 1 = " <<x - y <<endl;
    cout << "5 * 1 = " << x * y <<endl;
    cout << fixed << setprecision(2) << "5 / 1 = " << x / y <<endl; 
    
    return 0;
}