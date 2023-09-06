
#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n <= 1)
        return false;
  
    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return false;
    }
  
    return true;
}

int specialCells(int arr[][1000], int row, int col) {
    int row_sum = 0, col_sum = 0, counter = 0;
    
    for (int i = 0; i < row; i++){
	    for (int j = 0; j < col; j++){
		    for(int k = 0; k < col; k++){ 
		        row_sum += arr[i][k];
		    }
		    
		    for(int k = 0; k < row; k++){
		        col_sum += arr[k][j];
		    }
		    
		    if(isPrime(row_sum) && isPrime(col_sum)) 
		        counter++;
		        
    		row_sum = 0;
    		col_sum = 0;
	    }
	}
	return counter;
}

int main(){
    int arr[][1000] = {{37,53,74},{12,37,60},{98,13,15}};

    cout << specialCells(arr,3,3);
    
    return 0;
}