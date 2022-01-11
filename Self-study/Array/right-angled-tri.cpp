#include <iostream>
using namespace std;

void rightTriangle(int h) {
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			cout << " * ";
		}
		cout << endl;
	}
}

int main() {
	int h;
	cout << "Enter h: ";
	cin >> h;
	rightTriangle(h);
	return 0;
}