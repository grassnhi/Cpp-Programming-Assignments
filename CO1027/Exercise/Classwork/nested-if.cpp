#include<iostream>
using namespace std;

int main() {
    float score;
    char grade;
    
    cout << "Enter a score [0 - 10]: ";
    cin >> score;
    
    if (score >= 8)
		grade = 'A';
    else if (score >= 6.5)
		    grade = 'B';
        else if (score >= 5)
		        grade = 'C';
            else if (score >= 4)
		            grade = 'D';
                else
		            grade = 'F';

    cout << "Your grade is " << grade << endl;
    
    return 0;
}