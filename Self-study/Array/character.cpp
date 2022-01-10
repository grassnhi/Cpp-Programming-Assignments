/* Character array in C++ 
	- End with null '\0'
	- The number of elements = the number of character + null
    - Real length: not including null
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char msg[] = "Hello\0"; // = "Hello"
    cout << "Array msg:" << msg << endl;

    char message[6] = "Hello";
    cout << "Array message:" << message << endl;

    size_t length = strlen(message); // real length
        // size_t -> unsigned integer number
    cout <<  "Length of array message:" << length << endl;

    char yourFullName[100];
    cout << "Enter your full name: ";
    cin >> yourFullName;
    cout << "Hello! " << yourFullName << endl;

    cin.getline(yourFullName, 99); // the last character is null
                // the max number = elements of array (100) - 1 (null)
    
    int yourAge;
	cout << "Enter your age: ";
    cin >> yourAge; // When enter number (yourAge) and press the button "enter".
                // the "enter" will be stored into the fullName (getline)

    cout << "Enter your name: ";
	char yourName[200];
	cin.getline(yourName, 199); // this command is passed
                // output of this is nothing

    cout << "\nHello " << yourName << ", you are " << yourAge << endl;


	int age;
	cout << "Enter your age: ";
	cin >> age; // When enter number (age) and the button "enter".
                // the "enter" will be stored into the fullName (getline)

	cin.ignore(); // ignore the character "enter"

	cout << "Enter your name: ";
	char fullName[200];
	cin.getline(fullName, 199); // the last character is null
                // the max number = elements of array (200) - 1 (null)

	cout << "\nHello " << fullName << ", you are " << age << endl;

	return 0;
}