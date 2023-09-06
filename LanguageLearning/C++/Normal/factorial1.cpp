#include <iostream>
#include <iomanip>

using namespace std;

int factorial( int );

int main()
{
for ( int i = 0; i <= 10; i++ )
    cout << setw( 2 ) << i << "! = " << factorial( i ) << endl;
    return 0;
}

int factorial( int number )
{
    if (number == 0)  // base case
        return 1;
    else                // recursive case
        return number * factorial( number - 1 );
}