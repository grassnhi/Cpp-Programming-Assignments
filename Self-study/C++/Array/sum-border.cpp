#include <iostream>

using namespace std;

// Sum of elements in the border of matrix

int sum(int a[][100], int row, int col){
    int sum = 0;

    for(int i = 0; i < row; i++){
        sum += a[i][0] + a[i][col-1];
    }

    for(int j = 0; j < col; i++){
        sum += a[0][j] + a[row-1][j];
    }

    return sum;
}

int main(){
    int a[100][100];
    int row, col;

    cin >> row >> col;
    for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> a[i][j];
		}
	}

    cout << sum(a, row, col);

    return 0;
}
