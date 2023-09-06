#include <iostream>
using namespace std;

template<class T>
void bubbleSort(T data[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = n - 1; j > i; --j){
            if (data[j] < data[j-1]){
                swap(data[j], data[j-1]);
            }
        }
    }              
} 


int main(){
    int array[9] = {0, 4, 1, 6, 2, 5, 8, 3, 7};
    bubbleSort(array, 9);  // Passing Array Directly 
    
    for(int i = 0; i < 9; i++) // Printing Sorted Array
        cout << array[i] << " ";
    
    return 0;
}
