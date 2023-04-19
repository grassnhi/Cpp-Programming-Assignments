/*
Implement three following hashing function:

long int midSquare(long int seed);
long int moduloDivision(long int seed, long int mod);
long int digitExtraction(long int seed, int* extractDigits, int size);

Note that:

In midSquare function: we eliminate 2 last digits and get the 4 next digits.

In digitExtraction: extractDigits is a sorted array from smallest to largest index of digit in seed (index starts from 0). The array has size size.



For example:

Test	Result
int a[]={1,2,5};
cout << digitExtraction(122443,a,3);
223
cout <<midSquare(9452);
3403

*/
long int midSquare(long int seed)
{
    long int square=seed*seed;
    return (square/100)%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
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