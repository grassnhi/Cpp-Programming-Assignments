/*
Write an appropriate function to produce the required result. 
You must also provide an example of the function call to the function you write, 
demonstrating the correct syntax used.

Required Result: 
Display on the screen the name and attributes (attack, defense, health) of an 
RPG player character (displayRPGCharDetails) ((each piece of information is on a separate line). 
State any assumptions if you have.

Note: main() function and libraries are provided. 
Define the function void displayRPGCharDetails(...) to meet the demand.
*/

#include <iostream>
#include <string>

using namespace std;

void displayRPGCharDetails (string n, int a, int d, int h ){
    cout << "name: "<< n << endl;
    cout << "attack: " << a << endl;
    cout << "defense: " << d << endl; 
    cout << "health: "<< h << endl;
}

int main(){
    displayRPGCharDetails("Bill", 15, 20, 200);
}