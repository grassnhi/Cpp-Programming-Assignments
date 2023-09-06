#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char hello1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    char hello2[] = "Hello";

    string hello3 = "Hello!";

    string hello4("Hello!");

    cout << hello1 << " " << hello2 << " " << hello3 << " " << hello4 << endl;

    char s0[] = " ";
    char s1[] = "Nhi";
    char s2[] = "Hien";
    strcpy(s0, s2);
    cout << s0 << " " << s1 << " " << s2 << endl;

    char s3[] = "Minh";
    strcat(s1, s3);
    cout << s0 << " " << s1 << " " << s2 << " " << s3 << endl;

    return 0;
}