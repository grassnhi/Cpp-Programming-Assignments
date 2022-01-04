/*
The following program reads a set of name, roll number, sex, height and weight of the students 
from the keyboard using a structure within an array.

a. Displaying data of n students in the following format:
5 columns, each column separate from the next to the right by exactly 20 characters, 
starting with the value and space characters to fill the rest, no space character 
and 1 newline character after last value of line
The first line will be the name of each column, respectively: Name, Rollno, Sex, Height, Weight
Output value, if float, is rounded up to 2 digits after decimal point

b. Computing and displaying the average of heights and the average of weights of the students, 
round up to 5 digits after decimal point, separated by 1 space character, no character after last value.
*/

#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

const int MAX = 100;

struct student{
    char name[20];
    long int rollno;
    char sex;
    float height;
    float weight;
};

int main() {
    student cls[MAX];
    
    int i,n;

    cout << "How many names ? \n";
    cin >> n;

    for (i = 0; i <= n-1; ++i){
        cout << "record = "<< i+1 << endl;
        cout << "name : "; cin>> cls[i].name;
        cout << "rollno : "; cin>> cls[i].rollno;
        cout << "sex : "; cin>> cls[i].sex;
        cout << "height : "; cin>> cls[i].height;
        cout << "weight : "; cin>> cls[i].weight;
        cout << endl;
    }
    
    float h=0, w=0;

    cout << "Name                Rollno              Sex                 Height              Weight"<< endl;
    for (i = 0; i <= n-1; ++i){
        cout << fixed << setprecision(2) << setw(20) << left << cls[i].name << setw(20) << cls[i].rollno <<setw(20) << cls[i].sex << setw(20) << cls[i].height << setw(20) << cls[i].weight << endl;
        h += cls[i].height;
        w += cls[i].weight;
    }
    
    cout << fixed << setprecision(5) << h/n << " " << w/n;
    
}