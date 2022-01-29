/*
Implement findAllIndex(string s1, string s2) to print all positions of the first character 
of string s2 in string s1. If not found, print -1. The found positions will be separated 
by a space, after the last position, do not print any more characters (including spaces, carriage returns)

Hint:  Use the string::find function in the <string> library.
*/

// C++ program to find indices of all
// occurrences of one string in other.
#include <iostream>

using namespace std;

void findAllIndex(string s1, string s2){
	bool temp = false;

	for (int i = 0; i < s1.length(); i++) {
		if (s1.substr(i, 1) == s2.substr(0, 1)) {
			cout << i << " ";
			temp = true;
		}
        //cout << " " << s1.substr(i, 1) << " ";
	}

	if (temp == false)
		cout << "-1";
}

int main()
{
	string s1 = "Truong Dai Hoc Bach Khoa.";
    string s2 = "lanjhgf";

    findAllIndex(s1, s2);
    //cout << s2.substr(0, 1);

	return 0;
}

