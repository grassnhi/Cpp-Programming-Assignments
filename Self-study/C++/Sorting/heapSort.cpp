#include <iostream>
using namespace std;

template<class T> 
void heapSort(T data[], int n){
    for (int i = n/2 - 1; i >= 0; --i){
        moveDown (data, i, n - 1);
    }   // create a heap;
        
    for (int i = n - 1; i >= 1; --i){
        swap(data[0], data[i]); // move the largest item to data[i];
        moveDown(data, 0, i-1);  // restore the heap property;
    } 
} 



int main(){
    int array[9] = {0, 4, 1, 6, 2, 5, 8, 3, 7};
    heapSort(array, 9);  // Passing Array Directly 
    
    for(int i = 0; i < 9; i++) // Printing Sorted Array
        cout << array[i] << " ";
    
    return 0;
}
