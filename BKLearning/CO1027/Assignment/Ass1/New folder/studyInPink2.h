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
 
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++)
            arr[i][j] = -9;
    }
    arr[0][0] = 0;

    int begin = 0, row = 0, col = 0;
    for(int i = 0; i < moves.length(); i++){
        char step = moves[i];
        switch(step){
            case 'D':
                if(row + 1 < 100) {
                    arr[++row][col] = begin + 9;
                    begin = arr[row][col];
                }
                break;
            case 'U':
                if(row - 1 > 0) {
                    arr[--row][col] = begin + 9;
                    begin = arr[row][col];
                }
                break;
            case 'R':
                if(col + 1 < 100) {
                    arr[row][++col] = begin + 9;
                    begin = arr[row][col];
                }
                break;
            case 'L':
                if(col - 1 > 0) {
                    arr[row][--col] = begin + 9;
                    begin = arr[row][col];
                } 
                break;
        }
    }
    
    int start = points.find("("),  end = points.find(",");
    int first = 1;
    int  current[2] = {0, 0}, previousious[2]={-9, -9};
    int preTime = 0, curTime = 0;
    bool flag = 0;
    previous[0] = 0, previous[1] = 0, current[0] = -9, current[1] = -9;
    
    while(start != string::npos){
        points = points.substr(start);
        int *p = &current[0];
    
        string found =points.substr(start + 1, end - start);
        *p++ = stoi(found);

        points = points.substr(end + 1);
        found = points.substr(0, points.find(")"));
        *p = stoi(found);

        curTime = 14*(abs(current[0] - previous[0]) + abs(current[1] - previous[1])) + preTime;
        
    }
    return flag;
   
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream pass(tag, ifstream::in);
    string email, address, n3 = "";
    while(note1.is_open()){
        getline(pass, email);
        getline(pass, address);

        if(isdigit(address[1])){
            for (int i = 0; i < 2; i++){
                n3 += to_string(count[i]);
            } 
        }else
            n3 = stoi(address[0]);

        string password = email + ";" + message;        
        
    }
    return "";
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
