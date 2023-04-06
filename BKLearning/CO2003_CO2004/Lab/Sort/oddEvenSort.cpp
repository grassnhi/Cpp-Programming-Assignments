/*
Implement static method oddEvenSort in class Sorting to sort an array in ascending order.  After each selection, we will print out a list to check (using printArray method). Remember to sort even first.

Remind about odd even sort: 

This algorithm is divided into two phases - odd and even Phase. The algorithm runs until the array elements are sorted and in each iteration two phases mentioned above occurs.
In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase, we perform a bubble sort on even indexed elements.
#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array *//*
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

*/

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    /*TODO*/
    int n = end-start;
    bool check = false;
    while(check != true){
        check = true;
        for(int i = 0 ; i+1 < n; i+=2){
            if(start[i] > start[i+1]){
                T temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                check = false;
            }
        }
        for(int i = 1; i+1 < n; i+=2){
            if(start[i] > start[i+1]){
                T temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                check = false;
            }
        }
        printArray(start,end);
    }
}

/*
Test	Result
int arr[] = {3, 2, 3, 8, 5, 6, 4, 1};
Sorting<int>::oddEvenSort(&arr[0], &arr[8]);
2, 3, 3, 5, 8, 1, 6, 4
2, 3, 3, 1, 5, 4, 8, 6
2, 1, 3, 3, 4, 5, 6, 8
1, 2, 3, 3, 4, 5, 6, 8
1, 2, 3, 3, 4, 5, 6, 8

*/