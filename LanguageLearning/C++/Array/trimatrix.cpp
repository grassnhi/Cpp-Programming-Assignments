#include<iostream>
#include<math.h>

using namespace std;
// Number of positive element in triangular matrix

int check(int a[][10], int n){
    int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(a[i][j] > 0){
                count++;
            }
		}
	}
	return count;
}

int main(){
    int a[10][10];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

    cout << check(a, n);

    return 0;
}