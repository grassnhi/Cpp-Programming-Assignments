// C++ code to find count of sub-arrays with odd sum

#include <bits/stdc++.h>
using namespace std;

int countOddSum(int ar[], int n)
{
	int result = 0;

	// Find sum of all subarrays and increment
	// result if sum is odd
	for (int i = 0; i <= n - 1; i++) {
		int val = 0;
		for (int j = i; j <= n - 1; j++) {
			val = val + ar[j];
			if (val % 2 != 0)
				result++;
		}
	}

	return (result);
}

// Driver code
int main()
{
	int ar[] = { 5, 4, 4, 5, 1, 3 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << "The Number of Subarrays with odd sum is " << countOddSum(ar, n);

	return (0);
}
