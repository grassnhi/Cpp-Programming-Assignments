/*
Implement the following function:
            int calcSum(int *ptr, int n);

Calculate and return the sum of elements of a 1-dimension array given by a pointer.

Where:
    ptr is a pointer to the first element in the array.
    n is the size of the array.

Note: 
    You need to use the dereference operator (*) to get the values of the elements in the array. 
    The subscript operator ([]) cannot be used.
*/

#include <iostream>

using namespace std;

int calcSum(int *ptr, int n)
{
  
    int sum = 0; 
    for (int i = 0; i < n; i++){
        sum += *ptr;
        ptr++;
}
    return sum;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    
    cout << calcSum(arr, sizeof(arr) / sizeof(arr[0]));
}