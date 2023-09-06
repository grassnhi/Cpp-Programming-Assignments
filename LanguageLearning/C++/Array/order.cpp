#include<iostream>
using namespace std;

void Display(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int a[], int n){
    int k = 1;

    bool flag;

    do{
        flag = 0;

        for(int i = 0; i < n - k; i++){
            if(a[i] > a[i+1]){
                int x = a[i];
                a[i] = a[i+1];
                a[i+1] = x;

                flag = 1;
            }
        }
        k = k + 1;
    } while(flag);
}

int main(){
    int n = 9;
    int a[] = {6, 3, 2, 7, 1, 9, 5, 4, 8};
    Display(a, n);

    BubbleSort(a, n);
    Display(a, n);

    return 0;
}