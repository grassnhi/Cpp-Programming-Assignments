/*
QuickSort is one of the fastest sorting algorithms for sorting large data. When implemented well, it can be about two or three times faster than its main competitors, such as MergeSort and HeapSort. When the number of elements is below some threshold (min_size), switch to insertion sort - non-recursive sorting algorithm that performs fewer swaps, comparisons or other operations on such small arrays.

Implement static methods hybridQuickSort in class Sorting to sort an array in ascending order. If you do insertion sort, please print "Insertion sort: array" (using printArray) first. If you do quick sort, please print "Quick sort: array (using printArray)" first. Please read example carefully to know exactly what we print.

To match the test cases, please note:

Using first element as pivot
Recursively call the hybridQuickSort function to the left of the pivot first, then recursively to the right of the pivot
Do insertion sort if sub array size smaller than min_size
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
*/

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
    T pivot = *start;
    T *left = start+1;
    T *right = end;
    
    while (true) {
        while (*left < pivot) {
            left++;
        }
        
        right--;
        while (*right > pivot) {
            right--;
        }
        
        if (left >= right) {
            T temp = *start;
            *start = *right;
            *right = temp;
            return right;
        }
        
        T temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
    }
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
        hybridQuickSort(pivot+1, end, min_size);
    }
}

int main(){
    int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    int min_size = 4;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
}

/*
Test	Result
int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
int min_size = 4;
Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
Quick sort: 1, 2, 6, 4, 7, 8, 5, 3
Quick sort: 2, 6, 4, 7, 8, 5, 3
Quick sort: 6, 4, 7, 8, 5, 3
Insertion sort: 5, 4, 3
Insertion sort: 8, 7
int array[] = {2, 6, 4, 12, 23, 1, 0, -12};
int min_size = 4;
Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
Quick sort: 2, 6, 4, 12, 23, 1, 0, -12
Insertion sort: 1, -12, 0
Quick sort: 23, 12, 4, 6
Insertion sort: 6, 12, 4
int array[] = {30, 7, 20, 0, -13, 1, 19, 72};
int min_size = 3;
Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
Quick sort: 30, 7, 20, 0, -13, 1, 19, 72
Quick sort: 19, 7, 20, 0, -13, 1
Quick sort: -13, 7, 1, 0
Quick sort: 7, 1, 0
Insertion sort: 0, 1
Insertion sort: 20
Insertion sort: 72
*/