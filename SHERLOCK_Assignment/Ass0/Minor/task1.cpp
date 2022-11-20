#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    if( E1 < 0 || E1 > 999)
        return -999;
    else{ 
        if(EXP2 < 0) EXP2 = 0;
        if(EXP2 > 900) EXP2 = 900;

        if(EXP1 < 0) EXP1 = 0;
        if(EXP1 > 900) EXP1 = 900;

        if(E1 >= 0 && E1 < 400){
            if( E1 %2 == 0){
                EXP1 = ceil(EXP1 - E1*1.0 / 5);                
                if(EXP1 < 0) EXP1 = 0;

            } else{
                EXP1 = ceil(EXP1 + E1*1.0 / 10);
                if(EXP1 > 900) EXP1 = 900;

            }

            if(E1 >= 0 && E1 <= 49){
                EXP2 += 25;
            } else if (E1 <= 99){
                EXP2 += 50;
            } else if (E1 <= 149){
                EXP2 += 85;
            } else if(E1 <= 199){
                EXP2 += 75;
            } else if(E1 <= 249){
                EXP2 += 110;
            }else if(E1 <= 299){
                EXP2 += 135;
            }else if(E1 <= 399){
                EXP2 += 160;
            }
        }else if (E1 >= 400 && E1 <= 999){
            if(E1 <= 499){
                EXP2 = ceil(EXP2 + E1*1.0 / 7 + 9);
            }else if(E1 <= 599){
                EXP2 = ceil(EXP2 + E1*1.0 / 9 + 11);
            }else if(E1 <= 699){
                EXP2 = ceil(EXP2 + E1*1.0 / 5 + 6);
            }else if(E1 <= 799){
                EXP2 = ceil(EXP2 + E1*1.0 / 7 + 9);
                if(EXP2 > 200){
                    EXP2 = ceil(EXP2 + E1*1.0 / 9 + 11);
                }
            }else if(E1 <= 999){
                EXP2 = ceil(EXP2 + E1*1.0 / 7 + 9);
                EXP2 = ceil(EXP2 + E1*1.0 / 9 + 11);
                if(EXP2 > 600){
                    EXP2 = ceil(EXP2 + E1*1.0 / 5 + 6);
                    EXP2 = ceil(EXP2*1.15);
                }
            }
            EXP1 = ceil(EXP1 - E1*0.1);
            if(EXP1 < 0) EXP1 = 0;
        }

        if(EXP2 > 900) EXP2 = 900;
        
        int EXP = EXP1 + EXP2;

        return EXP;
    }
}
int main(){
    int EXP1, EXP2, E1;

    cin >> EXP1 >> EXP2 >> E1;

    cout << firstMeet(EXP1, EXP2, E1) << endl;
    cout << "EXP1 = " << EXP1 << "  EXP2 = " << EXP2 << endl;

    return 0;
}

