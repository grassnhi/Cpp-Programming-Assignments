#include<iostream>
using namespace std;

void displaySum(int, int);

int main() {
	displaySum(5, 10);
	return 0;
}

// Function with parameters and without return
void displaySum(int num1, int num2) {
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
    //C++ also can use this.
}
