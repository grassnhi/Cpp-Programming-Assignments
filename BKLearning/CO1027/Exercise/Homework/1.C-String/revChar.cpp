/*
Implement void process(const char *str, char *outstr) function which reverses the string.

- Input: Char * pointer to the first character of string

- Output: The result is written to outstr

- Available library: <iostream>, <cstring>

- Note: Your code MUST NOT contain any of the words in the list {"include", "string"} even in the comment
*/

#include <iostream>

using namespace std;

int len(const char str[])
{
    int i = 0;

    while (str[i] != '\0'){
      i++;
    }

    return i-1;
}

void process(const char *str, char *outstr) {
    int n = len(str);
    
    outstr[n+1] = '\0';

    for (int i=0, j=n; i<= n; i++,j--)
        outstr[i] = str[j];
}

int main()
{
    char str[] = "cvbn" ;

    char *outstr = new char[len(str) + 1];

    process(str, outstr);

    cout << outstr;
    
    return 0;
}
