/*
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
*/
template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value){
        
        if(idx < 0 || idx >= size) throw -1;
        else this->p[idx] = value;

    };
    T getAt(int idx){
        if(idx < 0 || idx >= size) throw -1;
        return this->p[idx];

    };
    
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

