#include <iostream>
using namespace std;

int main() {
	float a, b, c, d, e;

	cout << "Enter 5 float number: ";
	cin >> a >> b >> c >> d >> e;

	float max = a; 

	if (b > max) {
		max = b;
	}

	if (c > max) {
		max = c;
	}

	if (d > max) {
		max = d;
	}
	if (e > max) {
		max = e;
	}

	if (a == b && b == c && c == d && d == e) {
		cout << "No maximum number!" << endl;
	}
	else {
		cout << "The maximum number is: " << max << endl;
	}
	
	return 0;
}