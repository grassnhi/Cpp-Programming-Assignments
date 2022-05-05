/*
Implement the function 
        void addElement(int*& arr, int n, int val, int index) 
that inputs a dynamic array, arr, consisting of exactly n elements 
and insert a value, val, into the a specific position, index.

Input: 
    The n-size dynamic array needs to be inserted the value, val, into the specific position, index.

Output: 
    The dynamic array after insert.

Note: 
    Insertion of elements into a dynamic array must be executed by freeing the old array 
    and allocating new memory for the new one.
*/

void addElement(int*& arr, int n, int val, int index) {
    int *newArr = new int[n+1];

    *(newArr + index) = val;

    for(int i = 0; i < index; i++){
        newArr[i] = arr[i];
    }

    for(int i = index + 1; i < n+1; i++){
        newArr[i] = arr[i-1];
    }
    
    arr = newArr;
    // for(int i = n-1; i >= index; i--){
    //     arr[i+1] = arr[i];
    // }
    // arr[index] = val;
}