/*
Implement the function  int* zeros(int n) which can create an array with n zero element.

Input: 
    The array size n.

Output: 
    The pointer that points to the allocated array.

Note: 
    In the case of failed allocation, the function will return nullptr value.
*/

#include<iostream>

using namespace std;

int* zeros(int n) {
    // TODO
    if(n<=0) return nullptr;

    int *p = new int[n];

    for(int i = 0; i < n; i++){
        *(p+i)=0;
    }

    return p;
}

int main(){
    int n;
    cin >> n;
    
    zeros(n);
}
