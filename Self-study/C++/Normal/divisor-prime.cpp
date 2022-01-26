#include <iostream>
#include <cmath>
using namespace std;

bool primeList(int n) {
	if (n < 2) {
		return false;
	}

	for (size_t i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void primeDivisorList(int n) {
	if (n == 0) {
		cout << "Infinite prime divisor!\n";
	}
	else {
		cout << "\nPrime Divisor List: \n";
		for (size_t i = 2; i <= n; i++)
		{
			if (n % i == 0 && primeList(i)) {
				cout << i << " ";
			}
		}
	}
}

void notPrimeDivisorList(int n) {
	if (n == 0) {
		cout << "Infinite non-prime divisor!\n";
	}
	else {
		cout << "\nNon-prime Divisor List: \n";
		for (size_t i = 2; i <= n; i++)
		{
			if (n % i == 0 && primeList(i) == false) {
				cout << i << " ";
			}
		}
	}
}

int main() {
	int n;

	cout << "Enter positive number n: ";
	cin >> n;

	if (n < 0) {
		cout << "Enter positive number n!";
        cin >> n;
	}
	else {
		notPrimeDivisorList(n);
		primeDivisorList(n);
	}

	return 0;
}