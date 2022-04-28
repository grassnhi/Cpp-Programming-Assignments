#include <iostream>  
using namespace std;  
class Animal {  
    public:  
void function(){    
	cout<<"Eating..."<<endl;    
    }      
};   

/*
class Man: public Animal    
{    
 	public:  
		void function(){    
		cout<<"Walking ..."<<endl;    
		}    
};  
*/


class Man: public Animal    
{    
  
};  



int main(void) {  
 	Animal A =Animal();
  	A.function();   //parent class object 
   	Man m = Man();    
   	m.function();   // child class object
   
   	return 0;  
}
