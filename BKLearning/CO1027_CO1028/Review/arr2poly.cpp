#include<iostream>

using namespace std;

int maxP(int* a, int* b, int n){
    int res = 0, max = res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res = a[i] - a[j] + b[i] + b[j];
            if(res > max){
                max = res;
            }
        }
    }
    return max;
}

int main(){
    int a[] = {0, 1, 2,3 , 4, 5, 6, 7, 8, 9, 10};
    int b[] = {1, 3, 7, 4, 2, 9, 10, 1, 2, 4, 0};
    cout << maxP(a, b, 11);
    return 0;
}