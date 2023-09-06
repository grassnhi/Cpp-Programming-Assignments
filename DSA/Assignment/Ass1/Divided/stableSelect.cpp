// C++ program for modifying Selection Sort
// so that it becomes stable.
#include <iostream>
using namespace std;

void stableSelectionSort(int a[], int n)
{
	// Iterate through array elements
	for (int i = 0; i < n - 1; i++)
	{

		// Loop invariant : Elements till a[i - 1]
		// are already sorted.

		// Find minimum element from
		// arr[i] to arr[n - 1].
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;

		// Move minimum element at current i.
		int key = a[min];
	//Shift left all elements by one.
	for(int k=min;k>i;k--)
		a[k]=a[k-1];
	//Store the key at its right position.
		a[i] = key;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int a[] = { 4, 5, 3, 2, 4, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	stableSelectionSort(a, n);
	printArray(a, n);
	return 0;
}
