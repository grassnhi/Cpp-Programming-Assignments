// e^x = 1 + x/1! + x^2/2! + ... + x^n/n!
// |x^n/n!| <= c

//  NEED TO BE FIXED

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define e M_E
int main()
{
	double c, x;

	cout << "Enter c and x: ";
	cin >> c >> x;

	long n = 1;

	double tmp = 1, ex = pow(x,n)/n;
    

	while (tmp >= c) {
		tmp += ex;
        n++;
        ex = pow(x,n)/n;
	}

	cout << "e^x = " << tmp << endl;

	cout << fixed << setprecision(30) << pow(e, x) << endl;

	return 0;
}

