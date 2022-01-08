// S = 1 + 1.2 + 1.2.3 + ...+1.2.3...n


#include <iostream>
using namespace std;

int main() {
	int n;
	long long sum = 0;

	cout << "Enter a natural number: ";
	cin >> n;

	long long x = 1;

	for (size_t i = 1; i <= n; i++)
	{
		x *= i; 
		sum += x; 
	}

	cout << "SUM = " << sum << endl;

	return 0;
}