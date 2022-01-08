#include <iostream>
using namespace std;

#define PASS 4.0f
int main(){
    float t = 5.5f;

    (t >= PASS) ? cout << "A passed this subject!\n" : cout << "A failed this subject!\n";

    string msg;
    msg = (t >= PASS) ? "A passed this subject!" : "A failed this subject!";
    cout << msg << endl;
    
    if(t >= PASS){
        cout << "A passed this subject!" << endl;
    }
    else{
        cout << "A failed this subject!" << endl;
    }
    return 0;
}