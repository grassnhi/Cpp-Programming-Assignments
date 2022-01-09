#include <iostream>
using namespace std;

int main() {
	int n, k;
	long sum = 0;

	cout << "Enter n, k: ";
	cin >> n >> k;

	if (n >= 0 && k > 0) {
		for (int i = 1; i < n; i++)
		{
			if (i % k == 0) {
				sum += i;
			}
		}

		cout << "SUM = " << sum << endl;
	}
	else {
		cout << "You must enter 2 natural number n >= 0 and k > 0";
	}

	return 0;
}