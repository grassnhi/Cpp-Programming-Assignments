#include<iostream>

using namespace std;

class Add
{ 
public: 
    virtual void print (){ 
        int a=20, b=30;
        cout<< " base class Action is:"<<a+b <<endl;
    } 
    void show () { 
        cout<< "show base class" <<endl; 
    } 
}; 

class Sub: public Add 
{ 
public: 
    void print (){ 
	int x=20,y=10;
        cout<< " derived class Action:"<<x-y <<endl; 
        
    } 
    
    void show (){ 
        cout<< "show derived class" <<endl; 
        
    } 
}; 

int main() { 
    Add *aptr; 
    Sub s; 
    aptr = &s; 
    
    aptr->print(); 
    
    aptr->show(); 
    
    return 0; 
} 
