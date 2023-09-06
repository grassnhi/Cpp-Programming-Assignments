/*
Implement the following function:
            void findMax(int *ptr, int n);

Reverse the 1-dimension array given by a pointer.

Where:
    ptr is a pointer to the first element in the array.
    n is the size of the array.

Note: 
    You need to use the dereference operator (*) to get the values of the elements in the array. 
    The subscript operator ([]) cannot be used.
*/

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *ptr, int n)
{
    for (int i = 0; i < n/2; ++i) {
        swap(*(ptr + i), *(ptr + n - i - 1));
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, sizeof(arr) / sizeof(arr[0]));
    cout << arr[0];
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << ", " << arr[i];
    }
}