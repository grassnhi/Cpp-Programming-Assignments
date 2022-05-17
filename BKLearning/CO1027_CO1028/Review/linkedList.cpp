#include<iostream>

using namespace std;

/*
    - Bugs still exist in: insertNode, addHead, addTail.

    - Problem between list and newList. Print list but output is newList.

    - 

*/

struct node
{
    int data;
    node *next;
    node(int data, node *next = nullptr){
        this->data = data;
        this->next = next;
    }
};

node *createList(int mode, int n){
    int data = 0;
    int count = 0;

    node *head = nullptr;
    node *tail = nullptr;
    if(mode == 1){
        while(count != n){
            cin >> data;
            count++;

            if(head == nullptr){
                head = new node(data);
            }else{
                head = new node(data, head);
            }
        }

        return head;
    }else{
        while (count != n)
        {
            cin >> data;
            count++;

            if(head == nullptr){
                head = tail = new node(data);
            }else{
                tail->next = new node(data);
                tail = tail->next;
            }

        }
        return head;

    }
}

int countNode(node *head){
    int count = 0;
    node *counter = head;

    while (counter != nullptr)
    {
        count++;
        counter = counter->next;
    }
    
    return count;
}

bool isEmpty(node *head){
    return (head == nullptr)?true:false;
}

node *insertNode(node *head, node *newNode, int position){ //
    if(position <= 0 || position > countNode(head) + 1){
        cout << "Out of range!" << endl;
    }else if(isEmpty(head)){ 
        head = newNode;
    }else if(position == 1){
        node *curr = head;
        newNode->next = curr;
        head = newNode;
    }else{
        int count = 1;
        node *curr = head;
        while (count != position - 1)
        {
            count++;
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return head;
}

void addHead(node *head, int data){ //
    if(isEmpty(head)){
        head = new node(data);
    }else{
        head = new node(data, head);
    }
    // return head;
}

void addTail(node *head, int data){ //
    if(isEmpty(head)){
        head = new node(data);
    }else{
        node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = new node(data);
        tail = tail->next;
    }
    //return head;
}

void replaceNode(node* head, int position, int data){
    if(position <= 0 || position > countNode(head) + 1){
        cout << "Out of range!" << endl;
    }else{
        node *curr = head;
        int count = 1;
        while (count != position)
        {
            count++;
            curr = curr->next;
        }
        curr->data = data;
    }
    
}

int searchNode(node* head, int key){ 
    int index = 0;
    node* curr = head;
    while(curr != nullptr){
        if(curr -> data == key){
            return index;
        }
        else{
            curr = curr -> next;
            index++;
        }
    }

    return -1;
}

void deleteNode(node *head, int position){
    node *curr = head;
    if(position <= 0 || position > countNode(head) + 1){
        cout << "Out of range!" << endl;
    }else if(countNode(head) == 0){
        return;
    }else{
        int count = 1;
        node *temp = nullptr;
        while (count != position)
        {
            count++;
            temp = curr;
            curr = curr->next;
        }
        temp->next = curr->next;
        delete curr;
    }
}

void clearList(node *head){
    node* curr = head;
    while(curr != nullptr){
        head = head->next;
        delete curr;
        curr = head;
    }
}

void print(node *head){
    node *curr = head;
    while(curr != nullptr){
        cout << curr->data << "  ";
        curr = curr->next;
    }
}

int main(){
    int mode;
    cin >> mode;

    int n = 0;
    cin >> n;

    if(n > 0 && (mode == 1 || mode ==2)){
        node *list = createList(mode, n);
        print(list);
        cout << endl;

        cout << countNode(list) << endl;
        cout << isEmpty(list) << endl;

        int key;
        cin >> key;
        int getIndex = searchNode(list, key);
        cout << getIndex << endl;

        // clearList(list);
        // print(list);

        int data;
        cin >> data;
        node *newNode = new node(data);

        int position = 0;
        cin >> position;

        node *newList = insertNode(list, newNode, position);
        // list = insert(list, newNode, position);
        print(newList);
        cout << endl;

        // deleteNode(list, 1);
        // print(list);
        // deleteNode(newList, 1);
        // print(newList);

        //newList = addHead(newList, 100); 
        addHead(newList, 100);
        print(newList);
        cout << endl;

        addTail(newList, 100);
        print(newList);
        cout << endl;

        cin >> position >> data;
        replaceNode(list, position, data); 
        print(list);
        cout << endl;

        // deleteNode(list, 1);
        // print(list);
        

    }else{
        cout << "Invalid!" <<endl;
    }



    return 0;
}