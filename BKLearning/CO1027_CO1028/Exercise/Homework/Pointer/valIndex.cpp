/*
Implement the following function:
        int getValueAtIndex(int *ptr, int k);
Return value at the position of the index number through pointer.

Where:
    ptr is a pointer to the first element in the array.
    k is the access position (this value does not exceed the length of the array).
*/

#include <iostream>

using namespace std

int getValueAtIndex(int *ptr, int k){
    return *(ptr + k);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    int k = 3;

    cout << getValueAtIndex(arr, k);

    return 0;
}