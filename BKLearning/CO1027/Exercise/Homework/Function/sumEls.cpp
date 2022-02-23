/*
Write the function sum2 that calculates the total of all elements in an integer array

Parameters:
    int* array: an array of integers
    int size: the number of elements in the array
    int& result: a parameter to return the calculated value to the caller
*/

#include <iostream>

using namespace std

void sum2(int * array, int numEls, int &result){
    result = 0; 

    for (int i = 0; i < numEls; i++){
        result += array[i];
    }

}

int main (){
    //
}