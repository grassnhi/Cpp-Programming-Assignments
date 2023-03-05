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
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
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


template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* node = new Node(e);
    if(head == nullptr){
        head = tail = new Node(e);
    }else{
        tail->next = node;
        node->previous = tail;
        tail = tail->next;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if(index < 0 || index > count){
        throw out_of_range("Index out of range");
    }else if(head == nullptr){
        if(index == 0){
            head = tail = new Node(e);
            count++;
        }else{
            throw out_of_range("Index out of range");
        }
    } else if(index == 0){
        Node* node = new Node(e);
        head->previous = node;
        node->next = head;
        head = head->previous;
        count++;
    }else if(index == count){
        Node* node = new Node(e);
        tail->next = node;
        node->previous = tail;
        tail = tail->next;
        count++;
    }else{
        Node* node = new Node(e);
        if(index < count/2){
            Node* tmp = head;
            Node* prev = tmp;
            for(int i = 0; i < index; i++){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = node;
            node->next = tmp;
            tmp->previous = node;
            node->previous = prev;
        }else{
            Node* tmp = tail;
            Node* follow = tmp;
            for(int i = count - 1; i >= index; i--){
                follow = tmp;
                tmp = tmp->previous;
            }
            follow->previous = node;
            node->previous = tmp;
            tmp->next = node;
            node->next = follow;
        }
        count++;
    }
    
}


template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if(index < 0 || index > count || head == nullptr){
        throw out_of_range("Index out of range");
    }else{
        if(index < count/2){
            Node* tmp = head;
            for(int i = 0; i < index; i++){
                tmp = tmp->next;
            }
            return tmp->data;
        }else{
            Node* tmp = tail;
            for(int i = count - 1; i > index; i--){
                tmp = tmp->previous;
            }
            return tmp->data;
        }
    }
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if(index < 0 || index >= count || head == nullptr){
        throw out_of_range("Index out of range");
    }else{
        if(index < count/2){
            Node* tmp = head;
            for(int i = 0; i < index; i++){
                tmp = tmp->next;
            }
            tmp->data = e;
        }else{
            Node* tmp = tail;
            for(int i = count - 1; i > index; i--){
                tmp = tmp->previous;
            }
            tmp->data = e;
        }
    }
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* tmp = head;
    int i = 0;
    while (tmp != nullptr) {
        if (tmp->data == item) {
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    T value = 0;
    if(index < 0 || index >= count || head == nullptr){
        throw out_of_range("Index out of range.");
    }else if(index == 0){
        if(head == tail){
            value = head->data;
            head = tail = nullptr;
            count--;
            return value;
        }
        value = head->data;
        head = head->next;
        head->previous = nullptr;
        count--;
        return value;
    }else if(index == count - 1){
        value = tail->data;
        tail = tail->previous;
        tail->next = nullptr;
        count--;
        return value;
    }
    else{
        if(index < count /2){
            Node* tmp = head;
            Node* prev = nullptr;
            for(int i = 0; i < index; i++){
                prev = tmp;
                tmp = tmp->next;
            }
            value = tmp->data;
            prev->next = tmp->next;
            tmp = tmp->next;
            tmp->previous = prev;
        }else{
            Node* tmp = tail;
            Node* follow = nullptr;
            for(int i = count - 1; i > index; i--){
                follow = tmp;
                tmp = tmp->previous;
            }
            value = tmp->data;
            follow->previous = tmp->previous;
            tmp = tmp->previous;
            tmp->next = follow;
        }
        count--;
        return value;
    }
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if(head == nullptr){
        return false;
    }else{
        Node* tmp = head;
        for (int i = 0; i < count; i++) {
            if (tmp->data == item){
                removeAt(i);
                return true;
            }
            tmp = tmp->next;
        }
    }
    return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* tmp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
    tail = nullptr;
    count = 0;
}