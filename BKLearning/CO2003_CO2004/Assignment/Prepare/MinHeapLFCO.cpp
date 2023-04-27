#include <string>
using namespace std;

class MinHeap
{
public:
    class Node{
    private:
        int ID; // ID
        string name; // name
        int NUM; // sổ lần gọi món
        int prior; // thứ tự ưu tiên
        friend class MinHeap;
    public:    
        Node(){}
        
        Node(int ID, string name, int NUM = 1, int prior) {
            this->ID = ID;
            this->name = name;
            this->prior = prior;
            this->NUM = NUM;
        }
    };
    
private:
    int capacity;
    int count;
    Node** nodes;
protected:
    bool compare(int position, int relative){
        if(this->nodes[relative]->NUM > this->nodes[position]->NUM){
            return true;
        }else if(this->nodes[relative]->NUM == this->nodes[position]->NUM){
            if(this->nodes[relative]->prior > this->nodes[position]->prior){
                return true;
            }
        }
        return false;
    }
    void reheapUp(int position){
        if(position <= 0 || position >= this->count){
            return;
        }
        int parent = (position - 1) / 2;
        if(compare(position, parent)){
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
         
        // con < cha => swap (2 con: con min swap cha, bằng: con trái swap cha)
        if(leftChild < this->count){
            int minChild = position;
            if(rightChild < this->count && compare(rightChild, leftChild)){
                minChild = rightChild;
            }
            if(compare(minChild, position)){
                Node* tmp = this->nodes[position];
                this->nodes[position] = this->nodes[minChild];
                this->nodes[minChild] = tmp;
                this->reheapDown(minChild);
            }
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

    int locateID(string name){
        if (this->isEmpty()) {
            return -1;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                return i;
            }
        }
        return -1;
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

    void insert(int ID, string name, int NUM, int prior){
        if (this->count < this->capacity) {
            this->nodes[count]->ID = ID;
            this->nodes[count]->name = name;
            this->nodes[count]->NUM = NUM;
            this->nodes[count]->prior = prior;
            this->count++;
            this->reheapUp(this->count - 1);
        }
    }

    bool checkName(string name){
        if (this->isEmpty()) {
            return false;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                return true;
            }
        }
    }

    void updateOrder(string name){
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                this->nodes[i]->NUM++;
                
                Node* tmp = this->nodes[i];
                this->nodes[i] = this->nodes[this->count - 1];
                this->nodes[this->count - 1] = tmp;
                
                this->count--;
                this->reheapDown(i);
                
                this->count++;
                this->reheapUp(this->count - 1);
            }
        }
    }

    int numOrders(string name){
        int index = this->locateID(name);
        if(index != -1){
            return this->nodes[index]->NUM;
        }
        return -1;
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

    int getCount(){
        return this->count;
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

    int FIFO(){
        int min = 0;
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->prior < this->nodes[min]->prior){
                min = i;
            }
        }
        return nodes[min]->ID;
    }

    void priorDelete(int number){
        for(int i = 0; i < number; i++){
            int index = this->FIFO();
            this->remove(index);
        }
    }
};
