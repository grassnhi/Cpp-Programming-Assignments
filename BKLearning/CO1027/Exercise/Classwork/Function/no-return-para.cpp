// Function with parameters and without return

#include<iostream>
using namespace std;

void displayMessage(); // declare a function

int main() {
	displayMessage(); // calling that function
	return 0;
}


void displayMessage() { // define the function
	cout << "Welcome to my workplace!\n";
}
