#include<iostream>

using namespace std;

int main(){
    int intArray[] = {1, 2, 3};
    int *p = intArray;

    cout << ++*p;
    
    return 0;
}