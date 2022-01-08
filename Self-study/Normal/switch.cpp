// Branching structure

#include <iostream>
using namespace std;

int main(){
    char choice = ' ';

    cout << "Is Nhi beautiful?\n";
    cout << "A. Yes\n" << "B. No\n" << "C. Don't know\n";
    cout << "Your choice" << endl;

    cin >> choice;

    switch(choice){
        case 'A':
        case 'a':
            cout << "Right!" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Wrong! Let try again." << endl;
            break;
        case 'C':
        case 'c':
            cout << "Thank you!" << endl;
            break;
        default:
            cout << "Invalid answer!" << endl;
            break;
    }
    
    return 0;
}