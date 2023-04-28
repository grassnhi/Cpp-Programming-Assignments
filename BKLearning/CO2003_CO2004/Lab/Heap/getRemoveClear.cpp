/*
Implement method remove to remove the element with given value from a maxHeap, clear to remove all elements and bring the heap back to the initial state.  You also have to implement method getItem to help you. Some given methods that you don't need to implement again are push, printHeap, ensureCapacity, reheapUp, reheapDown.

class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

// Your code here



For example:

Test	Result
Heap<int> maxHeap;
int arr[] = {42,35,30,15,20,21,18,3,7,14};
for (int i = 0; i < 10; i++)
    maxHeap.push(arr[i]);
maxHeap.remove(42);
maxHeap.remove(35);
maxHeap.remove(30);
maxHeap.printHeap();
Max Heap [ 21 20 18 15 14 7 3 ]
Heap<int> maxHeap;
int arr[] = {78, 67, 32, 56, 8, 23, 19, 45};
for (int i = 0; i < 8; i++)
    maxHeap.push(arr[i]);
maxHeap.remove(78);
maxHeap.printHeap();
Max Heap [ 67 56 32 45 8 23 19 ]
Heap<int> maxHeap;
int arr[] = { 13, 19, 20, 7, 15, 12, 16, 10, 8, 9, 3, 6, 18, 2, 14, 1, 17, 4, 11, 5 };
for (int i = 0; i < 20; ++i)
    maxHeap.push(arr[i]);
maxHeap.clear();
maxHeap.printHeap();
Max Heap [ ]
*/

class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

// Your code here
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    if (this->count == 0) return -1;
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = this->getItem(item);
    if (index == -1) return;
    else {
        this->elements[index] = this->elements[this->count - 1];
        --this->count;
        this->reheapDown(index);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete[] this->elements;
    this->elements = NULL;
    this->count = 0;
}