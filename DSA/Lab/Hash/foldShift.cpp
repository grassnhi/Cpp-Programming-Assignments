/*
Implement function 

int foldShift(long long key, int addressSize);
int rotation(long long key, int addressSize);
to hashing key using Fold shift or Rotation algorithm. 
Review Fold shift:

The folding method for constructing hash functions begins by dividing the item into equal-size pieces (the last piece may not be of equal size). These pieces are then added together to give the resulting hash value.

For example:

Test	Result
cout << rotation(600101, 2);
26

*/
#include <cmath>
#include <iostream>

using namespace std;

int foldShift(long long key, int addressSize) { 
	long long num = key; 
	int digitArr[100] = {}; 
	int n = 0;
	while (num != 0) { 
        digitArr[n] = num % 10; 
        num /= 10; 
        n++; 
	} 
	long long sum = 0; 
	while(n > 0){ 
		long long s = 0; 
		for (int i = 0; i < addressSize; i++) { 
			if (n - i - 1 >= 0) { 
				s = s * 10 + digitArr[n - i - 1]; 
			} 
		} 
		n -= addressSize; 
		sum += s; 
	} 
	long long mod = pow(10, addressSize); 
	return sum % mod; 
}


int rotation(long long key, int addressSize){ 
	long long num = key;
    int digitArr[20] = {};
    int n = 0;
    while (num != 0)
    {
        digitArr[n] = num % 10;
        num /= 10;
        n++;
    }
    int temp = digitArr[0];
    for(int i = 0; i < n - 1; i++){
        digitArr[i] = digitArr[i+1];
    }
    digitArr[n-1] = temp;

    long long sum = 0; 
	while(n > 0){ 
		long long s = 0;
        for(int i = 0; i < addressSize; i++){
            if(n - i - 1 >= 0){
                s = s * 10 + digitArr[n-i-1];
            }
        }
        n -= addressSize;
        sum += s;
	} 

	long long mod = pow(10, addressSize); 
	return sum % mod; 
}

int main(){
    cout << foldShift(1234567, 3);
    cout << rotation(600101, 2);

}