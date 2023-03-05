/*
Implement methods add, size in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

*/

template <class T>
SLinkedList<T>::SLinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
SLinkedList<T>::~SLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
void SLinkedList<T>::add(T e) {
    Node* newNode = new Node(e, nullptr);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, T e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Index out of range");
    }

    Node* newNode = new Node(e, nullptr);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }
    else if (index == count) {
        tail->next = newNode;
        tail = newNode;
    }
    else {
        Node* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    count++;
}

template <class T>
int SLinkedList<T>::size() {
    return count;
}

/*
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(index);
}

cout << list.toString();
[0,1,2,3,4,5,6,7,8,9]
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(0, index);
}

cout << list.toString();
*/

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if(tail == nullptr){
        head = tail = new Node(e, nullptr);
    }else{
        tail->next = new Node(e, nullptr);
        tail = tail->next;
    }
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count) {
        return;
    }
    if(tail == nullptr){
        head = tail = new Node(e, nullptr);
    }else{ 
        if(index == 0){
            head = new Node(e, head);
        }else if(index == count){
            tail->next = new Node(e, nullptr);
            tail = tail->next;
        }else{
            Node* tmp = head;
            for(int i = 0; i < index - 1; i++){
                tmp = tmp->next;
            }
            tmp->next = new Node(e, tmp->next);
        }
    }
    count++;
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
