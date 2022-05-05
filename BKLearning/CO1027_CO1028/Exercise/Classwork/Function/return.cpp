// Function with parameters and return

#include<iostream>
using namespace std;

int computeSum(int, int);

int main() {
	int sum = computeSum(5, 10);
	printf("%d + %d = %d\n", 5, 10, sum);
	return 0;
}

int computeSum(int num1, int num2) {
	return num1 + num2; 
}
