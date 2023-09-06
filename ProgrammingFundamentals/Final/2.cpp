#include<iostream>

using namespace std;

int** specialMatrix(int** mat, int nRow, int nCol) {
    int** newMat = new int*[nRow];
    for(int i = 0; i < nRow; i++) {
        newMat[i] = new int[nCol];
    }
    for(int i = 0; i < nRow; i++){
        for(int j = 0; j < nCol; j++){
          newMat[i][j] =   
        }
    }
    return newMat;
}

 int main(){
    int nRow, nCol;
    cin >> nRow >> nCol;
    int** mat = new int*[nRow];

    for(int i = 0; i < nRow; i++) {
        mat[i] = new int[nCol];
        for(int j = 0; j < nCol; j++) {
            cin >> mat[i][j];
        }
    }

    int** res = specialMatrix(mat, nRow, nCol);
    for(int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i = 0; i < nRow; i++) {
        delete[] mat[i]; 
    }
    delete[] mat;
    return 0;
}