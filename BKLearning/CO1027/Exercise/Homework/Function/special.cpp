/*
A natural number n is special if and only if n is a prime number and the sum 
of all the digits of n is also a prime number. Write a function that determines 
if a natural number is a special or not.

Input:
    int n: a natural number n. 0 <= n <= 1000

Output:
    bool: return true if n is special, return false otherwise
*/

#include <iostream>

using namespace std;

int digsum(int n){
    int s = 0;
    for(;n!=0;){
        int r = n % 10;
        s += r;
        n /= 10;
    }
    return s;
}

bool isSpecialNumber(int n) {
    if(n<2 && digsum(n) < 2 ){ 
        return false; 
        
    }
    else{
        for (int i = 2; i < n; i++){
    		if (n % i == 0) {
    			return false;
    		}
    	}
    	for (int i = 2; i < digsum(n); i++){
    	    if(digsum(n) % i == 0){
    	        return false;
    	    }
    	}
		return true;
    }
}
 
int main(){
    int n;
cin >> n;
cout << isSpecialNumber(n);

}