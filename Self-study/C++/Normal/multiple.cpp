#include <iostream>

using namespace std;

int main() {
	int a, b;
	int mul = 1;

	cout << "Enter two positive integer numbers a, b: ";
	cin >> a >> b;

    if(a <= 0 || b <= 0){ 
        cout << "It is a wrong number!\n" << "Enter a positive integer number: " << endl;
        cin >> a >> b;
    }

	if (a > 0 && b > 0) {
		mul = a * b;

		while (a != b) {
			if (a > b) {
				a = a - b;
			}
			else {
				b = b - a;
			}
		}

		cout << "GCD = " << a << endl;
		cout << "LCM = " << mul / a << endl;
	}

	return 0;
}