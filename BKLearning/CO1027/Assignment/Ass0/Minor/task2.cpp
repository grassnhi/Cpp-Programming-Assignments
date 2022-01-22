#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    if( E2 < 0 || E2 > 999)
        return -999;
    else{
        if(EXP2 < 0) EXP2 = 0;
        if(EXP2 > 900) EXP2 = 900;
        
        if(HP2 < 0) HP2 = 0;
        if(HP2 > 999) EXP2 = 999;
    
        if(EXP1 < 0) EXP1 = 0;
        if(EXP1 > 900) EXP1 = 900;
        
        if(M2 > 2000) M2 = 2000; 
        if(M2 < 0)  M2 = 0;

        if(E2 >= 0 && E2 <= 299){
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1 + (E2*1.0 / 9 + 10) / 3);
        }else if(E2 <= 499){
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1+ (E2*1.0 / 9 + 10) / 3);
            EXP2 = ceil(EXP2 + E2*0.35);
            EXP1 = ceil(EXP1 + (E2*0.35) / 3);
        }else if(E2 <= 999){
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1+(E2*1.0 / 9 + 10) / 3);
            EXP2 = ceil(EXP2 + E2*0.35); 
            EXP1 = ceil(EXP1 + (E2*0.35) / 3);
            EXP2 = ceil(EXP2*1.17);
            EXP1 = ceil (EXP1 + EXP2*0.17/3);
        }

        HP2 = ceil(HP2 - pow(E2, 3)*1.0 / pow(2, 23));

        if(E2 % 2 == 0){
            M2 = ceil(M2 + pow(E2, 2)*1.0 / 50);
        }

        if(EXP2 > 900) EXP2 = 900;
        
        if(HP2 < 0) HP2 = 0;
    
        if(EXP1 > 900) EXP1 = 900;
        
        if(M2 > 2000) M2 = 2000; 
        
        return (EXP2 + HP2 + M2 + EXP1);

    }
}

int main(){
    int E2, EXP1, EXP2, HP2, M2;

    cin >> E2 >> EXP1 >> EXP2 >> HP2 >> M2;

    cout << investigateScene(EXP1, EXP2, HP2, M2, E2)<< endl;
    cout << "EXP1 = " << EXP1 << "  EXP2 = "<< EXP2 << "  HP2 = " << HP2 << "  M2 = " << M2 << endl;

    return 0;
}

