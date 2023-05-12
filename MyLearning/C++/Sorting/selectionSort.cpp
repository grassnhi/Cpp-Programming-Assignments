#include <iostream>
using namespace std;

template<class T>
void selectionSort(T data[], int n){
    for (int i = 0, j, least; i < n-1; i++){
        for (j = i + 1, least = i; j < n; j++){
            if (data[j] < data[least]){
                least = j;
            }
        }            
        swap(data[least], data[i]);
    }
} 

int main(){
    int array[9] = {0, 4, 1, 6, 2, 5, 8, 3, 7};
    selectionSort(array, 9);  // Passing Array Directly 
    
    for(int i = 0; i < 9; i++) // Printing Sorted Array
        cout << array[i] << " ";
    
    return 0;
}
