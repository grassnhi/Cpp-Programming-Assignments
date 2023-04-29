#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
    --------------------------------------------------------------------------------------------------------
    AUTHOR: QUY LE MINH
    UPDATE DATE: 04/19/2023
    --------------------------------------------------------------------------------------------------------
*/

void assert(string expected, string got, int line, int testcase){
    if (expected!=got){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\u0058 Failed case " << testcase << " at line " << line << ". Expected \"" << expected << "\" got \"" << got  << "\"" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        abort();
    }
}

int main() {
    string s1, s2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 100; i++){
        //  EDIT HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
        string expect = "E:\\Coding\\C-plus-plus\\BKLearning\\CO2003_CO2004\\DSATestcase_Assignment2\\output\\expected" + to_string(i+1) + ".txt";       //<-------- Throw your output folder path here and add additional \ in your path. Then add \\expected. In general, your path will look similar mine.
        string got = "E:\\Coding\\C-plus-plus\\BKLearning\\CO2003_CO2004\\DSATestcase_Assignment2\\got\\got" + to_string(i+1) + ".txt";

        ifstream output(got);
        ifstream expected(expect);

        int line = 1;

        while (getline(output, got) && getline(expected, expect)){
            assert(expect, got, line, i+1);
            line++;
        }

        if (getline(output, got) || getline(expected, expect)){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "\u0058 Wrong at case " + to_string(i+1) + ". Maybe you missing something? Check got" << (i+1) << ".txt file" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            abort();
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << char(251) << " Passed case " << (i+1) << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << char(251) << " Passed all." << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
