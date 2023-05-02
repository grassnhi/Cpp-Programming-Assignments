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

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= this->count) 
        throw std::out_of_range("Invalid Index!");
    Node* temp = this->head;
    for (int i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= this->count) 
        throw std::out_of_range("Invalid Index!");
    Node* temp = this->head;
    for (int i = 0; i < index; i++) temp = temp->next;
    temp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (this->count == 0);
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* temp = this->head;
    int i = 0;
    while (temp != NULL) {
        if (temp->data == item)
            return i;
        temp = temp->next;
        ++i;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return (this->indexOf(item) != -1);
}

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* pNew = new Node(e);
    if (this->head == NULL) {
        this->head = this->tail = pNew;
    }
    else {
        this->tail->next = pNew;
        pNew->previous = this->tail;
        this->tail = pNew;
    }
    ++this->count;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if (index > this->count || index < 0) {
		throw ("out of range");
		return;
	}
		
	if (index == this->count && this->count != 0) {
		add(e);
		return;
	}
	
	Node* pNew = new Node(e);
	if (this->count == 0) 
        this->head = this->tail = pNew;
    else if (index == 0) {
        pNew->next = this->head;
        this->head->previous = pNew;
        this->head = pNew;
    }
    else {
        Node* prev = this->head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;
        Node* cur = prev->next;
        pNew->next = prev->next;
        cur->previous = pNew;
        pNew->previous = prev;
        prev->next = pNew;
    }
    ++this->count;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= this->count)
        throw std::out_of_range("The index is out of range!");
    T dataDel;
    Node* temp = this->head;
    if (this->count == 1) {
        dataDel = this->head->data;
        delete this->head;
        this->head = this->tail = NULL;
    }
    else if (index == 0) {
        dataDel = temp->data;
        this->head = temp->next;
        delete temp;
        temp = this->head;
        this->head->previous = NULL;
    }
    else if (index == this->count - 1) {
        while (temp->next->next != NULL) temp = temp->next;
        dataDel = this->tail->data;
        delete this->tail;
        this->tail = temp;
        temp->next = NULL;
    }
    else {
        for (int i = 0; i < index; i++) temp = temp->next;
        dataDel = temp->data;
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        delete temp;
        temp = NULL;
    }
    --this->count;
    return dataDel;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = this->indexOf(item);
    if (index != -1) {
        this->removeAt(index);
        return true;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->count != 0) this->removeAt(0);
}