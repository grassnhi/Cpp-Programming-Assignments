#include<iostream>
using namespace std;

int fac(int n);

int main() {
	cout << fac(4) << endl;
    
	return 0;
}

int fac(int numb){
	int product=1;

	while(numb>1){
		product *= numb;
		numb--;
	}

	return product;
}