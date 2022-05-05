#include<iostream>
using namespace std;

void increment(int input);
void increment2(int& input);

int main() {
    int a = 34;
    cout << "Before the function call a = " << a << "\n";
    increment(a);
    cout << "After the function call a = " << a << "\n";

    int b = 34;
    cout << "Before the function call b = " << b << "\n";
    increment2(b);
    cout << "After the function call b = " << b << "\n";
    return 0;
}

void increment(int input) {
	input++;
}

void increment2(int& input) {
	input++;
}
