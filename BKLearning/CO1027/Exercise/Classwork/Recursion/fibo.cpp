#include<iostream>
using namespace std;

int fibonacci(int n);

int main() {
	cout << fibonacci(5) << endl;

	return 0;
}

int fibonacci(int n) {
	if (n <= 2) 
        return 1;
	
    return fibonacci(n - 1) + fibonacci(n - 2);
}
