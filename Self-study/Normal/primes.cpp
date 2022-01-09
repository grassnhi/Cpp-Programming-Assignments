#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int count = 0;
	int i = 2;

	cout << "Enter a positive number n: ";
	cin >> n;

	if (n <= 0) {
		cout << "Please, enter a positive number n:";
		cin >> n;
	}
	else {
		while (i < n) {
			bool isTrue = true;
			
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0) {
					isTrue = false;
					break;
				}
			}

			if (isTrue) {
				count++;
				cout << i << " ";
			}

			i++;
		}
	}
	
	return 0;
}