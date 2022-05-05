/*
Write the function bool completeNum(int N) that checks if a positive integer N is a complete number. 
N is a complete number if and only if N is equal to the sum of all of its positive divisors (excluding itself)

Input: 
    int N: positive integer N to be checked

Output:
    bool: return true if N is a complete number, otherwise return false
*/

#include <iostream>

using namespace std;

bool completeNum(int N){
    long long int sum = 1;
  
    for (long long int i = 2; i*i <= N; i++){
        if(N % i == 0){
            if(i*i != N)
                sum = sum + i + N/i;
            else
                sum = sum + i;
        }
    }

    if (sum == N && N != 1)
        return true;
  
    return false;
}

int main(){
    int N;
    cin >> N;

    cout << completeNum(N);

    return 0;
}