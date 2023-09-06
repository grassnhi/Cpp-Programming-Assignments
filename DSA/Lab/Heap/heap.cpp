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
        // ủa delete chưa?
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

template<class T>
void Heap<T>::push(T item){
    if (this->count == this->capacity) this->ensureCapacity(this->capacity * 2);
    this->elements[count] = item;
    ++this->count;
    this->reheapUp(this->count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* newElements = new T[minCapacity];
    for (int i = 0; i < this->count; ++i) {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->capacity = minCapacity;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position <= 0 || position >= this->count) return;
    int parent = (position - 1) / 2;
    if (this->elements[parent] < this->elements[position]) {
        int temp = this->elements[parent];
        this->elements[parent] = this->elements[position];
        this->elements[position] = temp;
        reheapUp(parent);
    }
    return;
}

void swap(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index > (numberOfElements)/2 || index<0)   return;
    int i= index;
    int largest_e=0;
        if((2*i + 1) < numberOfElements){
            int left_e= 2*i +1;        
            if((2*i +2) < numberOfElements){
                int right_e= 2*i +2;
                if(maxHeap[left_e] > maxHeap[right_e])    largest_e= left_e;
                else    largest_e= right_e;
            }
            else    largest_e= left_e;
        }
        else    return;
        if(maxHeap[i] < maxHeap[largest_e]){
            swap(maxHeap[i], maxHeap[largest_e]);
            reheapDown(maxHeap, numberOfElements, largest_e);
            //break;
        }
    return;
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index<=0 || index >= numberOfElements)   return;
    int parent_i= (index-1)/2;
    if(maxHeap[parent_i] < maxHeap[index]){
        swap(maxHeap[parent_i], maxHeap[index]);
        reheapUp(maxHeap, numberOfElements, parent_i);
    }
    return;
}

template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (this->count == 0);
}

template<class T>
T Heap<T>::peek(){
    if (this->isEmpty()) return -1;
    return this->elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    if (this->isEmpty()) return false;
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (this->isEmpty()) return false;
    this->elements[0] = this->elements[this->count - 1];
    --this->count;
    this->reheapDown(0);
    return true;
}