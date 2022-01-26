#include <iostream>

using namespace std;

int main() {
	int a, b; // ax + b = 0
	float x = 0;

	cout << "Enter a, b: ";
	cin >> a >> b;
	
    if (a == 0 && b == 0) {
		cout << "Infinite solutions!" << endl;
	}
	else if (a == 0 && b != 0) {
		cout << "No solution!" << endl;
	}
	    else {
		    x = -b * 1.0 / a;
		    cout << "Solution of equation " << a << "x"
			        << " + " << b << " = 0 is: x= " << x << endl;
	}

	return 0;
}