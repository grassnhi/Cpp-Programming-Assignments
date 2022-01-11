#include <iostream>
using namespace std;

int sumary(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void factorization(int n) {
	if (n < 2) {
		cout << n << " = " << n;
	}
	else {
		cout << n << " = ";

		int i = 2;
        
		while (n != 1) {
			if (n % i == 0) {
				if (n == i) {
					cout << i << endl;
				}
				else {
					cout << i << " x ";
				}
				n /= i;
			}
			else {
				i++;
			}			
		}
	}
}

int main() {
	int n;

	cout << "Nhap so duong n: ";
	cin >> n;

	if (n >= 0) {
		cout << "sum CHU SO = " << sumary(n) << endl;
		factorization(n);
	}

	return 0;
}