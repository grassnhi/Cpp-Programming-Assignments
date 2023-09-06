#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) ;

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end)
    {
        for (T *i = start + 1; i < end; ++i) {
            T key = *i;
            T *j = i - 1;
            while (j >= start && *j > key) {
                *(j + 1) = *j;
                --j;
            }
            *(j + 1) = key;
        }
    }

    static void hybridQuickSort(T *start, T *end, int min_size)
    {
        if (end - start <= 1) return;
        if (end - start <= min_size) {
            cout << "Insertion sort: ";
            printArray(start, end);
            insertionSort(start, end);
            return;
        }
        cout << "Quick sort: ";
        printArray(start, end);
        T *pivot = Partition(start, end);
        hybridQuickSort(start, pivot, min_size);
        hybridQuickSort(pivot + 1, end, min_size);
    }

    static void selectionSort(T *start, T *end);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) ;
    
};

template <class T>
T* Sorting<T>::Partition(T *start, T *end)
{
    T *pivot = start;
    T *left = start + 1;
    T *right = end - 1;
    while (left <= right) {
        while (left <= right && *left <= *pivot) ++left;
        while (left <= right && *right > *pivot) --right;
        if (left < right) {
            swap(*left, *right);
            ++left;
            --right;
        }
    }
    --left;
    swap(*pivot, *left);
    return left;
}

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    bool sorted = false;
    int size = end - start;
    
    while (!sorted) {
        sorted = true;
        
        // Odd phase
        for (int i = 1; i < size - 1; i += 2) {
            if (start[i] > start[i+1]) {
                swap(start[i], start[i+1]);
                sorted = false;
            }
        }
        printArray(start, end);
        
        // Even phase
        for (int i = 0; i < size - 1; i += 2) {
            if (start[i] > start[i+1]) {
                swap(start[i], start[i+1]);
                sorted = false;
            }
        }
        printArray(start, end);
    }
}

template <class T>
void Sorting<T>::sortSegment(T* start, T* end, int segment_idx, int cur_segment_total)
{
    // Sort the segment using insertion sort
    for (int i = segment_idx + cur_segment_total; i < end - start; i += cur_segment_total) {
        T key = start[i];
        int j = i - cur_segment_total;
        while (j >= segment_idx && start[j] > key) {
            start[j + cur_segment_total] = start[j];
            j -= cur_segment_total;
        }
        start[j + cur_segment_total] = key;
    }
}

template <class T>
void Sorting<T>::ShellSort(T* start, T* end, int* num_segment_list, int num_phases)
{
    // Calculate total number of segments
    int num_segments = 0;
    for (int i = 0; i < num_phases; i++) {
        num_segments += num_segment_list[i];
    }

    // Sort the array using Shell sort
    for (int phase = 0, segment_idx = 0; phase < num_phases; phase++) {
        int cur_segment_total = (end - start) / num_segments;
        for (int j = 0; j < num_segment_list[phase]; j++) {
            sortSegment(start, end, segment_idx, cur_segment_total);
            segment_idx += cur_segment_total;
        }
        num_segments -= num_segment_list[phase];
    }

    // Print the sorted array
    printArray(start, end);
}

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    for (T *i = start; i < end - 1; i++) {
        T *min = i;
        for (T *j = i + 1; j < end; j++) {
            if (*j < *min) {
                min = j;
            }
        }
        if (min != i) {
            swap(*i, *min);
        }
        printArray(start, end);
    }
}
