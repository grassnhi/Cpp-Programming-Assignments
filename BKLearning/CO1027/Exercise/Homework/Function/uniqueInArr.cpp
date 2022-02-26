/*
Write a function that determines if the elements in the given array is unique

Input:
    int* arr: array of integer
    int n: the size of the array

Output:
    bool: return true if the elements in arr is unique, otherwise return false

Note: 
    arr[i] is in the range of [0, 1000]
*/

#include <iostream>

using namespace std;

bool checkElementsUniqueness(int* arr, int n) {
    for (int i=0; i<n; i++){
        for ( int j=0; j<i; j++)
           if (arr[i] == arr[j])
               return false;
    }
    return true;
}

int main(){
    int n;
cin >> n;
int* arr = new int[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
cout << checkElementsUniqueness(arr, n);
delete[] arr;
}