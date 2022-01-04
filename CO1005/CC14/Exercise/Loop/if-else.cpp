/*
We construct a C++ program for determining income taxes. 
Assume that these taxes are assessed at 2% of taxable incomes less than or equal to $20,000. 
For taxable income greater than $20,000, taxes are 2.5% of the income that exceeds (vượt quá) 
$20,000 plus a fixed amount of $400.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const float LOWRATE = 0.02;     // lower tax rate
const float HIGHRATE = 0.025;   // higher tax rate
const float CUTOFF = 20000.0;   // cut off for low rate
const float FIXEDAMT = 400; 

int main()
{
  float taxable, taxes;
  cout << "Please type in the taxable income: ";
  cin  >> taxable;

  if (taxable <= CUTOFF)
    taxes = LOWRATE * taxable;
  else
    taxes = HIGHRATE * (taxable - CUTOFF) + FIXEDAMT;
   // set output format
  cout << setiosflags(ios::fixed) // use conventional fixed-point decimal notation.
       << setiosflags(ios::showpoint) //show the decimal point for floating point number.
       << setprecision(2); // two postion after decimal notation: ".".
  cout << "Taxes are $ " << taxes << endl;
 return 0;
} 