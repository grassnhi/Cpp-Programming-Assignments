#include <iostream>
using namespace std;
class Addition {
public:
    int ADD(int X,int Y){
        return X+Y;
    }

    int ADD() {
        string a= "HELLO";
        string b="SAM"; 
        string c= a+b;
        cout<<c<<endl;
        return 0;
        }
};

int main(void) {
    Addition obj;   
    cout<<obj.ADD(128, 15)<<endl; 
    obj.ADD();  
    return 0;
}
