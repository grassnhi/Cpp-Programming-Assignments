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

	int tmp = n;
	int rev = 0;

	while (n > 0) { 
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (tmp == rev) {
		cout << tmp << " is a reversible number." << endl;
	}
	else {
		cout << tmp << " is not a reversible number." << endl;
	}
    
	return 0;
}