#include <iostream>
using namespace std;

template<class T>
void insertionSort(T data[], int n){
    for (int i = 1, j; i < n; i++){
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--){
            data[j] = data[j-1];
        } 
        data[j] = tmp;
    }
} 


int main(){
    int array[9] = {0, 4, 1, 6, 2, 5, 8, 3, 7};
    insertionSort(array, 9);  // Passing Array Directly 
    
    for(int i = 0; i < 9; i++) // Printing Sorted Array
        cout << array[i] << " ";
    
    return 0;
}
