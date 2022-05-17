#include<iostream>

using namespace std;

int main(){
    bool a = true;
    cout << a << endl;

    bool b = 0;
    cout << b << endl;
    
    bool c = 1;
    cout << c << endl;

    bool d = 3;
    cout << d << endl;

    bool e;
    cout << "Enter e: " << endl;
    cin >> e;
    
    if(e == false){
        cout << "FALSE" << endl;
    }else cout << "TRUE" << endl;
    

    return 0;
}