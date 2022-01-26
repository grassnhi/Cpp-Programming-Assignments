#include <iostream>
#include <cstring>

using namespace std;

void del(char str[], int pos){
	int n = strlen(str);

    for(int i = pos; i < n; i++){
        str[i] = str[i+1];
    }

	str[n-1] = '\0';
}

void process(char str[], char outstr[]) {
    int n = strlen(str);

    outstr[n+1] = '\0';

    for(int i = 0; i < n; i++){
		if(str[i] == ' ' && str[i-1] == ' '){
			del(str,i);
			i--;
		}
    }

    if(str[0] == ' ')
		del(str, 0);

    if(str[n-1] == ' ')
		del(str, n);

	for(int i = 0; i < n; i++){
	    outstr[i] = str[i];
	}
}
int main() {
    char str[] = " vvv' '  '  ' .m,b erthb  " ;
    char *outstr = new char[strlen(str) + 1];

    process(str, outstr);
    
    cout << outstr;
    
    return 0;
}