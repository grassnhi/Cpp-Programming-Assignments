#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){

}

int main(){
    int E3, EXP1, EXP2, HP1, M1;

    cin >> E3 >> HP1 >> EXP1 >> M1;

    cout << traceLuggage(HP1, EXP1, M1, E3)<< endl;
    cout << "HP1 = " << HP1 << "  EXP1 = "<< EXP1 << "  M1 = " << M1 << endl;
    
    return 0;
}

