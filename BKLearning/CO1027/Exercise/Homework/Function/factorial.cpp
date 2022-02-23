/*
Implement a function that calculates the factorials of N. 
Then call that function inside the main function to assign the calculated value to the variable result.

Input:      int N:   a natural number N
*/

#include <iostream>

using namespace std;
// implement calculate factorial function in here
long factorial(int number){
    if (number == 0) 
        return 1;
    else               
        return number * factorial( number - 1 );
}

int main(int narg, char** argv){
    int N;
    cin >> N;

    long result;

    // call function calculateFactorial in here and assign value to the variable result
    result = factorial(N);
    
    cout << result << endl;
    
    return 0;
}