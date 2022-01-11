#include <iostream>
using namespace std;

void enter(int& k) {
	cout << "Enter k (0< k <= 72): ";
	cin >> k;
}

bool reversible(int n) {
	int m = n;
	int rev = 0;

	while (n > 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	return rev == m;
}

bool divisible(int n, int k) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10; // sum of the digits
		n /= 10;
	}

	return sum % k == 0;
}

int main() {
	int k;

	enter(k);

	if (k <= 0 || k > 72) {
		cout << "Enter k (0 < k <= 72): ";
        cin >> k;
	}
	else {
		cout << "The numbers that have 8 digits and are divisible by " << k << " : \n";
		for (size_t i = 10000000; i <= 99999999; i++){
			if (reversible(i) && divisible(i, k)) {
				cout << i << " ";
			}
		}
	}

	return 0;
}