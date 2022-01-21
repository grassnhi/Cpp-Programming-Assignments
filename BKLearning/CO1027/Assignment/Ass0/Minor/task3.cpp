#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    if( E3 < 0 || E3 > 999)
            return -999;
        else{ 
            int P1[9]= {1,3,5,7,9,11,13,15,17};
            for(int i=0; i<9; i++){
                P1[i] = (P1[i]+E3)%26 + 65;
                if (P1[i]==80){
                    
                }
            }
    }
}

int main(){
    int E3, EXP1, EXP2, HP1, M1;

    cin >> E3 >> HP1 >> EXP1 >> M1;

    cout << traceLuggage(HP1, EXP1, M1, E3)<< endl;
    cout << "HP1 = " << HP1 << "  EXP1 = "<< EXP1 << "  M1 = " << M1 << endl;
    
    return 0;
}

