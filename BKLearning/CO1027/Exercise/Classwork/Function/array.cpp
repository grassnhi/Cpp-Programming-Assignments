#include<iostream>
#include<iomanip>
using namespace std;

void arrayAsPointer(int *array, int size);

int main() {
	const int size = 3;
	int array[size] = { 33,66,99 };
	arrayAsPointer(array, size);
	return 0;
}

void arrayAsPointer(int *array, int size) {
	
	for (int i = 0; i<size; i++)
	cout << array[i] << " ";
	cout << "\n";
}
