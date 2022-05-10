#include<iostream>

using namespace std;

void substring(char* str, int n, int start, int outSize, char* out) {
    str[n] = '\0';
    if(n - start < outSize) outSize = n - start;
    for(int i = start; i < n - start; i++){
        
        out[i-start]= str[i];
        cout << i - start << endl;
    }
    out[n-start-1] = '\0';
    cout << n - start << endl;
}

int main(){
    int n, start, size;
    cin >> n >> start >> size;
    char str[256], out[256];
    cin >> str;
    substring(str, n, start, size, out);
    cout << out << '\n';
    return 0;
}