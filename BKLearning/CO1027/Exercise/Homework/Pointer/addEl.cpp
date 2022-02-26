/*
Implement the following function:
        void add(int *ptr, int n, int k);

Insert element to the end of the 1-dimension array given by a pointer.

Where:
    ptr is a pointer to the first element in the array.
    n, k respectively is the size of the array and the element that need to be added.
*/

#include <iostream>

using namespace std;

void add(int *ptr, int n, int k)
{
    int i;
    n++;
    for (i = n-2; i >= 0; i--)
        ptr[i] = ptr[i-1];

    ptr[n-1] = k;
}

int main(){
    int arr[100] = {1, 2, 3, 4, 5};
int n = 5;
int k = 7;
add(arr, n, k);
cout << arr[n];
}