#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

class List
{
private:
    Node *head;
    Node *tail;
    int number;
public:
    List(){
        head = tail = nullptr;
        count = 0;
    }
    ~List(){
        clearList();
    }

    void createList(int mode, int n){
        int data = 0;
        this->number = 0;

        if(n > 0 && (mode == 1 || mode ==2)){ //new to head
            if(mode == 1){
                while(this->number != n){
                    cin >> data;
                    this->number++;

                    if(head == nullptr){
                        head = tail = new Node(data);
                    }else{
                        head = new Node(data, head);
                    }
                }
            }else{ // new to tail
                while (this->number != n)
                {
                    cin >> data;
                    this->number++;

                    if(head == nullptr){
                        head = tail = new Node(data);
                    }else{
                        tail->next = new Node(data);
                        tail = tail->next;
                    }

                }
            }
        }else{
            cout << "Invalid!" << endl;
        }
        
    }

    int getData(int position){
        if(position <= 0 || position > this->number || this->number == 0){
            return -1;
        }else{
            Node* curr = head;
            int index = 1;
            while (index != position)
            {
                index++;
                curr = curr->next;
            }
            return curr->data;
        }
    }

    void replaceData(int position, int data){
        if(position <= 0 || position > this->number){
            cout << "Out of range!" << endl;
        }else{
            Node *curr = head;
            int count = 1;
            while (count != position)
            {
                count++;
                curr = curr->next;
            }
            curr->data = data;
        }
    }

    int searchData(int key){ 
        int index = 0;
        Node* curr = head;
        while(curr != nullptr){
            if(curr->data == key){
                return index;
            }
            else{
                curr = curr -> next;
                index++;
            }
        }
        return -1;
    }

    void deleteNode(int position){
        if(position <= 0 || position > this->number || this->number == 0){
            cout << "Out of range!" << endl;
        }else if(position == 1){
            Node *curr = head;
            head = curr->next;
            delete curr;
            this->number--;
        }else{
            int count = 1;
            Node *curr = head;
            Node *temp = nullptr;
            while (count != position)
            {
                count++;
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            delete curr;
            this->number--;
        }
    }

    void addHead(int data){ 
        if(this->number == 0){
            tail = head = new Node(data);
        }else{
            head = new Node(data, head);
        }
        this->number++;
    }

    void addTail(int data){
        if(this->number == 0){
            tail = head = new Node(data);
        }else{
            tail->next = new Node(data);
            tail = tail->next;
        }
        this->number++;
    }

    int countNode(){
        return this->number;
    }

    bool isEmpty(){
        return (this->number == 0)?true:false;
    }

    void print() const{
        Node *curr = head;
        while(curr != nullptr){
            cout << curr->data << "  ";
            curr = curr->next;
        }
    }    

    void clearList(){
        Node* curr = head;
        while(curr != nullptr){
            head = head->next;
            delete curr;
            curr = head;
        }
        head = tail = nullptr;
        cout << endl << "Cleared." << endl;
    }
};


int main(){
/*
    List list;

    int mode;
    cin >> mode;

    int n = 0;
    cin >> n;

    list.createList(mode, n);
    list.print();
    int count = list.countNode();
    cout << endl << count << endl;

    cout << "Is it empty? " << list.isEmpty() << endl;
    int found, position, data;
    cout << "Find the data of the node at the position: ";
    cin >> position;
    found = list.getData(position);
    cout << found << endl;

    cout << "The position of node needed to be replaced and the data: ";
    cin >> position >> data;
    list.replaceData(position, data);
    list.print();

    cout << "Search the data: ";
    cin >> data;
    cout << "Index of the node: " << list.searchData(data) << endl;

    cout << "Delete the node at the position: ";
    cin >> position;
    list.deleteNode(position);
    list.print();

    cout << "Add the first node with the data: ";
    cin >> data;
    list.addHead(data);
    list.print();
    cout << endl << "The number of node: " << list.countNode() << endl;

    cout << "Add the last node with the data: ";
    cin >> data;
    list.addTail(data);
    list.print();
    cout << endl << "The number of node: " << list.countNode();
*/


    List *newList = new List();

    int mode, n;
    cin >> mode >> n;
    newList->createList(mode, n);
    newList->print();
    cout << endl << "The number of node: " << newList->countNode() << endl;

    cout << "Is it empty? " << newList->isEmpty() << endl;
    int found, position, data;
    cout << "Find the data of the node at the position: ";
    cin >> position;
    found = newList->getData(position);
    cout << found << endl;

    cout << "The position of node needed to be replaced and the data: ";
    cin >> position >> data;
    newList->replaceData(position, data);
    newList->print();

    cout << "Search the data: ";
    cin >> data;
    cout << "Index of the node: " << newList->searchData(data) << endl;

    cout << "Delete the node at the position: ";
    cin >> position;
    newList->deleteNode(position);
    newList->print();

    cout << "Add the first node with the data: ";
    cin >> data;
    newList->addHead(data);
    newList->print();

    cout << "Add the last node with the data: ";
    cin >> data;
    newList->addTail(data);
    newList->print();
    newList->countNode();

    delete newList;

    return 0;
}