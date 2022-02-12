
#include<iostream>
//you are not allowed to include more library
using namespace std;

int main(){
	string str[];
	int n = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == str[i+1]){
			n++
		}
	}
	cout << n;
	return 1;
}

