/*
Hãy thiết kế một class Integer với một biến private val dạng int, Class gồm các phương thức sau:

constructor nhận biến val ban đầu. 
setValue() để thay đổi giá trị biến val.
getValue() để lấy giá trị biến val.
Define a class Integer with one private variable val type int with:
_ A constructor with one input for val.
_ A function setValue() to change the value of val.
_ A function getValue() to return the value of val.

For example:

Test	Result
cout<<"Constructor test";
Integer i(10);
Integer i2(-10);
Integer *i3=new Integer(20);
delete i3;
Constructor test

*/

class Integer{
    private:
        int val;
        
    public:
        Integer(int val){
            this->val = val;
        }
        
        void setValue(int val){
            this->val = val;
        }
        
        int getValue(){
            return this->val;
        }
};