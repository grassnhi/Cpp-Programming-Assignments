#include<iostream>
#include<cstring>

using namespace std;

void summoning(char* input, char** talis, int nTalis, int* demon, int nDemon){
    char* temp;
	for (int i = 0; i < nTalis; i++) {
		temp = strstr(talis[i], input);
		if (temp != NULL) {
			demon[nDemon] = i;
			nDemon++;
		}
	}

	for (int i = 0; i < nDemon; i++) {
		cout << demon[i] << " ";
	}
}

int main(){
    char* talis[5] = {
		(char*)"yatagarasu",
		(char*)"nekomata",
		(char*)"kappa",
		(char*)"yamajijii",
		(char*)"yurei"
	};

	char* input;
    cin >> input;
	int idx[500]={0, 1, 2, 3, 4};
	int numDemons = 0;

	summoning(input, talis, 5, idx, numDemons);
    
    return 0;
}