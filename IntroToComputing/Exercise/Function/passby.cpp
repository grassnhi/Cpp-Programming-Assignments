// Pass by value: pass value to function, then value out function not change
// Pass by reference: value out change and value out = value in function

#include <iostream>
using namespace std;

int squareByValue( int );
void squareByReference( int & );   

int main()
{
    int x = 2, z = 4;

    cout    << "x = " << x << " before squareByValue\n" // x = 2 at first
            << "Value returned by squareByValue: "
            << squareByValue( x ) << endl // x = x*x => x = 4
            << "x = " << x << " after squareByValue\n" << endl; 
                        // the value of x did not change => x = 2 

    cout << "z = " << z << " before squareByReference" << endl; // z = 4
    squareByReference( z ); // z = z*z => z = 16
    cout << "z = " << z << " after squareByReference" << endl;
                // after calling function, the value of z change
                // the value of z here is the value of it in function => z = 16
   return 0;
}

int squareByValue( int a )
{
   return a *= a;   // caller's argument not modified
}

void squareByReference(int &cRef )
{
   cRef *= cRef;    // caller's argument modified
}

