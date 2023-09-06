/*
Implement int calc(const char *str) function which returns the decimal value of binary string str.

- Input: Char * pointer to the first character of string

- Output: The decimal value of binary string

- Available library: <iostream>, <cstring>

- Note: Your code MUST NOT contain any of the words in the list {"include", "string"} even in the comment
*/
#include <iostream>
#include <cstring>
using namespace std;

int calc(char str[]) {
	int dec= 0;

	int base = 1;

	int n = strlen(str);

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == '1')
			dec += base;

		base = base * 2;
	}

	return dec;
}


int main(){
	char str[] = "001011" ;
    cout << calc(str);
}
