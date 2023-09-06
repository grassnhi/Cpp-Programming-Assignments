#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variable declaration
    string food = "Chicken"; // A food variable of type string
    
    // Pointer declaration
    string* ptr = &food;    

    // Output the value of food (Chicken)
    cout << food << "\n";
    
    // Output the memory address of food 
    cout << &food << "\n";
    
    // Output the memory address of food with the pointer 
    cout << ptr << "\n";
    cout << *ptr << "\n";

    return 0;
}
