/*
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
    p:              a pointer contains the address of first element of allocated memory.
    size:           number of elements of array.
    Requirement:    Implement following 2 method:

Method Array(int size, T initValue): constructor, assigns size to the number of elements of the array; 
                                    initializes a 1-dimensional array in the heap and stores 
                                    the address of the first element of the array in the variable p.

Method ~Array(): destructor, recovers the allocated Heap memory.

Also, declare the print() method for the class Array (don't define the method).

*/

template <typename T>
class Array {
public:
    Array(int size, T initValue){
        this-> size =size;
        int *arr = new int[size];
        p = arr;
        for(int i = 0; i < size; i++){
            *(p+i) = initValue;
        }
    };
    ~Array(){
        delete p;
    };
    void print();
private:
    int size;
    T * p;
};

// TODO

int main(){
    Array<int> a1(5, 0);
    a1.print();
}