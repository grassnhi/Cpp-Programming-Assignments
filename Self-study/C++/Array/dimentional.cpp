type_name array_name[array_size1][array_size2]

type_name array_name[array_size1][array_size2] = initializer_list;

// Truy xuất:

array_name[index1][index2]

// => Example:

#include<iostream>
using namespace std;

int main(){
    const int MAXM = 3;
    const int MAXN = 4;

    int a[MAXM][MAXN] = {{1, 2}, {5, 6, 7, 8}, {9, 0, 1}};

    for(int i = 0; i < MAXM; i++){
        for(int j = 0; j < MAXN; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}