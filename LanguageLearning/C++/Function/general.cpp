#include <iostream>
using namespace std;

int addTwoNumbers(int a, int b) {
	return (a + b);
}

float divAbyB(int a, int b) {
	return 1.0f * a / b;
}

void showResult(float result) {
	cout << "Result =" << result << endl;
}

int main() {
	int a = 100, b = 255;
	int sumOfAAndB = addTwoNumbers(a, b);

	cout << addTwoNumbers(100, 200);

	float divAforB = divAbyB(a, b);

	showResult(sumOfAAndB);

	showResult(divAforB);

	char x[] = "Lalalal";

	size_t len = strlen(x);

	return 0;
}