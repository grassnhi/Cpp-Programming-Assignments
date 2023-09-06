/*
Given class template Array as below that contains an array allocated in Heap memory.

        template <typename T>
        class Array {
        public:
            Array(int size, T initValue);
            ~Array();
            Array(const Array<T> & other); // Copy constructor
            Array<T> & operator=(const Array<T> & other); // Copy assignment operator
        private:
            int size;
            T * p;
        };


There are 2 attributes in class Array:

    p:              a pointer contains the address of first element of allocated memory.
    size:           number of elements of array.
    
    Requirement:    Implement following method:

        Method Array(const Array<T> & other): copy constructor, 
                initialize new object based on data of provided object.
                Also, print out the message: "Call copy constructor"

        Method operator=: copy assignment operator, 
            assigns the value of the current object's attributes to the value of the provided object. 
            Print out the message: "Call assignment operator"
*/
#include<iostream>

using namespace std;

#include <iostream>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other){
        this->size = other.size; 
        this->p = new T[this->size]; 
        for (int i = 0; i < this->size; i++) { 
            this->p[i] = other.p[i];
        }
        cout << "Call copy constructor" << endl;
    } // Copy constructor
    Array<T> & operator=(const Array<T> & other){
        this->size = other.size; 
        this->p = new T[this->size]; 
        for (int i = 0; i < this->size; i++) { 
            this->p[i] = other.p[i];
        }
        cout << "Call assignment operator" << endl;
    } // Copy assignment operator
    
    void print();

private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

// TODO

int main(){
    // Test copy constructor
    Array<int> * a3;
    Array<int> * a4 = new Array<int>(10, 3);
    a3 = new Array<int>(*a4);
    delete a4;
    a3->print();
    delete a3;

    // // Test copy assignment operator
    Array<int> * a5 = new Array<int>(1, 2);
    Array<int> * a6 = new Array<int>(12, 5);
    *a5 = *a6;
    delete a6;
    a5->print();
    delete a5;
}