#include <iostream>
using namespace std;

class Deque {
private:
    class Node {
    private:
        int value;
        Node* left;
        Node* right;
        friend class Deque;
    public:
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr) : value(val), left(l), right(r) { }
    };

private:
    Node* head;
    Node* tail;
    int curSize;

public:
    Deque() : head(nullptr), tail(nullptr), curSize(0) { }
    ~Deque() { clear(); }
    
    int getSize() {
        return curSize;
    }
    
    void pushFront(int item) {
        Node* newNode = new Node(item, nullptr, head);
        if (head != nullptr)
            head->left = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = head;class Deque {
private:
    class Node {
    private:
        int value;
        Node* left;
        Node* right;
        friend class Deque;
    public:
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr) : value(val), left(l), right(r) { }
    };

private:
    Node* head;
    Node* tail;
    int curSize;

public:
    Deque();
    ~Deque();
    int getSize();
    void pushFront(int item);
    void pushBack(int item);
    int popFront();
    int popBack();
    void clear();
    void printDequeReverse();
    void printDeque();
};

Deque::Deque() {
    this->head = nullptr;
    this->tail = nullptr;
    this->curSize = 0;
}

Deque::~Deque() {
    clear();
}

void Deque::clear() {
    //=> erase all items in the deque
    if(head == nullptr){
        head = tail = nullptr;
    }else{
        Node* tmp = head;
        while (head != nullptr)
        {
            tmp = head;
            head = head->right;
            delete tmp;
        }
        tail = nullptr;
    }
    curSize = 0;
}

int Deque::getSize() {
    //=> number of items in the deque
    return curSize;
}

void Deque::pushFront(int i) {
    //=> add an item to the left end
    if(head == nullptr){
        head = tail = new Node(i);
    }else{
        head->left = new Node(i, nullptr, head);
        head = head->left;
    }
    curSize++;
}

void Deque::pushBack(int i) {
    //=> add an item to the right end
    if(tail == nullptr){
        head = tail = new Node(i);
    }else{
        tail->right = new Node(i, tail, nullptr);
        tail = tail->right;
    }
    curSize++;
}

int Deque::popFront() {
    //=> remove and return an item from the left end
    if(head == nullptr){
        head = tail = nullptr;
        return - 1;
    }else if(head == tail){
        Node* tmp = head;
        head = tail = nullptr;
        curSize--;
        int value = tmp->value;
        delete 
        return value;
    }else{
        Node* tmp = head;
        head = head->right;
        head->left = nullptr;
        curSize--;
        return tmp->value;
    }
}

int Deque::popBack() {
    //=> remove and return an item from the right end
    if(tail == nullptr){
        head = tail = nullptr;
        return - 1;
    }else if(head == tail){
        Node* tmp = head;
        head = tail = nullptr;
        curSize--;
        return tmp->value;
    }else{
        Node* tmp = tail;
        tail = tail->left;
        tail->right = nullptr;
        curSize--;
        return tmp->value;
    }
}

void Deque::printQueueReverse() {
    //=> print all items in the deque from right to left, separated by a space, with a new line at the end.
    
    Node* tmp = tail;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->left;
    }
    cout << endl;
}

void Deque::printQueue() {
    // print all items in the deque from left to right, separated by a space, with a new line (i.e '\n') at the end.
    Node* tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->right;
    }
    cout << endl;
}
        curSize++;
    }
    
    void pushBack(int item) {
        Node* newNode = new Node(item, tail, nullptr);
        if (tail != nullptr)
            tail->right = newNode;
        tail = newNode;
        if (head == nullptr)
            head = tail;
        curSize++;
    }
    
    int popFront() {
        if (head == nullptr)
            return -1;
        Node* nodeToRemove = head;
        int value = nodeToRemove->value;
        head = head->right;
        if (head != nullptr)
            head->left = nullptr;
        else
            tail = nullptr;
        delete nodeToRemove;
        curSize--;
        return value;
    }
    
    int popBack() {
        if (tail == nullptr)
            return -1;
        Node* nodeToRemove = tail;
        int value = nodeToRemove->value;
        tail = tail->left;
        if (tail != nullptr)
            tail->right = nullptr;
        else
            head = nullptr;
        delete nodeToRemove;
        curSize--;
        return value;
    }
    
    void clear() {
        while (head != nullptr) {
            Node* nodeToRemove = head;
            head = head->right;
            delete nodeToRemove;
        }
        tail = nullptr;
        curSize = 0;
    }
    
    void printDeque() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->right;
        }
        cout << endl;
    }
    
    void printDequeReverse() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->left;
        }
        cout << endl;
    }
};
