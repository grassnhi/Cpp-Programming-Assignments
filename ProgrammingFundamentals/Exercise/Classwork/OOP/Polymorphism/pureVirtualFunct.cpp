#include <iostream> 
using namespace std;
class Animal{
    public: 
    virtual void show() = 0;    
};  
class Man: public Animal     
{   
    public: 
    void show()  
    {    
        cout << "Hello there" << endl;  
    }   
};   

int main()  
{    
    Animal *aptr; //Base class pointer 
     
    Man m;   //derived class object creation.
    aptr = &m;   
    aptr->show();
    return 0;    
}
