#include<iostream>
#include<string.h>
using namespace std;
void printFirstRepeatedWord(char str[]) {
	char* arr[100];
    char *token;
    token = strtok(str, " ");
	int i = 0;
    while(token != NULL){
        arr[i++] = token;
        token = strtok(NULL, " ");

    }
    int size = i;
	for(int i = 0 ; i < size; i++){
		for(int j = i + 1 ; j < size; j++){
			if(strcmp(arr[i], arr[j]) == 0){
				cout << arr[i];
                return;
			}
	    }
	}
    cout << "No Repetition";
}
int main()
{
	char str[] = "car taxi bike bike car taxi" ;
	printFirstRepeatedWord(str);

	return 0;

}