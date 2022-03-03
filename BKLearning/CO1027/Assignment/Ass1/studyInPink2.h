/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    ifstream note1(ntb1, ifstream::in);
    string ans = "";
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(note1.is_open()){
        string N1;
        note1 >> N1;
        string number;
        string myText;
        
        for(int i = 11; i < 14; i++){ 
            if(!isdigit(N1[i])){
                note1.close();
                return "000000000";
            }else
            number[i-11] = N1[i];
        }
        int num = stoi(number);
cout << num << endl;
        getline(note1, myText);   // 1 2 3
cout << myText[1] << myText[2] << myText[27];
// for(int i = 0; i < num*2; i+= 2){
//     cout << myText[i] << " ";
// }    
    }
return "0000000000";

//         for(int i = 0; i < num*2; i += 2){
//             for(int j = 0; j < 10; j++){
//                 if(myText[i] = j){
//                     count[j]++;
// //cout << "\n" << count[j];
//                     if(count[j] >= 10){
//                         count[j] = 0;
//                     }
//                     break;
//                 }
//             }
//         }

//         for (int i = 0; i < 10; i++){
//             ans += to_string(count[i]);
//         }  
    
//     }
    
//     note1.close();
//     return ans;
        

}

string notebook2(string ntb2) {
    // Complete this function to gain point
    return "000000000";
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    return "000000000";
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    return "000000000";
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    return "";
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
