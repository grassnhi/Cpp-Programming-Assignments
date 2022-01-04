#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;

    if (a > 20) 
        goto esc;
   	else cout << a*a;
        esc: cout << endl;

    return 0;
}
