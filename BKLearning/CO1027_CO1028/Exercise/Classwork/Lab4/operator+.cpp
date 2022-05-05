/*
Implement following requirements:
    Define class Integer that contains one attribute named val of type int.

Implement constructor: 
    Integer(int): assign value of parameter to attribute val.

Implement constructor: 
    Integer(Integer*).

Overload operator + so that: 
    Integer(2) + Integer(3) returns Integer(5).

Overload operator + so that: 
    Integer(3) + 2 returns Integer(5).

Note: 
    declare method print() in class's definition and do not provide its implementation.
*/


#include<iostream>
using namespace std;

// TODO
class Integer{
    private:
        int val;
    public:
    void print();
    Integer(int val){
        this->val = val;
    }
    Integer(Integer* a){
        this->val = a->val;

    }
    Integer operator + (Integer const &int1){
        this->val += int1.val;
        return this->val;
    }
};

void Integer::print() {
    cout << this->val << endl;
}


int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    return 0;
}