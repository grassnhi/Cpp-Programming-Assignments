// Auto storage class # static storage class

#include <iostream>
using namespace std;

int funct(int);   
 // function prototype
int main()
{
    int count, value;      
    // count is a local auto variable
    for(count = 1; count <= 10; count++){
        value = funct(count);
        cout << count << '\t' << value << endl;
    }

    return 0;
}

int funct( int x)
{
  int sum = 100;     // sum is a local auto variable
  sum += x;
  return sum;
}


