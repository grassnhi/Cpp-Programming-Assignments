/*
Define a class Integer with one private variable val type int with:
_ A constructor with one input for val.
_ A function setValue() to change the value of val.
_ A function getValue() to return the value of val.
*/

#include <iostream>

using namespace std;

class Integer
{
    private:
        int val;
    public:
        Integer(int val){
            this->val = val;
        }
        
        int getValue(){
            this->val = val;
            return val;
        }
        
        int setValue(int val){
            this->val = val;
            val = val + 1;
            return val;
        }
         
};

int main(){
    cout<<"Constructor test";
    Integer i(10);
    Integer i2(-10);
    Integer *i3=new Integer(20);
    delete i3;
}