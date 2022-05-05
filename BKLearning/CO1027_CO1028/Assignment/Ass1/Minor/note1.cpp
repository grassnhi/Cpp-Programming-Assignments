#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream note1(ntb1, ifstream::in);
    
    string N1 = "";
    string myText;

    if(note1.is_open()){
        note1 >> N1;
        string number;
        for(int i = 12; i < 15; i++){
            if(N1[i] >= '0' && N1[i] <= '9' && N1[14] != 0){
                number[i-12] = N1[i];
            }
            else{
                note1.close();
                return "000000000";
            }
                
        }
        int num = stoi(number);
                
        
        getline(note1, myText);

        int count[10];
        for(int i = 0; i < 10; i++){
            count[i] = 0;
        }

        for(int i = 0; i < myText.length(); i++){
            if(myText[i] >= '0' && myText[i] <= '9' && myText.length() >= num){
                if(myText[i] == i){
                    count[i]++;
                    while(count[i] > 10){ 
                        count[i] -= 10; 
                    }    
                }                 
            }
            else{
                note1.close();
                return "000000000";
            }
                
        }
          
        //convert

        note1.close();
    }
    else{
        note1.close();
        return "000000000";
    }
}
int main(){
    cout << notebook1("tc1-file-ntb1.txt");

}