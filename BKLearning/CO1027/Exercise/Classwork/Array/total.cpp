#include <iostream>

using namespace std;

int main()
{
    const int arraySize = 12;

    int a[arraySize] = { 1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45 };

    int total = 0;

    for ( int i = 0; i < arraySize; i++ )
        total += a[i];
    
    cout << "Total of array element values is " << total << endl;
    
    return 0;
}