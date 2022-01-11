#include <iostream>
using namespace std;

bool reversible(int n) {
	int m = n;
	int rev = 0;

	while (n > 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	return rev == m;
}

int odd(int n) {
	int temp = 0;

	while (n > 0) {
		int c = n % 10; 
		n /= 10;

		if (c % 2 != 0) {
			temp++;
		}
	}

	return temp;
}

int even(int n) {
	int temp = 0;

	while (n > 0) {
		int c = n % 10; 
		n /= 10;

		if (c % 2 == 0) {
			temp++;
		}
	}

	return temp;
}

int main() {
	int n;

	cout << "Nhap so duong n: ";
	cin >> n;

	if (n < 0) {
		cout << "Nhap lai so duong n!";
	}
	else {
		if (reversible(n)) {
			cout << "Reversible!" << endl;
		}
		else {
			cout << "Not Reversible!" << endl;
		}

		cout << "The number of odd digits = " << odd(n) << endl;
		cout << "The number of even digits = " << even(n) << endl;
	}
	return 0;
}