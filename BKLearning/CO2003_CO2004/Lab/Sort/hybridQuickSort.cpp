#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    T *pivot = start;
    T *lower = start + 1;
    T *upper = end; 
    while (lower <= upper){
        while (*pivot > *(lower)){
            lower++;
        }
            
        while (*pivot < *(upper)){
            upper--;
        }
           
        if (lower < upper){
            swap(*(lower),*(upper));
        }
        else lower++;
        swap(*start, *upper);
    }
    
    return pivot;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    for (T* i = start + 1, *j; i < end; ++i) {
        T tmp = *i;
        for (j = i; j > start && tmp < *(j-1); j--){
            *j = *(j-1);
        } 
        *j = tmp;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    if(end - start < 1) return; 
    if(end - start < min_size){
        cout << "Insertion sort: ";
        printArray(start, end);
        insertionSort(start, end);
    }else{
        cout << "Quick sort: ";
        printArray(start, end);
        T *pivot = Partition(start, end);
        hybridQuickSort(start, pivot, min_size);
        hybridQuickSort(pivot + 1, end, min_size);
    }
}

int main(){
    int array[] = {2, 6, 4, 12, 23, 1, 0, -12};
    int min_size = 4;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
}

/*
Quick sort: 2, 6, 4, 12, 23, 1, 0, -12
Insertion sort: 1, -12, 0
Quick sort: 23, 12, 4, 6
Insertion sort: 6, 12, 4
*/