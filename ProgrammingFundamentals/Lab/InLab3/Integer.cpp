/*
Thực hiện các yêu cầu sau:

Xây dựng một class Integer gồm một thành phần private tên là val là một số nguyên kiểu int. 
Hiện thực constructor: Integer(int).
Hiện thực constructor: Integer(Integer*).
Quá tải toán tử operator + để phép tính Integer(2) + Integer(3)  trả về Integer(5).
Quá tải toán tử operator + để phép tính Integer(3) + 2 trả về Integer(5).
Chú ý: khai báo phương thức print() trong định nghĩa của class và không cần hiện thực.

[English]

Implement following requirements:
Define class Integer that contains one attribute named val of type int.
Implement constructor: Integer(int): assign value of parameter to attribute val.
Implement constructor: Integer(Integer*).
Overload operator + so that: Integer(2) + Integer(3) returns Integer(5).
Overload operator + so that: Integer(3) + 2 returns Integer(5).
Note: declare method print() in class's definition and do not provide its implementation.
For example:

Test	Input	Result
1
1 2 3
1
2
10

*/

#include<iostream>
using namespace std;

// TODO
class Integer{
    private:
        int val;
        
    public:
        Integer(int val){
            this->val = val;
        };
        Integer(Integer* integer){
            this->val = integer->val;
        };
        Integer operator+(const Integer& other) const{
            return Integer(this->val + other.val);
        };
        Integer operator+(int x) const{
            return Integer(this->val + x);
        };
        void print();
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