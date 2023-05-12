#include <iostream>

using namespace std;

int finding(int a[][100], int row, int col){
    int horse = 0;
    int max, min;
    int r = 0, c = 0;
 
    for (int i = 0; i < row; i++)
    {
        max = a[i][0];
        
        for (int j = 1; j < col; j++){
            // Find maximum in a row
            if (max < a[i][j]){
                max = a[i][j];
                c = j;
            }
        }
 
        // Find minimum in a column col
        min = a[0][c];

        for (int i = 1; i < row; i++){
            if (min > a[i][c]){
                min = a[i][c];
            }
        }
 
        // Compare maximum in row and minimm in column
        if (max == min){
            horse++;
        }
    }
 
    return horse;
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

    cout << finding(a, row, col);

    return 0;
}