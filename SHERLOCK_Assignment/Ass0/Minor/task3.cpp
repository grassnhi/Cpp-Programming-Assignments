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
        if(EXP1 < 0)        EXP1 = 0;
        if(EXP1 > 900)      EXP1 = 900;
        
        if(M1 < 0)          M1=0;
        if(M1 > 200)        M1 = 2000;
        
        if(HP1 < 0)         HP1=0;
        if(HP1 > 999)       EXP1 = 999;
                
        int road1 = 0, road2 =0, road3 = 0, road4 = 0;
        int P1[9]= {1, 3, 5, 7, 9, 11, 13, 15, 17};

        for(int i = 0; i < 9; i++){
            P1[i] = (P1[i] + E3) % 26 + 65;

            if (P1[i] == 80){
                road1++;

                HP1 -= P1[i]*(i + 1)*2;
                EXP1 += (1000 - P1[i]*(i + 1) % 101);
                M1 = ceil(M1 - (i + 1)*E3 / 9);

                if(EXP1>900)    EXP1 = 900;
                if(M1<0)    M1=0;
                if(HP1<0)   HP1=0;
            }
        }
        if(road1 == 0){
            M1= ceil(M1 - 9*9*E3 / 9);
            if(M1<0)    M1=0;
        }    
            
        int P2[7]={2, 3, 5, 7, 11, 13, 17};
        int s = 0, m = 0;

        for(int i = 0; i < 7; i++){
            P2[i] = (P2[i]*E3) % 26;
            s += P2[i];
        }

        m = ceil(s*1.0 / 7);

        for(int i = 0;i < 7; i++){
            P2[i] = (P2[i] + s + m) % 26 + 65;

            if(P2[i] == 80){
                road2++;

                HP1 -= P2[i]*(i + 1)*2;
                EXP1 += (1000 - P2[i]*(i + 1) % 101);
                M1 = ceil(M1-(i + 1)*E3 / 9);

                if(EXP1>900)    EXP1 = 900;
                if(M1<0)    M1=0;
                if(HP1<0)   HP1=0;
            }
        }
        if(road2 == 0){
            M1= ceil(M1 - 7*7*E3 / 9);
            if(M1<0)    M1=0;
        }    
       
        int P3[20];
        int n = 2;

        for(int i = 0; i < 20; i++){
            P3[i] = n*n;
            n += 2;
            P3[i]=(P3[i] + E3*E3) % 113;
        }

        int max = P3[0];

        for(int i = 1; i < 20; i++){
            if(P3[i] > max){
                max = P3[i];
            }
        }

        for(int i = 0; i < 20; i++){
            int a = (ceil((P3[i]+E3)*1.0 / max));

            P3[i] = a % 26 + 65;

            if(P3[i] == 80){
                road3++;

                HP1 -= P3[i]*(20 - i)*3;
                EXP1 += (3500 - P3[i]*(20 - i) % 300);
                M1 = ceil(M1 - (20 - i)*E3 / 9);

                if(EXP1>900)    EXP1 = 900;
                if(M1<0)    M1=0;
                if(HP1<0)   HP1=0;
            }
        }

        if(road3 == 0){
            M1 = ceil(M1 - 20*20*E3 / 9);
            if(M1<0)    M1=0;
        }             
        
        int P4[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int b = (P4[0]+ pow(ceil(E3*1.0/29),3));
        P4[0] = b % 9;

        int min = P4[0];
        int idx = 1;

        for(int i = 1;i < 12; i++){
            int c = (P4[i] + pow(ceil(E3*1.0 / 29), 3));
            P4[i] = c % 9;

            if(min > P4[i]){
                min = P4[i];
                idx = i + 1;
            }
        }

        for(int i = 0; i < 12; i++){
            int d = (P4[i] + E3)*ceil(min*1.0 / idx);
            P4[i] = d % 26 + 65;

            if(P4[i] == 80){
                road4++;

                HP1 -= P4[i]*(12 - i)*4;
                EXP1 += (4500 - P4[i]*(12 - i) % 400);
                M1 = ceil(M1 - (12 - i)*E3 / 9);

                if(EXP1>900)    EXP1 = 900;
                if(M1<0)    M1=0;
                if(HP1<0)   HP1=0;
            }            
        }
        if(road4 == 0){
            M1 = ceil(M1 - 12*12*E3 / 9);
            if(M1<0)    M1=0;
        }    
        
        if((road1 + road2 + road3 + road4) == 0){
            HP1 -= (59 * E3) % 900;
            if(HP1 < 0)   HP1 = 0;

            EXP1 -= (79*E3) % 300;
            if(EXP1 < 0)  EXP1 = 0;
            
            return -1;
        }
        else{
            return HP1 + EXP1 + M1;
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

