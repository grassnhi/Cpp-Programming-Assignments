#include<iostream>
using namespace std;

int factorial(int n);

int main() {
	cout << factorial(4) << endl;

	return 0;
}

int factorial(int n) {
	if (n > 1 )
		return n * factorial(n - 1);
	else 
		return 1;
}