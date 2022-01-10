#include <iostream>
using namespace std;

void rightTriangle(int h) {
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < h; j++)
		{
			if (j < i) {   // j > i => same as right-angled-tri.exe
				cout << "   ";
			}
			else {
				cout << " * ";
			}
		}
		cout << endl;
	}
}

int main() {
	int h, d;
	cout << "Enter h: ";
	cin >> h;
	rightTriangle(h);
	return 0;
}