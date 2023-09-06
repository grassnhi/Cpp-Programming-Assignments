/*
Implement the following function:
        bool isSymmetry(int *head, int *tail);

Checks if the 1-dimensional array is a symmetric array.

Where:
    head, tail respectively are pointers to the first element and last element of the array.
*/

#include <iostream>

using namespace std;

bool isSymmetry(int *head, int *tail)
{
    if(*head == *tail || *tail - *head == 1)
        return true;
    int i = 0;
    bool check = true;
    while( *head + i < *tail - i){
        if(*(head+i)!=*(tail-i)){
            check = false;
            break;
        }else{
            i++;
        }
    }
}

int main(){
    int arr[] = {1, 2, 1};
    cout << isSymmetry(arr, arr + (sizeof(arr) / sizeof(arr[0])) - 1);
}