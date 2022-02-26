#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;



int checkElement(string str){
    int check = 0;

    for(int i = 0; i < str.length(); i++){
        for(int j = 48; j <= 57; j++){
            if(str[0] != 0 && str[i] == j){
                check++;
            }
        }
    }

    return check;  
}

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream note1(ntb1, ifstream::in);
    
    string N1 = "";
    string myText;

    if(note1.is_open()){
        note1 >> N1;
    
        if(ntb1.substr(0, 11) ="Freq/First/" && checkElement(substr(12,3)) == 3){
            if(stoi(substr(12, 3)) > 0 && stoi(substr(12, 3)) < 1000){
                int num;
                while(!note1.eof()){
                    getline(note1, myText);

                    note1.close();
                }
                int count[10];
                for(int i = 0; i < 10; i++){
                    count[i] = 0;
                }
                for(unsigned int i = 0; i < myText.length(); i++){
                    if(myText[i] >= '0' && myText[i] <= '9' && myText.length() >= num){
                        if(myText[i] == i){
                            count[i]++;
                            if(count[i] > 10){ count[i] -= 10; }    
                        }                 
                    }
                    else{
                        note1.close();
                        return "000000000";
                    }
                cout << count[10] << endl;
                }
            }
            else{
                note1.close();
                return "000000000";
            }
        }
        else{
            note1.close();
            return "000000000";
        }

        note1.close();
    }
    else
        return "000000000";
        //return "000000000";
}

int main(){
    cout << notebook1("tc1-file-ntb1.txt");

}