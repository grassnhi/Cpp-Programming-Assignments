/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

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
            EXP2 = ceil(EXP2+E2*1.0/9 + 10);
            EXP1 = ceil(EXP1+(E2*1.0/9 + 10)/3);
        }else if(E2 <= 499){
            EXP2 = ceil(EXP2+E2*1.0/9 + 10);
            EXP1 = ceil(EXP1+(E2*1.0/9 + 10)/3);
            EXP2 = ceil(EXP2 + E2*0.35);
            EXP1 = ceil(EXP1+(E2*0.35)/3);
        }else if(E2 <= 999){
            EXP2 = ceil(EXP2+E2*1.0/9 + 10);
            EXP1 = ceil(EXP1+(E2*1.0/9 + 10)/3);
            EXP2 = ceil(EXP2 + E2*0.35); 
            EXP1 = ceil(EXP1+(E2*0.35)/3);
            EXP2 = ceil(EXP2*1.17);
            EXP1 = ceil (EXP1 + EXP2*0.17/3);
        }

        HP2 = ceil(HP2 - pow(E2,3)*1.0/pow(2,23));

        if(E2%2==0){
            M2 = ceil(M2+pow(E2,2)*1.0/50);
        }

        if(EXP2 > 900) EXP2 = 900;
        
        if(HP2 < 0) HP2 = 0;
    
        if(EXP1 > 900) EXP1 = 900;
        
        if(M2 > 2000) M2 = 2000; 
        
        return (EXP2+HP2+M2+EXP1);

    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    return -1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
