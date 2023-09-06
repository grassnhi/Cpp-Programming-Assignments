/*
Implement the following function:
        void swap(int *ptr2, int *ptr2);
Swap the value at the position that 2 pointers point to.

Where:
    ptr1, ptr2 respectively are pointers to swapping positions.
*/

#include <iostream>

using namespace std

void swap(int *ptr1, int *ptr2){
    int tmp;
    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

int main(){
    int a = 5;
    int b = 6;

    swap(&a, &b);

    cout << a << " " << b;
}