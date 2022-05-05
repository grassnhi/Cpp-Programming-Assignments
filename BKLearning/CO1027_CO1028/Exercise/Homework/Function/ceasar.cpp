/*
Write a function to encrypt a text string using Caesar Cipher technique.

In this technique, to encrypt a string we need a parameter of type integer called 'shift'.

The encrypt method will shift each letter by some fixed number of position (determined by the parameter 'shift') to the right in the alphabet. For example, when 'shift' is 3, 'a' will be replaced by 'd', 'b' will become 'e', ... , 'z' will become 'c'.

The decrypt method will receive an encoded string and a shift value and it will decode this string to get the original string, which means shifting each character to the left in the alphabet.

Input:

char* text: the text string that needs to be encrypted or decrypted. text only contains lowercase and uppercase ASCII letters
int shift: the shift value in Caesar Cipher technique
*/
#include <iostream>

using namespace std;

void encrypt(char* text, int shift) {
    int l = 0;
    while (text[l] != '\0') l++;
    shift = shift % 26;
    for (int i = 0; i < l; i++)
    {
        if (isupper(text[i]))
        {
            int num = (int)text[i] + shift;
            if (num > 90)
                num -= 26;
            text[i] = (char)num;
        }
        else if (islower(text[i]))
        {
            int num = (int)text[i] + shift;
            if (num > 122)
                num -= 26;
            text[i] = (char)num;
        }
    }
    text[l] = '\0';
}

void decrypt(char* text, int shift) {
    // Write your code 
    int l = 0;
    while (text[l] != '\0') l++;
    shift = shift % 26;
    shift = -shift;
    for (int i = 0; i < l; i++)
    {
        if (isupper(text[i]))
        {
            int num = (int)text[i] + shift;
            if (num < 65)
                num += 26;
            text[i] = (char)num;
        }
        else if (islower(text[i]))
        {
            int num = (int)text[i] + shift;
            if (num < 97)
                num += 26;
            text[i] = (char)num;
        }
    }
    text[l] = '\0';
}

int main(){
    int n, shift; 
    cin >> n >> shift;
    char* text = new char[n+1];
    for(int i = 0; i < n; i++) cin >> text[i];
    text[n] = 0;

    encrypt(text, shift);
    cout << text << '\n';
    decrypt(text, shift);
    cout << text;

    delete[] text;
}