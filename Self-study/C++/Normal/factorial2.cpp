#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Enter a positive number n: ";
	cin >> n;

	if (n <= 0) {
		cout << "Please, enter a positive number n:";
        cin >> n;
	}

	int fact = 1;

	for (size_t i = n; i >= 1; i--){
			fact *= i;
		}

		cout << n << "! = " << fact << endl;

	return 0;
}