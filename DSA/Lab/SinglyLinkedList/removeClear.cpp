/*
Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) 
representing the singly linked list with type T with the initialized frame. 
The description of each method is given in the code.

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
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
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
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

*/
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count || head == nullptr) {
        return -1;
    }
    if(index == 0){
        int e = head->data;
        if(head == tail){
            Node* tmp = head;
            head = tail = nullptr;
            delete tmp;
        }else{
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        count--;
        return e;
    }else if(index == count - 1){
        int e = tail->data;
        Node* tmp = head;
        for(int i = 0; i < index - 1; i++){
            tmp = tmp->next;
        }
        tail = tmp;
        tmp = tmp->next;
        tail->next = nullptr;
        delete tmp;
        count--;
        return e;
    }else{
        Node* tmp = head;
        Node* prev = tmp;
        for(int i = 0; i < index; i++){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        int e = tmp->data;
        delete tmp;
        count--;
        return e;
    }  
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* tmp = head;
    for(int i = 0; i < count; i++){
        if(tmp->data == item){
            removeAt(i);
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while(head != nullptr){
        Node* prev = head;
        head = head->next;
        delete prev;
    }
    tail = nullptr;
    count = 0;
}

/*
SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(0) == list.removeAt(0));

    cout << list.toString();
[1,2,3,4,5,6,7,8,9]
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));

    cout << list.toString();
[0,1,2,3,4,5,6,7,8]
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.removeItem(9));

    cout << list.toString();
*/