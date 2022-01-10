#include <iostream>
using namespace std;

void xy(int &x, int &y) {
	cout << "Enter the two positive numbers x, y: ";
	cin >> x >> y; // x column and y row
}

void border(int x, int y) {
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1) {
				cout << " * ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
}

int main() {
	int x, y;
	xy(x, y);
	border(x, y);
	return 0;
}

/*
 * * * * *          00 01 02 03 04  // j = 0
 *       *      =>  10          14
 *       *          20          24  
 * * * * *          30 31 32 33 34  // j = y - 1 
 */               //i=0         // i = x -1