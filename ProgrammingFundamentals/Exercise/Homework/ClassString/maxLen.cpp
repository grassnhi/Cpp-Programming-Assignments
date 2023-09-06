/*
Write a program read a string s from keyboard, find and return the length of 
the longest sub-string that doesn't have any repeated character in s.

Input:  String s.

Output: Length of the longest sub-string that doesn't have any repeated character in s.
*/

#include <iostream>
#include<string.h>

using namespace std;

bool check_not_repeated(string s) {
	for (unsigned int i = 0; i < s.length(); i++)
		for (unsigned int j = i + 1; j < s.length(); j++)
			if (s[i] == s[j]) 
                return false;

	return true;
}

int main() {
	string s;
	getline(cin, s);

	unsigned int longest = 1;

	for (unsigned int i = 0; i < s.length(); i++) {
		for (unsigned int j = i + 1; j < s.length(); j++) {
			string temp = s.substr(i, j - i + 1);

			if (check_not_repeated(temp)) 
                if (longest < temp.length()) 
                    longest = temp.length();
		}
	}
    
	cout << longest;
}