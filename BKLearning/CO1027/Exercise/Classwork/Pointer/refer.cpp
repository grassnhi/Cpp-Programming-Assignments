#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int& b = a;

	cout << "Value of a :" << a << endl;
	cout << "Value of a reference :" << b << endl;

	a = 6;
    
	cout << "Value of a :" << a << endl;
	cout << "Value of a reference :" << b << endl;
}
