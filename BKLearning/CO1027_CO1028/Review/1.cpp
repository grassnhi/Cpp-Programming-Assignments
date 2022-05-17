#include <iostream>
#include <cstring>
using namespace std;

void summoning(char* input, char** talis, int nTalis, int* demon, int nDemon) {
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

int main() {
	char** temp = new char*[5];
    for(int i = 0;i<5;i++) temp[i] = new char[500];
	temp[0] = (char*)"yatagarasu";
	temp[1] = (char*)"nekomata";
	temp[2] = (char*)"kappa";
	temp[3] = (char*)"yamajijii";
	temp[4] = (char*)"yurei";
	char* input = new char[500];
	input = (char*)"ya";
	int idx[500]={1,2,3,4};
	int numDemons = 0;
	summoning(input, temp, 5, idx, numDemons);
}