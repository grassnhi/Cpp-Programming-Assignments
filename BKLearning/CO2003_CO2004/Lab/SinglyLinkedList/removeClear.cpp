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
        throw out_of_range("Index out of range");
    }else{
        Node* prev = head;
        Node* tmp = head;
        if(index == 0){
            head = head->next;
            count--;
            return prev->data;
        }else{
            for(int i = 0; i < index; i++){
                prev = tmp;
                tmp = tmp->next;
                if(i == count - 2)  tail = prev;
            }
            prev->next = tmp->next;
            count--;
            return tmp->data;
        }  
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if(tail == nullptr){
        return false;
    }else{
        if(head->data == item){
            head = head->next;
            count--;
            return true;
        }else if(tail->data == item){
            Node* tmp = head;
            while(tmp->next != tail){
                tmp = tmp->next;
            }
            tail = tmp;
            tail->next = nullptr;
            return true;
        }else{
            Node* tmp = head;
            Node* prev = nullptr;
            for(int i = 0; i < count; i++){
                if(tmp->data == item){
                    prev->next = tmp->next;
                    count--;
                    return true; 
                }else{
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
        }
        return false;
    }
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// need to check again
void    clear(){
            Node* prev = head;
            Node* curr = head;
            Node* tmp = curr->next;
            while(tmp != nullptr){
                curr = tmp;
                tmp = tmp->next;
                prev->next = tmp;
                delete curr;
            }
            delete prev;
            delete tmp;
            head = tail = nullptr;
        } // maybe some error still exits


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