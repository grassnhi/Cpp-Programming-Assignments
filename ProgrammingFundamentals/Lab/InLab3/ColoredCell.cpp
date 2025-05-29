/*
Hãy xem xét định nghĩa sau: 

template < class T >
class Cell { 
       protected: 
           T info; 
       public: 
           void set(T x){ info = x; } 
           T get() { return info; } 
   }; 
enum Color {White, Yellow, Black, Red, Blue};

Định nghĩa một lớp con ColoredCell của Cell với:

1. Với một biến color.

2. Hàm setColor(Color ) để cài đặt màu cho ô

3. Hàm getColor() để lấy màu của ô (trả về kiểu dữ liệu của màu).

4. Cập nhật method get để trả về con trỏ đến info nếu ô này không trắng, ngược lại trả về NULL.

[English]

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



For example:

Test	Input	Result
1
1 2
2

*/

#include <iostream>
#include <string.h>

using namespace std;

template<class T> class Cell {
protected:
    T infor;
public:
    void set(T _infor) { this->infor = _infor; };
    T get() { return this->infor; };
};

enum Color {White, Yellow, Black, Red, Blue};

// TODO
template<class T>
class ColoredCell : public Cell<T> {
private:
    Color color;
public:
    void setColor(Color c) {
        color = c;
    }

    Color getColor() {
        return color;
    }

    T* get() {
        if (color == White) return NULL;
        return &(this->infor);
    }
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