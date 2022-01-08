/*
Global scope refers to variables declared outside of any functions or classes 
and that are available to all parts of your program.
 
Local scope refers to a variable declared inside a function and that is available 
only within the function in which it is declared. 
*/

#include <iostream>
using namespace std;

int x;    
// create a global variable named x
void valfun(); 
  // function prototype (declaration)
int main()
{
  int y; 
     // create a local variable named y
  x = 10; // store a value into the global variable
  y = 20;   // store a value into the local variable

  cout << "From main(): x = " << x << endl;
  cout << "From main(): y =  " << y << endl;

  valfun();      
  // call the function valfun
  cout << "\nFrom main() again: x = " << x << endl;
  cout << "From main() again: y = " << y << endl;

  return 0;
}
void valfun() {
  int y;  // create a second local variable named y
  y = 30; // this only affects this local variable's value

  cout << "\nFrom valfun(): x = " << x << endl;
  cout << "\nFrom valfun(): y = " << y << endl;

  x = 40;    // this changes x for both functions
  return;
}

/*
From main(): x = 10
From main(): y =  20

From valfun(): x = 10

From valfun(): y = 30

From main() again: x = 40
From main() again: y = 20
*/