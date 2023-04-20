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

            if( E1 %2 == 0){
                EXP1 = ceil(EXP1 - E1*1.0 / 5);                
                if(EXP1 < 0) EXP1 = 0;

            } else{
                EXP1 = ceil(EXP1 + E1*1.0 / 10);
                if(EXP1 > 900) EXP1 = 900;

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
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1 + (E2*1.0 /9 + 10)*1.0 / 3);
        }else if(E2 <= 499){
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1 + (E2*1.0 / 9 + 10)*1.0/3);
            EXP2 = ceil(EXP2 + E2*0.35);
            EXP1 = ceil(EXP1 + (E2*0.35)*1.0 / 3);
        }else if(E2 <= 999){
            EXP2 = ceil(EXP2 + E2*1.0 / 9 + 10);
            EXP1 = ceil(EXP1 + (E2*1.0 / 9 + 10)*1.0 / 3);
            EXP2 = ceil(EXP2 + E2*0.35); 
            EXP1 = ceil(EXP1 + (E2*0.35)*1.0 / 3);
            EXP2 = ceil(EXP2 + (E2*1.0/9 + 10 + E2*0.35)*0.17);
            EXP1 = ceil(EXP1 + (E2*1.0/9 + 10 + E2*0.35)*0.17*1.0 / 3); 
        }

        HP2 = ceil(HP2 - pow(E2,3)*1.0/pow(2,23));

        if(E2%2==0){
            M2 = ceil(M2+pow(E2,2)*1.0/50);
        }

        if(EXP2 > 900) EXP2 = 900;
        
        if(HP2 < 0) HP2 = 0;
    
        if(EXP1 > 900) EXP1 = 900;
        
        if(M2 > 2000) M2 = 2000; 
        
        return (EXP2 + HP2 + M2 + EXP1);

    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3)
{
	if (E3 < 0 || E3 > 999)
	{
		return -999;
	}
	
	else
	{
		if (EXP1 > 900) EXP1 = 900;
		if (EXP1 < 0) EXP1 = 0;
		if (M1 > 2000) M1 = 2000;
		if (M1 < 0) M1 = 0;
		if (HP1 < 0) HP1 = 0;
		if (HP1 > 999) HP1 = 999;
		
	//road 1: 9 first odds natural numbers
	
	int P1[9] = {1,3,5,7,9,11,13,15,17};
	int count1 = 0;
	for (int i = 0; i < 9; i++)
	{
		P1[i] = fmod((P1[i]+E3),26) + 65;
		if (P1[i] == 80)
		{
			count1 ++;
			HP1 = HP1 - P1[i]*(i+1)*2;
			EXP1 = EXP1 + fmod((1000-P1[i]*(i+1)),101);
			M1 = ceil(M1 - E3*1.0/9*(i+1));
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (M1 < 0) M1 = 0;	
			if (HP1 < 0) HP1 = 0;
			break;
		}
	}
	if (count1 == 0) 
	{
		M1 = ceil(M1 - E3*1.0/9 * pow(9,2));
		if (M1 < 0) M1 = 0;
	}
	
cout << HP1 << " " << EXP1 << " " << M1 << endl;          
	
	//road 2 : 7 first prime numbers
	
	int count2 = 0;
	int P2[7] = {2,3,5,7,11,13,17};
	int S = 0;
	for (int i = 0; i < 7; i++)
	{	
		P2[i] = fmod((P2[i]+E3),26);
		S = S + P2[i];
	}
	int m = ceil(S*1.0/7);
	
	for (int i = 0; i < 7; i++)
	{
		P2[i] = fmod((P2[i] + S + m),26) + 65;
	}
	
	for (int i = 0; i < 7; i++)
	{
		if (P2[i] == 80)
		{
			count2 ++;
			HP1 = HP1 - P2[i]*(i+1)*2;
			EXP1 = EXP1 + fmod((1000 - P2[i]*(i+1)),101);
			M1 = ceil(M1 - E3*1.0/9 * (i+1));
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (M1 < 0) M1 = 0;
			if (HP1 < 0) HP1 = 0;
			break;
		}
	}
	
	if (count2 == 0) 
	{
		M1 = ceil(M1 - E3* 1.0/9 * 49);
		if (M1 < 0) M1 = 0;
	}

cout << HP1 << " " << EXP1 << " " << M1 << endl;          

	//road 3: 20 first even perfect square numbers
	
	int P3[20];
	int t = 2; //initialize for the 1st square number
	int count3 = 0;
	for (int x = 0; x < 20; x++)
	{
		P3[x] = t*t;
		t += 2;
	}
	
	int ma = fmod((P3[0] + pow(E3,2)),113);
	
	for (int x = 1; x < 20; x++)
	{
		P3[x] = fmod(P3[x] + pow(E3,2),113);
		if (P3[x] > ma) ma = P3[x];
	}
	
	P3[0] = fmod((P3[0] + pow(E3,2)),113);
	
	for (int x = 0; x < 20; x++)
	{
		P3[19-x] = fmod(ceil((P3[19-x] + E3)*1.0/ma),26)+65;
		if (P3[19-x] == 80)
		{
			count3 ++;
			HP1 = HP1 - P3[19-x]*(x+1)*3;
			EXP1 = EXP1 + (3500-P3[19-x]*(x+1))%300;
			M1 = ceil(M1 - E3*1.0/9 * (x+1));
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (M1 < 0) M1 = 0;
			if (HP1 < 0) HP1 = 0;
			break;
		}
	}
	if (count3 == 0) 
	{
		M1 = ceil(M1 - E3*1.0/9*400);
		if (M1 < 0) M1 = 0;
	}

cout << HP1 << " " << EXP1 << " " << M1 << endl;          

	//road 4: 12 months
	
	int temp = 0;
	int count4 = 0;
	int P4[12] = {31 , 28 , 31, 30 ,31 ,30 ,31 , 31 ,30 , 31, 30, 31};
	int min = fmod(P4[0] + pow(ceil(E3*1.0/29),3),9);
	
	for (int i = 1; i < 12; i++)
	{
		P4[i] = fmod(P4[i] + pow(ceil(E3*1.0/29),3),9);
		if (P4[i] < min) 
		{
			min = P4[i];
			temp = i+1;
		}
	}
	
	P4[0] = fmod(P4[0] + pow(ceil(E3*1.0/29),3),9);
	
	for (int i = 0; i < 12; i++)
	{
		P4[11-i] = fmod(((P4[11-i]+E3)*ceil(min*1.0/temp)),26)+65;
		if (P4[11-i] == 80)
		{
			count4 ++;
			HP1 = HP1 - P4[11-i]*(i+1)*4;
			EXP1 = EXP1 + fmod(4500-P4[11-i]*(i+1),400);
			M1 = ceil(M1 - E3* 1.0/9* (i+1));
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (M1 < 0) M1 = 0;
			if (HP1 < 0) HP1 = 0;
			break;
		}
	}
	
	if (count4 == 0) 
	{
		M1 = ceil(M1 - E3*1.0/9 *144);
		if (M1 < 0) M1 = 0;
	}
cout << HP1 << " " << EXP1 << " " << M1 << endl;          

	
	//if no found
	
	int count = count1 + count2 + count3 + count4;
	if (count == 0) 
		{
			HP1 = HP1 - fmod((E3*59),900);
			EXP1 = EXP1 - fmod((E3*79),300); 
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (HP1 > 999) HP1 = 999;
			if (HP1 < 0) HP1 = 0;
			return -1;
		}
	
	else
		{
			if (EXP1 > 900) EXP1 = 900;
			if (EXP1 < 0) EXP1 = 0;
			if (HP1 > 999) HP1 = 999;
			if (HP1 < 0) HP1 = 0;
			return HP1 + EXP1 + M1;
		}
	}
}
int readFile(string filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3) {
//This function is used to read the input file,
//DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> HP1 >> HP2;
        myfile >> EXP1 >> EXP2;
        myfile >> M1 >> M2;
        myfile >> E1 >> E2 >> E3;
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    string filename = "input.txt";
    int HP1 = -1, HP2 = -1;
    int EXP1 = -1, EXP2 = -1;
    int M1 = -1, M2 = -1;
    int E1 = -1, E2 = -1, E3 = -1;
    bool isRead = readFile(filename, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3);
    if (isRead){
        //Task 1
        cout << firstMeet(EXP1, EXP2, E1) << endl;
        cout << EXP1 << " "<< EXP2 << endl;
        //Task 2
        cout << investigateScene(EXP1, EXP2, HP2, M2, E2)<< endl;
        cout << EXP1 << " "<< EXP2 << " " << HP2 << " " << M2 << endl;
        //Task 3
        cout << traceLuggage(HP1, EXP1, M1, E3)<< endl;
        cout << HP1 << " "<< EXP1 << " " << M1 << endl;
    }
    else{
        cout << "Cannot read input file";
    }
    return 0;
}