/*
Implement methods add, size in template class DLinkedList (which implements List ADT) representing the doubly linked list with type T with the initialized frame. The description of each method is given in the code.


template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};
In this exercise, we have include <iostream>, <string>, <sstream> and using namespace std.
*/



/*
Test	Result
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
   list.add(idx);
}
cout << list.toString();
[0,1,2,3,4,5,6,7,8,9]
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
   list.add(0, idx);
}
cout << list.toString();
[9,8,7,6,5,4,3,2,1,0]

*/