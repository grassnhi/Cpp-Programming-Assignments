/*
Write function findMax to find the maximum of an input integer array.

Input:
    int* vals: array of integers
    int numEls: the size of the array.

Output:
    int: the maximum value in the array vals
*/

#include <iostream>

using namespace std;

int findMax(int *vals, int numEls) {
    int i;
     
    int max = vals[0];
 
    for (i = 1; i < numEls; i++){
        if (vals[i] > max)
            max = vals[i];
    }
    
    return max;
}

int main(){
    // need to learn more;
}