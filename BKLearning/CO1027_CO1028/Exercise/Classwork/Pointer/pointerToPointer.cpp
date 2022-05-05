#include <iostream>

using namespace std;

int main() {
	int  var = 300;
	int  *ptr = &var; // take the address of var
	int  **pptr = &ptr; // take the address of ptr 

	// take the value using pptr
	cout << "Value of var :" << var << endl;
	cout << "Value available at *ptr :" << *ptr << endl;
	cout << "Value available at **pptr :" << **pptr << endl;

	return 0;
}
