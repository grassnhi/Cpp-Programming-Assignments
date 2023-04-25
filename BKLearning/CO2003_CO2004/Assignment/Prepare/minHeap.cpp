#include <iostream>
#include <cassert>

using namespace std;

const int MAXSIZE = 32;

class MinHeap
{
public:
    class Node {
    private:
        int ID;
        int name;
        int NUM;
        int order;
        friend class MinHeap;
    public:    
        Node(){}
        
        Node(int ID, int name, int NUM) {
            this->ID = ID;
            this->name = name;
            this->NUM = NUM;
        }
    };
    
private:
    int capacity;
    int count;
    Node** nodes;
protected:
    void reheapUp(int position){
        if(position <= 0 || position >= this->count){
            return;
        }
        int parent = (position - 1) / 2;
        if(this->nodes[parent]->NUM > this->nodes[position]->NUM || 
                (this->nodes[parent]->NUM == this->nodes[position]->NUM && 
                    this->nodes[parent]->order > this->nodes[position]->order)){
            Node* tmp = this->nodes[parent];
            this->nodes[parent] = this->nodes[position];
            this->nodes[position] = tmp;
            this->reheapUp(parent);
        }
    }

    void reheapDown(int position){
        if(position < 0 || position >= this->count){
            return;
        }
        int leftChild = 2 * position + 1;
        int rightChild = 2 * position + 2;
        int minChild = position; 
        // con < cha => swap (2 con: con min swap cha, bằng: con trái swap cha)
        if(leftChild < this->count && this->nodes[leftChild]->NUM < this->nodes[minChild]->NUM){
            minChild = leftChild; // left < cha => min = left
        }
        
        if(rightChild < this->count && this->nodes[rightChild]->NUM < this->nodes[minChild]->NUM){
            minChild = rightChild; // right < cha or right < left => min = right
        }
        
        if(minChild != position || minChild == position && this->nodes[minChild]->order < this->nodes[position]->order){ 
            Node* tmp = this->nodes[position];
            this->nodes[position] = this->nodes[minChild];
            this->nodes[minChild] = tmp;
            this->reheapDown(minChild);
        }   // min = con => swap
    }

public:
    MinHeap(){
        this->capacity = MAXSIZE;
        this->count = 0;
        this->nodes = new Node*[capacity]; 
        for (int i = 0; i < capacity; i++) {
            nodes[i] = new Node();  
        }
    }

    ~MinHeap(){
        clear();
    }

    void insert(int ID, int name, int NUM, int order){
        if (this->count < this->capacity) {
            this->nodes[count]->ID = ID;
            this->nodes[count]->name = name;
            this->nodes[count]->NUM = NUM;
            this->nodes[count]->order = order;
            this->count++;
            this->reheapUp(this->count - 1);
        }
    }

    int locateID(int ID){
        if (this->isEmpty()) {
            return -1;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->ID == ID) {
                return i;
            }
        }
        return -1;
    }

    void increaseNUM(int i){
        this->nodes[i]->NUM++;
    }

    int getCount(){
        return this->count;
    }

    int getName(int index){
        if (this->isEmpty()) {
            return -1;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->ID == index) {
                return this->nodes[i]->name;
            }
        }
        return -1;
    }

    int getName(){
        return this->nodes[0]->name;
    }

    void remove(int ID){
        int index = this->locateID(ID);
        if (index == -1) {
            return;
        }else{
            this->nodes[index] = this->nodes[this->count - 1];
            this->count--;
            this->reheapDown(index);
        }
    }

    
    bool isEmpty(){
        return (this->count == 0);
    }

    void clear(){
        for (int i = 0; i < this->capacity; i++) {
            if (this->nodes[i] != nullptr) {
                delete this->nodes[i];
            }
        }
        delete[] this->nodes;  
        this->nodes = nullptr;
        this->count = 0;
    }

    void printHeap()
    {
        cout << "Heap [ ";
        for (int i = 0; i < count; i++)
            cout << nodes[i]->NUM << "-" << nodes[i]->order << " ";
        cout << "]\n";
    }
};

int main() {
    // Create a new heap
    MinHeap* heap = new MinHeap();
    
    // Test isEmpty() on an empty heap
    assert(heap->isEmpty());
    
    // Test insert() and getCount()
    heap->insert(1, 222, 3, 1);
    heap->insert(2, 333, 9, 2);
    heap->insert(3, 444, 10, 3);
    heap->insert(1, 222, 3, 4);
    heap->insert(2, 333, 9, 5);
    heap->insert(3, 444, 10, 6);
    assert(!heap->isEmpty());
    assert(heap->getCount() == 6);
    
    // Test locateID()
    //assert(heap->locateID(2) == 1);
    //assert(heap->locateID(4) == -1);

    heap->printHeap();
    
    // Test increaseNUM()
    heap->increaseNUM(0);
    
    // Test remove()
    heap->remove(2);
    assert(heap->getCount() == 5);

    heap->printHeap();
    // Test clear() and isEmpty()
    //heap->clear();
    //assert(heap->isEmpty());

    cout << " " << heap->getName() << " ";
    
    cout << "All tests passed!\n";
    delete heap;
    return 0;
}