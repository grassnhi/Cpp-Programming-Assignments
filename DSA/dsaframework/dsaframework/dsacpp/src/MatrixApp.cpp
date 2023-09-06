#include <iostream>
#include <iomanip>
using namespace std;

#include "util/ArrayLib.h"

int main(int argc, char** argv){
    Matrix<int> m(3, 4, Matrix<int>::INT32);
    m.binomial(0.5, true, 2021);
    //m.uniform(-10, 10, true, 2021);
    m.println();
    for(int r=0; r < m.rows(); r++){
        int* ptr = m.ptr(r, 0);
        for(int c=0; c < m.cols(); c++){
            cout << ptr[c] << " ";
            m.set(r,c, 999);
        }
        cout << endl;
    }
    
    cout << endl;
    for(int r=0; r < m.rows(); r++){
        for(int c=0; c < m.cols(); c++)
            cout << m.get(r,c)<< " ";
        cout << endl;
    }
    return 0;
}