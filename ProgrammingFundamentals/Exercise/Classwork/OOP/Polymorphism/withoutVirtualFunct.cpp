#include <iostream>
using namespace std;
class Add
{
    int x=5, y=20; 
    public:
    void display() //overridden function
    {
        cout << "Value of x is : " << x+y<<endl; 
    } 
};
class Substract: public Add
{ 
    int y = 10,z=30; 
    public:
    void display() //overridden function
    { 
        cout << "Value of y is : " <<y-z<<endl;
    }
};

int main()
{   
    Add *m; 
    Substract s;    
    m = &s; 
    m->display();   
    return 0;   
}
