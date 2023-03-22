#include <iostream>
using namespace std;

template<class T> 
void quickSort(T data[], int first, int last){
    int lower = first + 1, upper = last;

    swap(data[first], data[(first + last) / 2]);

    T bound = data[first];

    while (lower <= upper){
        while (bound > data[lower]){
            lower++;
        }
            
        while (bound < data[upper]){
            upper--;
        }
           
        if (lower < upper){
            swap(data[lower++],data[upper--]);
        }
        else lower++;
    }

    swap(data[upper],data[first]);

    if (first < upper-1){
        quickSort (data,first,upper-1);
    }
        
    if (upper+1 < last){
        quickSort (data,upper+1,last);
    }

} 

template<class T> 
void quickSort(T data[], int n){
    int i, max;

    if (n < 2){
        return;
    }
        
    for (i = 1, max = 0; i < n; i++){ // find the largest
        if (data[max] < data[i]){ // element and put it
            max = i; // at the end of data[];
        }       
    }   

    swap(data[n-1],data[max]); // largest el is now in its

    quickSort(data,0,n-2);     // final position; 
} 


int main(){
    int array[9] = {0, 4, 1, 6, 2, 5, 8, 3, 7};
    quickSort(array, 0, 7);  // Passing Array Directly 
    
    for(int i = 0; i < 9; i++) // Printing Sorted Array
        cout << array[i] << " ";
    
    return 0;
}
