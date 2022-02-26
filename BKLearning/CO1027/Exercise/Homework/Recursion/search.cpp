/*
Write a recursiveSearch function that takes an array of N elements as input, and the value M. 
The recursiveSearch function returns the first position of the value M in the sequence 
(assuming this element has an index of k) and deletes the part. 
the element at position k out of the sequence. If not found, will return -1

Input:

    The recursiveSearch function takes the following input values:
    Number of elements of the sequence N (0 N ≤ 108)
    The sequence of N elements arr and each element has a value in the range (0; 109)
    Number M (0 < M < 109)
    The initial call for index variable in main() is 0

Output:
    The recursiveSearch function will return the request of the problem.
*/

#include <iostream>

using namespace std;

int recursiveSearch(int& n, int m, int arr[], int index)
{
	// Implement function content here
	if (n == 0 || n <= index)
		return -1;
	else if (arr[index] == m)
	{
		for (int i = index; i < n; i++)
			arr[i] = arr[i + 1];
		n -= 1;
		return index;
	}
	else recursiveSearch(n, m, arr, index + 1);
}

int main(){
    
}