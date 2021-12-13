/*A function prototype declares to the compiler that you intend to use a function 
later in the program
*/

#include <iostream>
using namespace std;

int maximum(int, int, int); 
  // function prototype
int main()
{
   int a, b, c;

   cout << "Enter three integers: ";
   cin >> a >> b >> c;

   cout << "Maximum is: " << maximum (a, b, c) << endl;
   
   return 0;
}
// Function maximum definition
// x, y and z are parameters to the maximum function definition
int maximum( int x, int y, int z)
{
   int max = x;

   if ( y > max )
      max = y;
   if ( z > max )
      max = z;

   return max;
}