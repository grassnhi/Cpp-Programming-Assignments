#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime(long n) {
	if (n < 2) {
		return false;
	}
	for (long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool primeDigit(long n) {
	char c;
	while (n > 0) {
		c = n % 10;
		n /= 10;
		if (!checkPrime(c)) {
			return false;
		}
	}
	return true;
}

bool revPrime(long n) {
	long m = n;
	long nRev = 0;
	while (n > 0) {
		nRev = nRev * 10 + n % 10;
		n /= 10;
	}
	if (m == nRev) { 
		return checkPrime(nRev);
	}
	return false;
}

bool sumOfPrimeDigit(long n) {
	int sumOfDigit = 0;
	while (n > 0) {
		sumOfDigit += n % 10;
		n /= 10;
	}
	return checkPrime(sumOfDigit);
}

int main() {
	for (long i = 100000001; i <= 999999999; i += 2)
	{
		if (primeDigit(i) && revPrime(i)
			&& sumOfPrimeDigit(i)
			&& checkPrime(i)) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}