#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream note3(ntb3, ifstream::in);
    
    int N3[9][9];

    if(note3.is_open()){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                // 
                note3 >> N3[i][j];
                if(N3[i][j] < 0){
                    N3[i][j] = 0 - N3[i][j];
                }

            }
        }
    }
    else{
        note3.close();
        return "000000000";
    }
}
int main(){
    cout << notebook3("tc1-file-ntb3.txt");

}