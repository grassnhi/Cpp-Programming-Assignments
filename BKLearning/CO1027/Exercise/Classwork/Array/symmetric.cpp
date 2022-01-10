#include<iostream>
#include<iomanip>
using namespace std; 

const int N = 3;
int main( ){
    int i, j;
    int a[N][N];
    bool symmetr = true;

    for ( i=0; i< N; ++i)
       for (j=0; j<N; ++j)
            cin >> a[i][j];

    for(i= 0; i<N; i++){
	    for (j = i+1; j < N; j++){
	   	    if(a[i][j] != a[j][i]){
	      	 	symmetr = false;
	       		break;
	 		}
  	    }

	    if(!symmetr)
	    	break;
    }

    if(symmetr)
        cout << "\nThe matrix is symmetric" << endl;
    else
         cout << "\nThe matrix is not symmetric" << endl;
         
     return 0;	      
}





