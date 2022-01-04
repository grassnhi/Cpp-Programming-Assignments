// Bool: True/ False
// bool rs = ( a== 5 ) => rs = 1 if a = 5 otherwise rs = 0

#include <iostream>
using namespace std;

int main() {
    int a = 5, rs;
    rs = ( a == 5 ) && ( a == 10 ); 
    // rs = 0 because the right hand side is false
    cout << rs << endl;
    return 0;
}