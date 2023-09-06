#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int n;

	cout << "Enter a positive number n: ";
	cin >> n;

	if (n < 2) {
		cout << n << " is not a prime number!" << endl;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0) {
				cout << n << " is not a prime number!" << endl;
				return 0;
			}
		}

		cout << n << " is a prime number!" << endl;
	}

	return 0;
}