/*
Cho class template Array như bên dưới dùng để chứa một mảng (1 chiều) được khai báo trong vùng nhớ Heap. Trong class Array có khai báo một số phương thức (hàm) để thao tác với Array.

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
Trong class Array có khai báo các thuộc tính sau:

Thuộc tính p là con trỏ trỏ đến vùng nhớ Heap được cấp phát.

Thuộc tính size của Array chứa số lượng phần tử của mảng.

Yêu cầu: hiện thực hàm Copy Constructor và Copy Assignment operator:

Hàm Array(const Array<T> & other): copy constructor, khởi tạo đối tượng mới dựa trên dữ liệu của đối tượng được cung cấp (other). Đồng thời, in ra thông báo: "Call copy constructor"
Hàm operator=: copy assignment operator, gán giá trị của đối tượng hiện tại bằng giá trị của đối tượng được cung cấp. Đồng thời, in ra thông báo: "Call assignment operator" 
[English]

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
p: a pointer contains the address of first element of allocated memory.
size: number of elements of array.
Requirement: Implement following method:
Method Array(const Array<T> & other): copy constructor, initialize new object based on data of provided object. Also, print out the message: "Call copy constructor"
Method operator=: copy assignment operator, assigns the value of the current object's attributes to the value of the provided object. Print out the message: "Call assignment operator"




For example:

Test	Result
// Test copy constructor
    Array<int> * a3;
    Array<int> * a4 = new Array<int>(10, 3);
    a3 = new Array<int>(*a4);
    delete a4;
    a3->print();
    delete a3;
Call copy constructor
3 3 3 3 3 3 3 3 3 3

*/

#include <iostream>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other); // Copy assignment operator
    
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
template <typename T>
Array<T>::Array(const Array<T> & other){
    cout << "Call copy constructor" << endl;
    this->size = other.size;
    this->p = new T[this->size];
    for(int i = 0; i < this->size; i++){
        this->p[i] = other.p[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> & other){
    cout << "Call assignment operator" << endl;
    if (this == &other){
        return *this;
    }  // self-assignment check

    delete[] this->p;

    this->size = other.size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->p[i] = other.p[i];
    }

    return *this;
}

