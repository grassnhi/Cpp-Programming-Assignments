#include <iostream>

using namespace std;

int main() {
	long long n;

	cout << "Enter a positive number n: ";
	cin >> n;

	if (n <= 0) {
		cout << "Please, enter a positive number n:";
        cin >> n;
	}

	int sum = 0;
    
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	cout << "SUM = " << sum << endl;

	return 0;
}