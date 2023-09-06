/*
A double-ended queue or deque (pronounced "deck") is like a queue or a stack but supports adding and removing items at both ends.
A deque stores a collection of items and supports the following methods:
+ getSize(): int                   => number of items in the deque
+ pushFront(int item): void      => add an item to the left end   
+ pushBack(int item): void     => add an item to the right end
+ popFront(): int                => remove and return an item from the left end
+ popBack(): int               => remove and return an item from the right end
+ clear(): void                 => erase all items in the deque

// For checking purposes
+ printDeque(): void            => print all items in the deque from left to right, separated by a space, with a new line (i.e '\n') at the end.
+ printDequeReverse(): void     => print all items in the deque from right to left, separated by a space, with a new line at the end.
Note: if the deque is empty, every pop method return -1;

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

*/

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
    while(head != nullptr){
        Node* tmp = head;
        head = head->right;
        delete tmp;
    }
    tail = nullptr;
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
        return -1;
    }
    Node* tmp = head;
    int val = head->value;
    if(head == tail){
        head = tail = nullptr;
    }else{
        head = head->right;
        head->left = nullptr;
    }
    delete tmp;
    curSize--;
    return val;
}

int Deque::popBack() {
    //=> remove and return an item from the right end
    if(tail == nullptr){
        head = tail = nullptr;
        return - 1;
    }
    Node* tmp = tail;
    int val = tail->value;
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->left;
        tail->right = nullptr;
    }
    delete tmp;
    curSize--;
    return val;
}

void Deque::printDequeReverse() {
    Node* tmp = tail;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->left;
    }
    cout << endl;
}

void Deque::printDeque() {
    Node* tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->right;
    }
    cout << endl;
}


/*
Test	Result
    Deque* deque = new Deque();
    vector<int> arr = {223, 1234, 43, 568, 90, 193, 2109};
    for(int i = 0; i < (int)arr.size(); i++) {
        if (i < (int)arr.size() / 2)
            deque->pushFront(arr[i]);
        else {
            deque->pushBack(arr[i]);
        }
    }
    deque->printDeque();
    cout << deque->getSize();
    delete deque;
43 1234 223 568 90 193 2109 
7
    Deque* deque = new Deque();
    int size = 20;
    for(int i = 0; i < size; i++) {
        deque->pushBack(i);
    }
    for(int i = 0; i < size / 2; i++) {
        if (i % 2 == 0)
            deque->popBack();
        else 
            deque->popFront();
    }
    deque->printDequeReverse();
    cout << deque->getSize();
    delete deque;
14 13 12 11 10 9 8 7 6 5 
10
*/

