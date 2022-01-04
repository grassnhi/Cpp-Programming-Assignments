// Output?

#include <iostream>
using namespace std;

int main() {
   char key = 'a';
   cout << !(key + 1 < 5) << endl;
   // In the operation, a = 97 so a + 1 = 98 > 5
   // !(a+1<5) => True 
   // => output = 1
}