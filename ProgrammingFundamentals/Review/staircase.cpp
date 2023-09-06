/*
Given a staircase with k steps (k is a positive integers), 
calculate the number of ways for An to climb k steps, 
knowing that each time An will take 1 or 2 steps.

Giving that the diagonal line will start from the bottom left to the top right

Note: Students are not allowed to use additional libraries

Testcase:
Input:
int k = 4;
Output: 5
*/

#include<iostream>

int countSteps (int k){
    if (k == 1) return 1;
    else if (k == 2) return 2;
    else return countSteps(k-1) + countSteps(k-2);
}

using namespace std;

int main(){
    int k;
    cin >> k;
    cout << countSteps(k);
    return 0;
}