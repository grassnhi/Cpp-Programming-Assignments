#include<iostream>
using namespace std;

const int KTHAY = -1; 

void Display(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int SequentialSearch(int a[], int n, int x){
    int chiSo = KTHAY;

    bool found = 0;

    int i = 0;
    while ((i < n) && (!found))
    {
        if(a[i] == x){
            found = 1;
            chiSo = i;
        }
        else    
            i++;
    }

    return chiSo;
}

int BinarySearch(int a[], int n, int x){
    int chiSo = KTHAY;

    bool found = 0;

    int i = 0; 
    int j = n-1;
    while ((i <= j) && (!found)){
        int k = (i+j) / 2;

        if(x < a[k]){
            j = k - 1;
        }
        else if(x == a[k]){
            found = 1;
            chiSo = k;
        }
        else
            i = k + 1;
    }

    return chiSo;
}

int main(){
    int n = 9;
    int a[] = {6, 3, 2, 7, 1, 9, 5, 4, 8};
    Display(a, n);

    int x = 7;
    int pos = SequentialSearch(a, n, x);

    if(pos == KTHAY)
        cout << "Not found " << x << endl;
    else 
        cout << pos << endl;


    pos = BinarySearch(a, n, x);

    if(pos == KTHAY)
        cout << "Not found " << x << endl;
    else 
        cout << pos << endl;

    return 0;
}