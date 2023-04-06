/*
Implement static method selectionSort in class Sorting to sort an array in ascending order.  After each selection, we will print out a list to check (using printArray). 


#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */ /*
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

*/



/*
Test	Result
int arr[] = {9, 2, 8, 1, 0, -2};
Sorting<int>::selectionSort(&arr[0], &arr[6]);
-2, 2, 8, 1, 0, 9
-2, 0, 8, 1, 2, 9
-2, 0, 1, 8, 2, 9
-2, 0, 1, 2, 8, 9
-2, 0, 1, 2, 8, 9

*/