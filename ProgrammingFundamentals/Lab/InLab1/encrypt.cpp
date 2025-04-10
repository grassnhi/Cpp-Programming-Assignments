#include <iostream>
using namespace std;

void encrypt(char* text, int shift) {
    // Write your code 
    if(shift < 0){
        shift = 0 - shift;
    }
    if(shift > 26){
        shift = shift % 26;
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') { 
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
    }
}

void decrypt(char* text, int shift) {
    // Write your code 
    if(shift < 0){
        shift = 0 - shift;
    }
    if(shift > 26){
        shift = shift % 26;
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - shift +26 ) % 26) + 'a';
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') { 
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
        }
    }
}

int main() {
    int n, shift;
    cin >> n >> shift;
    char* text = new char[n + 1];

    for (int i = 0; i < n; i++) cin >> text[i];
    text[n] = '\0';

    encrypt(text, shift);
    cout << text << '\n';

    decrypt(text, shift);
    cout << text << '\n';

    delete[] text;
    return 0;
}
