#include <iostream>
#include <cassert>

using namespace std;

const int MAXSIZE = 32;

class MinHeap
{
public:
    class Node {
    public:
        int ID;
        int name;
        int NUM;
        
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
        if(this->nodes[parent]->NUM < this->nodes[position]->NUM){
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
        
        if(leftChild < this->count && this->nodes[leftChild]->NUM < this->nodes[minChild]->NUM){
            minChild = leftChild;
        }
        
        if(rightChild < this->count && this->nodes[rightChild]->NUM < this->nodes[minChild]->NUM){
            minChild = rightChild;
        }
        
        if(minChild != position){
            Node* tmp = this->nodes[position];
            this->nodes[position] = this->nodes[minChild];
            this->nodes[minChild] = tmp;
            this->reheapDown(minChild);
        }
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

    void push(int ID, int name, int NUM){
        if (this->count < this->capacity) {
            this->nodes[count]->ID = ID;
            this->nodes[count]->name = name;
            this->nodes[count]->NUM = NUM;
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
};

int main() {
    // Create a new heap
    MinHeap* heap = new MinHeap();
    
    // Test isEmpty() on an empty heap
    assert(heap->isEmpty());
    
    // Test push() and getCount()
    heap->push(1, 222, 3);
    heap->push(2, 333, 2);
    heap->push(3, 444, 4);
    assert(!heap->isEmpty());
    assert(heap->getCount() == 3);
    
    // Test locateID()
    assert(heap->locateID(2) == 1);
    assert(heap->locateID(4) == -1);
    
    // Test increaseNUM()
    heap->increaseNUM(0);
    
    // Test remove()
    heap->remove(1);
    assert(heap->getCount() == 2);

    
    // Test clear() and isEmpty()
    //heap->clear();
    //assert(heap->isEmpty());
    
    cout << "All tests passed!\n";
    delete heap;
    return 0;
}