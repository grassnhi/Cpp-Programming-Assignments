#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n) {
	if(n <= 2) {
		return false;
	}
	int i;
	for(i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int a, b;
	cout << "Enter a and b that is a < b, a > 0: ";
    cin >> a >> b;

	if(a > 0 && b > 0) {
		for(int i = a; i <= b; i++) {
			if(prime(i)) {
				cout << i << " ";
			}
		}
    }
	
	return 0;
}
