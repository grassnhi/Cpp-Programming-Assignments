#include <iostream>
using namespace std;

int main() {
    int count = 0, grade, total = 0;

    while( count < 30){
    cout << "Enter a grade: ";
    cin >> grade;

    if (grade < 0 || grade > 100)
       continue;
       
    total = total + grade;
    count++;
    cout << total;
}
// invalid grades are simply ignored and only valid grades are added to the total
    return 0;
}