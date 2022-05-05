#include <iostream>

using namespace  std;

class Node{
public:
    int value;
    Node* next;
    Node(int data, Node* ptr = nullptr){
        this->value = data;
        this->next = ptr;
    };
};

class List{
    Node* head;
    Node* tail;
    int count;
public:
    List(){
        head = tail = nullptr;
        count = 0;
    }
    ~List(){clear();}
    bool empty() const{return(this->count == 0)?true:false;}
    void addHead(int value);
    void addTail(int value);
    void Insert(int value, int pos);
    void display()const;

    // Em code:
    void delete_pos(int pos);//xoa 1 node
    int getValue(int pos);
    int getSize();
    void clear();//clear linked list xoa het
};
void List:: clear(){
//    head = tail = nullptr;
    Node* temp = head;
    while(temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
    head = tail = nullptr;
}
int List:: getValue(int pos){
    // check xem cai linked list em có empty khum
    // check xem cái position có out of range khong em
    Node* temp=head;
    int index=1; // = 0 di em, index luon luon di tu 0 ma :v
    while (index!= pos){
        index++;
        temp = temp->next;
    }
    return temp->value;
}
void List:: delete_pos(int pos){
    if(empty())return;
    if(pos >= getSize())return;
    Node* temp = head;
    Node* prev_temp = nullptr;
    int index = 0;
    if(pos == 0){
        head = head->next;
        delete temp;
    }
    while(index != pos){
        index++;
        prev_temp = temp;
        temp = temp->next;
    }
    if(pos == getSize() - 1) tail = prev_temp;
    prev_temp->next = temp->next;
    delete temp;
    this->count--;
}
int List:: getSize(){
//    return this->count
//    if(empty()) return 0;
//    int index=0;
//    Node* temp=head;
//    while (temp != nullptr){
//        index++;
//        temp = temp->next;
//    }
//    return index;
}

void List:: addHead(int value){
    if(empty()){
        head = tail = new Node(value);
    }else{
        head = new Node(value, head);

//        Node* temp = new Node(value, head);
//        head = temp;
    }
    this->count++;
}


void List:: addTail(int value){
    if(empty()){
        head = tail = new Node(value);
    }else{
        tail->next = new Node(value);
        tail = tail->next;
    }
    this->count++;
}


void List:: Insert(int value, int pos){
    if(pos > this->count){
        cout << "out of range" << endl;
        return;
    }
    if(empty()){
        head = tail = new Node(value);
    }else if(pos == 0){this->addHead(value);}
    else{
        Node* temp = head;
        Node* prev_temp = nullptr;
        int index = 0;
        while(index != pos){
            index++;
            prev_temp = temp;
            temp = temp->next;
        }
//        if(prev_temp = nullptr){
//            this->head = new Node(value, head);
//        }
        prev_temp->next = new Node(value, temp);
    }
    this->count++;
}


void List:: display() const{
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout <<"end list" << endl;
}

int main() {
    List* l = new List();
    l->addHead(1);
    l->addHead(0);
    l->display();
    l->addTail(4);
    l->addTail(5);
    l->display();
    l->Insert(2,2);
    l->Insert(3,3);
    l->display();
    l->Insert(9, 9);
    // int size = l->getSize();
    // cout<<size<<endl;
    // int gtri = l->getValue(3);
    // cout<<gtri;
    l->display();
    l->delete_pos(3);
    l->display();
    delete l;
    return 0;
}