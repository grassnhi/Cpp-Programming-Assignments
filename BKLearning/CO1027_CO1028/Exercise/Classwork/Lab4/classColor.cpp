/*
Given the following declaration: 

        template < class T >
        class Cell { 
            protected: 
                T info; 
            public: 
                void set(T x){ info = x; } 
                T get() { return info; } 
        }; 
        enum Color {White, Yellow, Black, Red, Blue};

Define a class ColoredCell as a child of class Cell with:

    1. A variable color.

    2. Function setColor(Color ) to set a cell's color.

    3. Function getColor() to return a cell's color.

    4. Overload function get() to return the pointer to info if the cell's color is not white, else return NULL.
*/

#include<iostream>

using namespace std;

#include <iostream>
#include <string.h>

using namespace std;

template<class T> class Cell {
protected:
    T infor;
public:
    void set(T _infor) { this->infor = _infor; };
    T get() { 
         
        if(infor != 1)  return this->infor;
        else return NULL;
    };
};

enum Color {White, Yellow, Black, Red, Blue};

// TODO
template<class T> class ColoredCell: public Cell<T>{
    protected:
        Color color;
    public:
        void setColor(Color color){
            this->color = color;
        };
        Color getColor(){
            return this->color;
            
        };
        T *get() { 
            if (this->color != White) { 
                return &(this->infor); 
            }else { 
                return NULL;
            } 

 };
        
};

int main () {
    int test, c;
    cin >> test >> c;
    ColoredCell<int>* a = new ColoredCell<int>();
    switch (test)
    {
    case 1:
        a->setColor(Color(c));
        cout << int(a->getColor());
        break;
    case 2:
        a->setColor(Color(c));
        a->set(10);
        if (a->get() == NULL) cout << "null" << endl;
        else cout << *(a->get());
    default:
        break;
    }
    return 0;
}

