#include<iostream>
#include<math.h>

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node* next;
    Node(T data){
        this->data = data;
        next = nullptr;
    }

};

template<class T>
class SLL{
private:
    Node<T>* head;
public:
    SLL(){
        head = nullptr;
    }
    void insertLast(T data){   
        if(head == nullptr){
            head = new Node<T>(data);
        }else{
            Node<T>* tmp = head;
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }
            // Node<T>* last = new Node<T>(data);
            // tmp->next = last;
            tmp->next = new Node<T>(data);
        }
    }

    void deleteNode(T data){
        if(head == nullptr){
            return;
        }else if(head->data == data){
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }else{
            Node<T>* tmp = head;
            while(tmp->next->data != data){
                tmp = tmp->next;
            }
            Node<T>* curr = tmp;
            tmp = tmp->next;
            curr->next = tmp->next;
            delete tmp;
        }
    }

    void print(){
        Node<T>* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }


};

int main(){
    SLL<int>* sll0 = new SLL<int>();
    SLL<int>* sll1 = new SLL<int>();
    sll0->insertLast(2);
    sll0->insertLast(9);
    sll1->insertLast(0);
    sll1->insertLast(5);
    sll0->print();
    sll1->print();
    
    add2SLL(sll0, sll1);
    
}