/*
Implement the following function:
        int findMax(int *ptr, int n);

Find and return the maximum element of a 1-dimension array given by a pointer.

Where:
    ptr is a pointer to the first element in the array.
    n is the size of the array.
*/

#include <iostream>

using namespace std;


int findMax(int *ptr, int n)
{
    
    int max = *ptr;

    for (int i = 1; i < n; i++){
        if (*(ptr + i) > max)
            max = *(ptr + i);
    }

    return max;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    
    cout << findMax(arr, sizeof(arr) / sizeof(arr[0]));
}