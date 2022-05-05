
#include<iostream>
#include<fstream>
#define N 3
//you are not allowed to include more library
using namespace std;
void uppercase(const char* output) {
    
}
int main(){
	const char s[N][100]={"output1.txt","output2.txt","output3.txt"};
	string Result[N]={"HELLO10","KYTHUATLAPTRINH212","@#$%^*()"}; 
	for(int i=0;i<N;i++){
		uppercase(s[i]);
		ifstream fin;
		fin.open(s[i]);
		
		string result;
		fin >> result;
		cout<<"test case "<<i<<endl;
		cout << "Your output:"<<result;
		cout<<endl;
		cout << "Expected   :"<<Result[i]<<endl<<endl;
		fin.close();
	}
	return 0;
}
