#include <iostream>
#include <string>

using namespace std;

int main() {

/*

    int a = 5;
    int b = 9;

    int *ptr = &a;
    
    *ptr = 6;               // OK
    ptr = &b;               // OK


*/

/*

    const int a = 5;
    const int b = 9;

    int* const ptr = &a;

    *ptr = 6;               // Error
    ptr = &b;               // Error

*/

/*

    const int a = 5;
    int b = 9;
    const int *ptr = &a;

    *ptr = 6;               // Error
    ptr = &b;               // OK


*/
    int a = 5;
    int b = 9;
    
    cout << a << endl;
    cout << &a << endl;
    
    int* ptr = &a;
    
    *ptr = 6; 
    
    cout << a << endl;
    
    ptr = &b; 
    
    cout << a << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    
    return 0;
}
