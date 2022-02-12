
#include<iostream>
#include<string.h>
//you are not allowed to use C++ string type or include more library
using namespace std;

void del(char str[], int pos){
	int n = strlen(str);
    for(int i = pos; i < n - 1; i++){
        str[i] = str[i+1];
    }
    str[--n] = '\0';
}

void remove(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n - 1; i++){
        if(str[i] == ' ' && str[i+1] == ' '){
            del(str, i);
            i--;
        }
    }

    if(str[0] == ' ')
        del(str, 0);

    if(str[n-1] == ' ')
        del(str, n);
    
    str[n] = '\0';
}

void process(const char *str, char *outstr) {
	char temp[100];
	int count = 0, n;
	strcpy(temp, str);
	n = strlen(temp);
	for(int i = 0; i < n; i++){
		if(('a' <= temp[i] && temp[i] <= 'z')||('A'<= temp[i] && temp[i] <= 'Z')|| temp[i] == ' '){
			outstr[count++] = temp[i];
		}
		if(outstr[count] == ' '){
			count--;
		}
	}
	outstr[count] = '\0';

	outstr[0] = outstr[0] >= 'a'? outstr[0]-32: outstr[0];

	for (int i = 1; i < count; i++)
	{
		if(outstr[i] >= 'A' && outstr[i] <= 'Z' && outstr[i-1]!= ' '){
			outstr[i] += 32;
		}
		else if(outstr[i] >= 'a' && outstr[i] <= 'z' && outstr[i-1]== ' '){
			outstr[i] -= 32;
		}
	}
	
	 remove(outstr);
}


int main(){
	char str[] = "doAn VAN *(()hau @!#$" ;
	char *outstr = new char[strlen(str) + 1];
	process(str, outstr);
	cout << outstr;
}
