// This program checks if a matrix is symmetric or not.

#include<iostream>
using namespace std;
const int N = 3;
void main( )
{
    int i, j;
    int a[N][N];
    bool symmetr = true;

    for ( i=0; i< N; ++i)
       for (j=0; j<N; ++j)
            cin >> a[i][j];

    for(i= 0; i<N; i++){
	    for (j = 0; j < N; j++)
	        if(a[i][j] != a[j][i]){
	            symmetr = false;
	            break;
	        }
            
	    if(!symmetr) // means if symmetr = false
	    break;
    }
    
    if(symmetr) // means symmetr = true
        cout << "\nThe matrix is symmetric" << endl;
    else
        cout << "\nThe matrix is not symmetric" << endl;

    return 0;	      
}