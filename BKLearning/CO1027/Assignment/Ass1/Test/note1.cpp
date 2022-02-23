#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int transform(string str){
    int n = str.length();
    int num = 0;
    for(int i = n - 1; i >= 0; i--){
        num1 += (int)(str[i] - '0') * pow(10, n-i-1);
    }
    return num;
}

int checkElement(string str){
    int check = 0;

    for(int i = 0; i < str.length(); i++){
        for(int j = 48; j <= 57; j++){
            if(s[0] != 0 && s[i] == j){
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

    if(note1.is_open){
        note1 >> N1;

        if(ntb1.substr(0, 11) ="Freq/First/" && checkElement(substr(12,3)) == 3){
            if(transform(substr(12, 3)) > 0 && transform(substr(12, 3)) < 1000){
                int num;
                while(!note1.eof()){
                    string myText;

                    getline(note1, myText);

                    my_file.close();
                }
    
                for(unsigned int i = 0; i < myText.length(); i++){
                    if(myText[i] >= '0' && myText[i] <= '9' && myText.length() >= num){
                        
                    }
                    else
                        return "000000000";

                
            }
            else
                return "000000000";
        }
        else
            return "000000000";
    }
    else
        return "000000000";

    note1.close();
        //return "000000000";
}

int main(){
    cout << notebook1("tc1-file-ntb1.txt");

}