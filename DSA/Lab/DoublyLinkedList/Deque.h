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
            tail = head;
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
