#include <cmath>
#include <iostream>

using namespace std;

long int digitExtraction(long int seed,int* extractDigits,int size)
{
    long int num = seed; 
	int digitArr[100] = {}; 
	int n = 0;

	while (num != 0) { 
        digitArr[n] = num % 10; 
        num /= 10; 
        n++; 
	} 

    long int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum * 10 + digitArr[n - extractDigits[i] - 1];
    }
    return sum;
}

int main(){
    int a[]={1,2,5};
cout << digitExtraction(122443,a,3);

}