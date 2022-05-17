#include <iostream>

using namespace std;

template <typename T>
class Stack;
template <typename T>
class Queue;
template <typename T>
class List{
public:
    class Node;
private:
    Node* head;
    Node* tail;
    int count;
public:
    class Node{
    private:
        T value;
        Node* next;
        friend class List<T>;
        friend class Stack<T>;
        friend class Queue<T>;
    public:
        Node(T value, Node* next = nullptr){
            this->value = value;
            this->next = next;
        }
    };
    List(): head(nullptr), tail(nullptr), count(0){};
    ~List(){
        Node* temp = head;
        while(head != tail){
            head = head->next;
            delete temp;
            temp = head;
        }
        temp = head;
        head = tail = nullptr;
        delete temp;
        delete head;
        delete tail;
    }

    void addHead(T value);
    void addTail(T value);
    void insert(T value, int pos);
    void deleteNode(int pos);
    void swapNode(int index1, int index2);

    virtual T getValue(int pos) const; // return data
    virtual int size() const; //return size
    virtual bool empty() const; // check empty
    virtual void showList() const; // print list, stack, queue
    virtual void clear();
};

template <typename T>
void List<T>:: addHead(T value){
    if(empty()){
        this->head = this->tail = new Node(value);
    }
    else{
        this->head = new Node(value, this->head);
    }
    this->count++;
}
template <typename T>
void List<T>:: addTail(T value){
    if(empty()){this->head = this->tail = new Node(value);}
    else{
        this->tail->next = new Node(value);
        this->tail = this->tail->next;
    }
    this->count++;
}
template <typename T>
void List<T>:: insert(T value, int pos){
    if(pos > this->count) throw 0;
    if(pos == 0){this->addHead(value); this->count++; return;}
    if(pos == this->count){this->addTail(value); this->count++; return;}
    int cnt = 0;
    Node* temp = head;
    Node* pre_temp = temp;
    while(cnt != pos){
        cnt++;
        pre_temp = temp;
        temp = temp->next;
    }
    pre_temp->next = new Node(value, temp);
    this->count++;
}
template <typename T>
void List<T>::deleteNode(int pos) {
    if(pos >= this->count || empty()) throw 0;
    if(pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else if(pos == this->count - 1){
        Node* temp = head;
        Node* dlt_node = tail;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        delete dlt_node;
    }
    else{
        int cnt = 0;
        Node* temp = head;
        Node* prev_temp = temp;
        while(cnt != pos){
            prev_temp = temp;
            temp = temp->next;
            cnt++;
        }
        prev_temp->next = temp->next;
        delete temp;
    }
    this->count--;
}
template <typename T>
T List<T>::getValue(int pos) const {
    if(pos >= this->count) throw 0; // out of size
    Node* temp = head;
    int cnt = 0;
    while(pos != cnt){
        temp = temp->next;
        cnt++;
    }
    return temp->value;
}
template<typename T>
int List<T>:: size() const{return this->count;}
template <typename T>
bool List<T>:: empty() const{ return (this->count  == 0)?true: false;}
template <typename T>
void List<T>:: showList() const{
    if(empty()){
        cout << "The list is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "end list" << endl;
}
template <typename T>
void List<T>:: clear(){
    cout << "Cleaning..." << endl;
    if(empty()){
        cout << "Done!!!" << endl;
        return;
    }
    Node* temp = head;
    while(head != tail){
        head = head->next;
        delete temp;
        temp = head;
    }
    head = tail = nullptr;
    delete temp;
    this->count = 0;
    cout << "Done!!!" << endl;
}
template <typename T>
void List<T>::swapNode(int index1, int index2) {
    if(index1 >= this->count || index2 >= this->count) throw (int) 0;
    if(index1 == index2)
    {
        return;
    }
    Node* prevX = nullptr;
    Node* currX = head;
    int i = 0;
    while(currX && i != index1)
    {
        prevX = currX;
        currX = currX->next;
        i++;
    }
    Node* prevY = nullptr;
    Node* currY = head;
    i = 0;
    while(currY && i != index2)
    {
        prevY = currY;
        currY = currY->next;
        i++;
    }

    // If x is not head of linked list
    if (prevX != nullptr)
        prevX->next = currY;
    else // Else make y as new head
        head = currY;

    if (prevY != nullptr)
        prevY->next = currX;
    else // Else make x as new head
        head = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
    if(index2 == count-1) tail = currX;
}



int main() {
    List<int> * l = new List<int>;
    try {
        l->addHead(1);
        l->addHead(0);
        l->addTail(5);
        l->addTail(6);
        l->showList();
        l->insert(3, 2);
        l->insert(2, 2);
        l->insert(4, 4);
        l->showList();
        l->addTail(7);
        l->addTail(8);
        l->addTail(9);
        l->showList();
        cout << "Size of list: " << l->size() << endl;
        l->deleteNode(9);
        //l->showList();
        l->deleteNode(5);
        //l->showList();
        l->deleteNode(0);
        l->showList();
        l->clear();
        l->addTail(-1);
        l->addTail(3);
        l->addTail(8);
        l->addTail(8);
        l->showList();
        delete l;
    }
    catch(int a){
        if(a == 0) cout << "Out of range" << endl;
    }
    return 0;
}
