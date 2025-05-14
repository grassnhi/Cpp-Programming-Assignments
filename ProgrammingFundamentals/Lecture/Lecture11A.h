// the right after const is the type of const
// const int* ptr1 -> int value is const, can change address only
// int const *ptr1 -> int value is const, can change address only
// int* const ptr1 -> pointer is constant, can only change value
// const int* const ptr1 -> int value & pointer are constant, cannot change anything

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

void demo1() {
    int x = 10, y = 20, z = 30;
    const int * ptr1 = &x;
    ptr1 = &y;
    // *ptr1 = 20 // Compilation error
    cout << "*ptr1 = " << *ptr1 << endl;

    int const * ptr2 = &y;
    ptr2 = &x;
    // *ptr2 = 40; // Compilation error
    cout << "*ptr2 = " << *ptr2 << endl;

    int* const ptr3 = &x;
    *ptr3 = 40;
    // ptr3 = &y; // Compilation error;
    cout << "*ptr3 = " << *ptr3 << endl;

    const int * const ptr4 = &z;
    // ptr4 = &x // Compilation error
    // *ptr4 = 50 // Compilation error
    cout << "*ptr4 = " << *ptr4 << endl;
}
// int * const * p; // ????????????