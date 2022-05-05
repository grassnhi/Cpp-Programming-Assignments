#include<iostream>
using namespace std;
void increment(int &input); 

int main() {
	int a = 34;
	cout << "Before the function call a = " << a << "\n";
	increment(a);
	cout << "After the function call a = " << a << "\n";
	return 0;
}

void increment(int &input){
	input++; 
}
