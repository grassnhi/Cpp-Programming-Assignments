// String

#include <iostream>
using namespace std;

int main() {
   string str= "Dr Cat Can Code";
   string strClone(str, 3, 3);
   cout << "|" << strClone << "|";
}
// Output: |Cat|