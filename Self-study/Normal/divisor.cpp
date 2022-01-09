#include <iostream>

using namespace std;

int main() {
	int n;
	int div = 0;

	cout << "Enter n: ";
	cin >> n;

	if (n < 0) {
		cout << "Enter n > 0: ";
	}
	else {
		for (int i = 1; i <= n; i++){
			if (n % i == 0) {
				cout << i << " ";
				div++;
			}
		}

		cout << "\nThe numbers of divisors is: " << div << endl;
	}

	return 0;
}