#include<iostream>
using namespace std;

void xy(int &x, int &y) {
	cout << "Enter the two positive numbers x, y: ";
	cin >> x >> y; // x column and y row
}

void rect(int x, int y) {
	for (size_t i = 0; i < y; i++) 
	{
		for (size_t j = 0; j < x; j++)
		{
			cout << " " << '*' << " ";
		}
		cout << endl;
	}
}

int main() {
	int x, y;

	xy(x, y);
	rect(x, y);

	return 0;
}