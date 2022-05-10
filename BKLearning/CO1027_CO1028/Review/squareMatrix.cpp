/*
Given a square matrix n x n, which n is smaller than 1000. Write a function to check 
if all the sums of the diagonal lines are equal or not

Given that the diagonal line will start from the bottom left to the top right of the matrix

Illustration: 

Note: Students are not allowed to use additional libraries. Included libraries: iostream


Testcase:
Input:
int M[3][20] = 
{
{ 3, 2, 1},
{ 1, 0, -2},
{ 2, 5, 3}
};
// sum 1: {3} -> 3
// sum 2: {1, 2} -> 3
// sum 3: {2, 0, 1} -> 3
// sum 4: {5, -2} -> 3
// sum 5: {3} -> 3
int n = 3;
Output: 1
*/

#include<iostream>

using namespace std;

bool isDSumsEqual (int n, int matrix[][20]){
    int DSum [2*n-1]{0};
    for (int i = 0; i < 2*n-1; i++){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (x+y == i) DSum[i] += matrix[x][y];
            }
        }
        if (DSum[i]!=DSum[0]) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    int matrix[n][20];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cout << isDSumsEqual(n, matrix);
}