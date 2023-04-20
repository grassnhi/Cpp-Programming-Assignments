#include <iostream>
#include <fstream>
#include <string>
#include "studyInPink.h"

/*
    Chao may ong!
    Truoc khi chay file nay, may ong hay:
                1. Doi ten file testcase input, output thanh: INPUT.txt , OUTPUT.txt
                2. Dat file studyInPink.h , INPUT.txt , OUTPUT.txt cung mot folder
    
    Hi vong huu ich!
    Cam on may ong!
*/

int main(){
    std::fstream inputFile;
    std::fstream outputFile;
    
    std::string temp;

    int task1_EXP1 = -2, task1_EXP2 = -2, task1_total = -2;
    int task2_EXP1 = -2, task2_EXP2 = -2, task2_total = -2, task2_HP2 = -2, task2_M2 = -2;
    int task3_HP1 = -2, task3_EXP1 = -2, task3_M1 = -2, task3_total = -2;

    const int MAX_COUNT = 100000; // <<---------------- Neu luong test case > 100, doi so nay nhe!
    int count=1; // <<------------ count bat dau tu 1.

    int task1_correct = 0, task2_correct = 0, task3_correct = 0;

    inputFile.open("INPUT.txt",std::ios::in);
    outputFile.open("OUTPUT.txt",std::ios::in);
    std::string trich_xuat="", trich_xuat1="", trich_xuat2="";
    if (inputFile.is_open() && outputFile.is_open()){
        while (count<=MAX_COUNT){
            int HP1 = -1, HP2 =-1;
            int EXP1 = -1, EXP2 = -1;
            int M1 = -1, M2 = -1;
            int E1 = -1, E2 = -1, E3 = -1;
            int task1_in_total = -1, task2_in_total = -1, task3_in_total = -1;

            // Get the input data
            inputFile >> temp >> temp >>temp;
            inputFile >> HP1 >> HP2;
            inputFile >> EXP1 >> EXP2;
            inputFile >> M1 >> M2;
            inputFile >> E1 >> E2 >> E3;

            std::cout << "Testcase #"<<count<<std::endl;
            // Get the output data
            // task 1
            std::cout << "\t Task 1: ";
            outputFile >> temp >> temp >> temp;
            outputFile >> temp >> temp;
            outputFile >>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>temp>>task1_total;
            outputFile >> temp >> temp >> trich_xuat >> temp >> temp >> task1_EXP2;
            task1_EXP1 = std::stoi(trich_xuat); 
                // So sanh
                task1_in_total = firstMeet(EXP1, EXP2, E1);
                if (task1_in_total==task1_total && EXP1==task1_EXP1 && EXP2==task1_EXP2){
                    task1_correct++;
                    std::cout << "TRUE"<<std::endl;
                } else {
                    std::cout << "FALSE <###############>"<<std::endl;
                }
            // task 2
            std::cout << "\t Task 2: ";
            outputFile >> temp >> temp;
            outputFile >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> task2_total;
            outputFile >> temp >> temp >> trich_xuat >> temp >> temp >> trich_xuat1 >> temp >> temp >> trich_xuat2 >> temp >> temp >> task2_M2;
            task2_EXP1 = std::stoi(trich_xuat); task2_EXP2 = std::stoi(trich_xuat1); task2_HP2 = std::stoi(trich_xuat2);
                // So sanh
                task2_in_total = investigateScene(EXP1, EXP2, HP2, M2, E2);
                if (task2_in_total==task2_total && EXP1==task2_EXP1 && EXP2==task2_EXP2 && HP2==task2_HP2 && M2==task2_M2){
                    task2_correct++;
                    std::cout << "TRUE"<<std::endl;
                } else {
                    std::cout << "FALSE <###############>"<<std::endl;
                }
            // task 3
            std::cout << "\t Task 3: ";
            outputFile >> temp >> temp;
            outputFile >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> task3_total;
            outputFile >> temp >> temp >> trich_xuat >> temp >> temp >> trich_xuat1 >> temp >> temp >> task3_M1;
            task3_HP1 = std::stoi(trich_xuat); task3_EXP1 = std::stoi(trich_xuat1);
                // Compare
                task3_in_total = traceLuggage(HP1, EXP1, M1, E3);
                if (task3_in_total==task3_total && HP1==task3_HP1 && EXP1==task3_EXP1 && M1==task3_M1){
                    task3_correct++;
                    std::cout << "TRUE"<<std::endl;
                } else {
                    std::cout << "FALSE <###############>"<<std::endl;
                }

            std::cout <<std::endl;
            count++;
        }
        inputFile.close();
    } else {
        std::cout << "Khong the mo duoc file, vi khong co file input output!"<<std::endl;
    }

    std::cout << "--------------------------------------"<<std::endl;
    std::cout << " Ket qua sau khi test"<<std::endl;
    std::cout << " \t Task 1: "<<((float)(task1_correct)/MAX_COUNT)*100<<"%"<<std::endl;
    std::cout << " \t Task 2: "<<((float)(task2_correct)/MAX_COUNT)*100<<"%"<<std::endl;
    std::cout << " \t Task 3: "<<((float)(task3_correct)/MAX_COUNT)*100<<"%"<<std::endl;
    return 0;
}