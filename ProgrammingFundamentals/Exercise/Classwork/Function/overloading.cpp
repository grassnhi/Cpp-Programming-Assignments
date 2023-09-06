#include<iostream>
using namespace std;

float add(float a, float b) {
	return a + b + b;
}

int add(int a, int b) {
	return a + b;
}

double add(int a, double b) {
	return (double)a + b;
}

int main() {

/*
    int a = 2, b = 3;
    int c = add(a, b);
*/

/*
    float a = 2.0, b = 3.1;
    float c = add(a, b);
*/

    int a = 2;
    double b = 3.2;
    double c = add(a, b);

    cout << "Total of a and b is " << c << endl;

    return 0;
}