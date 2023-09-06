/*
Given class template Array as below that contains an array allocated in Heap memory.

            template <typename T>
            class Array {
            public:
                Array(int size, T initValue);
                ~Array();
                Array(const Array<T>& other);
            private:
                int size;
                T * p;
            };

There are 2 attributes in class Array:

    p:              a pointer contains the address of first element of allocated memory.

    size:           number of elements of array.

    Requirement:    Implements the Copy Constructor method (highlighted in red), 
                    which initializes a new Array object based on other Array object.

*/
#include<iostream>

using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
    
    Array(const Array<T> & other){
        this->size = other.size; 
        this->p = new T[this->size]; 
        for (int i = 0; i < this->size; i++) { 
            this->p[i] = other.p[i];
        }
        //p = array;
    }; // Copy Constructor
    
private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}

// TODO
int main(){
    Array<int> * a3;
    Array<int> * a4 = new Array<int>(10, 3);
    a3 = new Array<int>(*a4);
    delete a4;
    a3->print();
    delete a3;
}
