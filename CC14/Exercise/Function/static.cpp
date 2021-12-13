// Auto storage class # static storage class

#include <iostream>
using namespace std;

int funct( int);   
// function prototype
int main()
{
    int count, value;        
    // count is a local auto variable
    for(count = 1; count <= 10; count++){
        value = funct( count);
        cout << count << '\t' << value << endl;
    }

    return 0;
}

int funct( int x)
{
  static int sum = 100;     // sum is a local static variable
  sum += x;
  return sum; // sum = 100 at the first time, after that sum = new sum or updated sum
}

/*
Note:
1.The initialization of static variables is done only once when the program is first compiled. 
At compile time, the variable is created and any initialization value is placed in it. 
2. All static variables are set to zero when no explicit initialization is given. 
*/