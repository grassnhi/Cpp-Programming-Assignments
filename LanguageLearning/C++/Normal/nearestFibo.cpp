// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the Fibonacci
// number which is nearest to N
int nearestFibonacci(int num)
{
	// Base Case
	if (num == 0) {
		cout << 0;
		return;
	}

	// Initialize the first & second
	// terms of the Fibonacci series
	int first = 0, second = 1;

	// Store the third term
	int third = first + second;

	// Iterate until the third term
	// is less than or equal to num
	while (third <= num) {

		// Update the first
		first = second;

		// Update the second
		second = third;

		// Update the third
		third = first + second;
	}

	// Store the Fibonacci number
	// having smaller difference with N
	int ans = (abs(third - num) >= abs(second - num)) ? second: third;

	// Print the result
	return ans;
}

// Driver Code
int main()
{
	int N = 17;
	nearestFibonacci(N);

	return 0;
}
