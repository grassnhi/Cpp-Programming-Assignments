#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
};

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    /*TODO*/
    bool sorted = false;
    int size = end - start;
    
    while (!sorted) {
        sorted = true;
        
        for (int i = 1; i < size - 1; i += 2) {
            if (start[i] > start[i+1]) {
                swap(start[i], start[i+1]);
                sorted = false;
            }
        }
        
        for (int i = 0; i < size - 1; i += 2) {
            if (start[i] > start[i+1]) {
                swap(start[i], start[i+1]);
                sorted = false;
            }
        }
        printArray(start, end);
    }
}


int main(){
    int arr[] = {3, 2, 3, 8, 5, 6, 4, 1};
    Sorting<int>::oddEvenSort(&arr[0], &arr[8]);
}

/*
2, 3, 3, 5, 8, 1, 6, 4
2, 3, 3, 1, 5, 4, 8, 6
2, 1, 3, 3, 4, 5, 6, 8
1, 2, 3, 3, 4, 5, 6, 8
1, 2, 3, 3, 4, 5, 6, 8
*/