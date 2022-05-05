#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream note2(ntb2, ifstream::in);
    
    string N2;


    if(note2.is_open()){
        note2 >> N2;
        for(int i = 0; i < N2.length(); i++){
            if(N2[i] < '0' || N2[i] > '9'){
                note2.close();
                return "1111111111";
            }
        }
        int n2 = stoi(N2);
        string finding;
        if(n2 >= 5 && n2 <= 500){
            for(int i = 0; i < n2; i++){
                getline(note2, finding);

            }
        }
        else{
            note2.close();
            return "1111111111";
        }
    }
    else{
        note2.close();
        return "000000000";
    }
}
int main(){
    cout << notebook2("tc1-file-ntb2.txt");

}