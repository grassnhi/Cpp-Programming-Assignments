/*
Cho class template Array như bên dưới dùng để chứa mảng 1 chiều được khai báo trong vùng nhớ Heap.

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
private:
    int size;
    T * p;
};

Trong class Array có khai báo các thuộc tính sau:

Thuộc tính p là con trỏ trỏ đến vùng nhớ Heap được cấp phát.

Thuộc tính size của Array chứa số lượng phần tử của mảng.

Yêu cầu:
SV hiện thực 2 phương thức được mô tả như sau:

Hàm Array(int size, T initValue): hàm khởi tạo(constructor), gán size vào số lượng phần tử của mảng; khởi tạo mảng 1 chiều có kích thước là size trong vùng nhớ Heap và lưu địa chỉ phần tử đầu tiên của mảng vào biến p.
Hàm ~Array(): hàm huỷ, thu hồi vùng nhớ Heap đã cấp phát.
SV thực hiện việc khai báo phương thức print (không định nghĩa) cho class Array.

[English]

Given class template Array as below that contains an array allocated in Heap memory.

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
private:
    int size;
    T * p;
};
There are 2 attributes in class Array:
p: a pointer contains the address of first element of allocated memory.
size: number of elements of array.
Requirement: Implement following 2 method:

Method Array(int size, T initValue): constructor, assigns size to the number of elements of the array; initializes a 1-dimensional array in the heap and stores the address of the first element of the array in the variable p.
Method ~Array(): destructor, recovers the allocated Heap memory.
Also, declare the print() method for the class Array (don't define the method).

For example:

Test	Result
Array<int> a1(5, 0);
a1.print();
0 0 0 0 0

*/

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
    
private:
    int size;
    T * p;
};

// TODO
template <typename T>
Array<T>::Array(int size, T initValue) {
    this->size = size;
    this->p = new T[this->size];
    for(int i = 0; i < this->size; i++){
        p[i] = initValue;
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] p;
}

// template <typename T>
// void Array<T>::print() {
//     for (int i = 0; i < this->size; i++) {
//         if (i > 0){
//             cout << " ";
//         }
//         cout << p[i];
//     }
//     cout << endl;
// }