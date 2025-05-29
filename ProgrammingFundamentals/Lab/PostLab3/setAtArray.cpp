/*
Cho class template Array như bên dưới dùng để chứa một mảng (1 chiều) được khai báo trong vùng nhớ Heap. Trong class Array có khai báo một số phương thức (hàm) để thao tác với Array.

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void setAt(int idx, const T & value);
    T getAt(int idx);
    void print();
private:
    int size;
    T * p;
};
Trong class Array có khai báo các thuộc tính sau:

Thuộc tính p là con trỏ trỏ đến vùng nhớ Heap được cấp phát.

Thuộc tính size của Array chứa số lượng phần tử của mảng.

Yêu cầu: SV hiện thực phương thức được mô tả như sau:
setAt(int idx, const T & value): gán giá trị value cho phần tử ở trị ví idx. Nếu idx có giá trị không hợp lệ (idx < 0 hoặc idx >= size) thì throw -1;
getAt(int idx): trả về phần tử tại vị trí idx. Nếu idx có giá trị không hợp lệ (idx < 0 hoặc idx >= size) thì throw -1;
[English]

Given class template Array as below that contains an array allocated in Heap memory.

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void setAt(int idx, const T & value);
    T getAt(int idx);
 
  void print();
private:
    int size;
    T * p;
};
There are 2 attributes in class Array:
p: a pointer contains the address of first element of allocated memory.
size: number of elements of array.
Requirement: Implement following method:

setAt(int idx, const T & value): set value to element at position idx. If idx has an invalid value (idx < 0 or idx >= size), throw -1.
getAt(int idx): returns value at position idx. If idx has an invalid value (idx < 0 or idx >= size), throw -1.






For example:

Test	Result
Array<int> * a7 = new Array<int>(10, 2);
    a7->print();
    try {
        a7->setAt(-1, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(10, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    try {
        a7->setAt(2, 99);
        a7->print();
    }
    catch (int exp) {
        cout << "Exception: " << exp << endl;
    }
    delete a7;
2 2 2 2 2 2 2 2 2 2
Exception: -1
Exception: -1
2 2 99 2 2 2 2 2 2 2

*/

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value);
    T getAt(int idx);
    
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
template<typename T>
void Array<T>::setAt(int idx, const T & value) {
    if (idx < 0 || idx >= size) {
        throw -1;
    }
    p[idx] = value;
}

template<typename T>
T Array<T>::getAt(int idx) {
    if (idx < 0 || idx >= size) {
        throw -1;
    }
    return p[idx];
}
