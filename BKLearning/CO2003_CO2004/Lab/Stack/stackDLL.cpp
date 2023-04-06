/*
Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.


#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif


You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.

template <class T>
class DLinkedList 
{
public:
    class Node;     //forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};

*/

void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(0, item);
}

T pop() {
    // TODO: Remove an element on top of the stack
    if(list.empty()) return -1;
    return list.removeAt(0);
}

T top() {
    // TODO: Get value of the element on top of the stack
    if(list.empty()) return -1;
    return list.get(0);
}

bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return list.size();    
}

void clear() {
    // TODO: Clear all elements of the stack
    return list.clear();
}

/*
Test	Result
Stack<int> stack;
cout << stack.empty() << " " << stack.size();
1 0
Stack<int> stack;

int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);
    
assert(stack.top() == 12);
    
stack.pop();
stack.pop();
    
cout << stack.top();
8
*/