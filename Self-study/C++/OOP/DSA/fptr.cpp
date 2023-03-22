#include<iostream>

using namespace std;

int addNum(int* ptr, int n){
    int total = 0;
	for(int i = 0; i < n; i++){
        total += *(ptr+i);
    }
	return total;

}

size_t removeNum(int* ptr, int n){
    int m = n;
    for(int i = 0; i < m; i++){
        if(*(ptr+i)%2 != 0){
            for(int j = i; j < n-1; j++){
                *(ptr+j) = *(ptr+j+1);
            } 
            i--;
            m = n - 1;
        }
    }
    int arr[m];
    for(int i = 0; i < m; i++){
        arr[i] = *(ptr+i);
    }
    return arr[m];
}

int ptrLen(const char *p){
    int i = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    return i;
}

int ptrCmp(char* p1, char* p2){
    int i = 0;
    if(ptrLen(p1) == ptrLen(p2)){
        while((*p1!='\0')){
            if(*p1 > *p2)
                return 1;
            if(*p1 < *p2)
                return -1;
            p1++;
            p2++;
        }
        return 0;
    }else if(ptrLen(p1) > ptrLen(p2)){
        return 1;
    }else return -1;
}

char* ptrCat(char* p1, char* p2){
    int len1 = ptrLen(p1);

    while (*p2 != '\0')
    {
        p1[len1] = *p2;
        p2++;
        len1++;
    }

    p1[len1] = '\0';

    return (char*) p1;
}

char* ptrChr(const char* p, int c){
    while(*p != '\0'){
        if(*p == c){
            return (char*) p;

        }else 
            p++;
    }
    return NULL;
}

int main(){
    char str[5] = "1245";
    char s[7] = "125677";
    cout << ptrCat(str, s) << endl;

    return 0;
}