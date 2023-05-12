#include <iostream>
#include <cmath>
using namespace std;

bool revisible(long n) {
	long m = n;
	long nRev = 0;
	while (n > 0) {
		nRev = nRev * 10 + n % 10;
		n /= 10;
	}
	return m == nRev;// true neu m == nRev
}

bool onlyEvenDigit(long n) {
	while (n > 0) {
		char c = n % 10;
		n /= 10;
		if (c % 2 != 0) {
			return false;
		}
	}
	return true;
}

bool sumOfDigitDiv5(long n) {
	int sumDigit = 0;
	while (n > 0) {
		sumDigit += n % 10;
		n /= 10;
	}
	return sumDigit % 5 == 0;
}

int main() {
	for (long i = 200000000; i <= 888888888; i += 2)
	{
		if (onlyEvenDigit(i) && revisible(i) && sumOfDigitDiv5(i)) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}