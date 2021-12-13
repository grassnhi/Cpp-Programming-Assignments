/*
A person invests $1000.00 in a saving account with 5 percent interest. 
Assuming that all interest is left on deposit in the account, calculate and print 
the amount of money in the account at the end of each year for 10 years. 
Use the following formula for determining these amounts: 
 	a = p(1 + r)n
where   p is the original amount invested, 
        r is the annual interest rate and n is the number of years  
        a is the amount on deposit at the end of the nth year.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double amount,
    principal = 1000.0, rate = 0.05;

    cout    << "Year" 
            << setw(21) << "Amount on deposit" << endl;
// 21 vị trí trống để điền cụm "Amount on deposit" căn lề bên phải
    cout    << setiosflags(ios::fixed | ios::showpoint) 
            << setprecision(2); 
// Viết dưới dạng số thập phân, lấy 2 chữ số sau dấu .
    for (int year = 1; year <= 10; year++) {
        amount = principal*pow(1.0 + rate, year);
        cout << setw(4) << year << setw(21) << amount << endl;
  }
  
  return 0;
}