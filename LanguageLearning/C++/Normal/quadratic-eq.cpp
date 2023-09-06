#include <iostream>
#include <cmath>

using namespace std;

// Equation: ax^2+bx+c=0

int main() {
	float a, b, c;
	float x1, x2;

	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;

	if (a == 0) { 
		if (b == 0 && c == 0) {
			cout << "Infinite solutions!" << endl;
		}
		else if (b == 0 && c != 0) {
			cout << "No solution!" << endl;
		}
		else {
			float x = -c * 1.0 / b;
			cout << "Solution of equation " << b << "x"
				<< " + " << c << " = 0 is: x= " << x << endl;
		}
	}
	else {
		float delta = b * b - 4 * a*c;

		if (delta < 0) {
			cout << "No solution!" << endl;
		}
		else if (delta == 0) {
			cout << "Double solution: x = " 
				<< -b / (2 * a) << endl;
		}
		else {
			x1 = -b + sqrt(delta) / (2 * a);
			x2 = -b - sqrt(delta) / (2 * a);
			cout << "The solutions is: \n"
				<< "x1 = " << x1 << endl
				<< "x2 = " << x2 << endl;
		}
	}

	return 0;
}