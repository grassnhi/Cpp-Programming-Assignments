/*
Given a function:
F(x)=ax2+bx+c
Write and run a program that performs the following steps:
- Reading the value of a, b and c from the keyboard.
- Solving F(x)=0 ( assume that the equation has two real distinct solutions x1 and x2 ).
- Displaying x1 and x2 .
*/

#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

int main()
{
    float a, b, c, x1, x2, delta;

    cin >> a >> b >> c;

    delta = b*b - 4*a*c;
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        cout << fixed<<setprecision(2) << "X1= " << x1 << endl;
        cout << fixed<<setprecision(2) <<"X2= " << x2 << endl;
        
    return 0;
}