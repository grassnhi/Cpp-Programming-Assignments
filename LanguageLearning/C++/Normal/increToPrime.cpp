// C++ program to find the minimum
// number to be added to N to
// make it a prime number

#include <bits/stdc++.h>
using namespace std;

// Function to check if a given number
// is a prime or not
bool isPrime(int n)
{
	// Base cases
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	// For all the remaining numbers, check if
	// any number is a factor if the number
	// or not
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	// If none of the above numbers are the
	// factors for the number, then the
	// given number is prime
	return true;
}

// Function to return the smallest
// number to be added to make a
// number prime
int findSmallest(int N)
{

	// Base case
	if (N == 0)
		return 2;
	if (N == 1)
		return 1;

	int prime = N, counter = 0;
	bool found = false;

	// Loop continuously until isPrime returns
	// true for a number greater than n
	while (!found) {
		if (isPrime(prime))
			found = true;
		else {

			// If the number is not a prime, then
			// increment the number by 1 and the
			// counter which stores the number
			// to be added
			prime++;
			counter++;
		}
	}

	return counter;
}

// Driver code
int main()
{
	int N = 10;

	cout << findSmallest(N);

	return 0;
}
