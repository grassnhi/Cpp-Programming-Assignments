#include <iostream>
using namespace std;

int main() {

	int arr[10];

	int* otherArray;

	otherArray = new int[10];

    char name[200]; // static array
        // the number of elements is defined 

    char* names = new char[200]; // dynamic array
            // do not know how many elements in the array.

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = 0;
		cout << arr[i] << " ";
	}

	cout << "\nDynamically allocated array: \n";

	for (size_t i = 0; i < 10; i++)
	{
		otherArray[i] = -1;
		cout << otherArray[i] << " ";
	}

	return 0;
}