#include<iostream>
using namespace std;

void printOut(int input); 

int main() {
	int a = 34;

	cout << "Before the function call a = " << a << "\n";
	
    printOut(a); 
    //value of a copied to the input and use in the function.

	cout << "After the function call a = " << a << "\n";

}

void printOut(int input){
	cout << "Value of a = " << input << "\n";
    input ++;
    cout << "New value of a = " << input << "\n";
}