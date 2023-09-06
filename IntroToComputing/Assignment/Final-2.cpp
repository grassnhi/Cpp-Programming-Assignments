/*
Write an appropriate function (from //BEGIN TODO to //END TODO) in the code below 
to produce the required result:

#include <iostream>
using namespace std;
int numbers [10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

//BEGIN TODO

//END TODO

int main() {
    int result = sum(numbers, 10); 
    cout << result; 
    return 0;
}

Required Result: a function that takes input as an array of integer numbers and their size. 
                    This function uses a for loop to calculate the sum of all numbers 
                    at even indexes; this calculated sum is returned to be printed 
                    on the screen in main function.
                    The declaration of the global numbers array is shown below.

                    int numbers[10]= (2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

Note: main() function and libraries are provided. 
    Define the function int sum(....) to meet the demand. 
*/

#include <iostream>
using namespace std;
int numbers[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

//BEGIN TODO

int sum( int array[], int sizeofArray) {
    int s = 0;

    for (int i=0; i< sizeofArray; i +=2) {
        s += array[i];
    }

    return s;
}

//END TODO

int main() {
    int result = sum(numbers, 10); 
    cout << result; 
    return 0;
}