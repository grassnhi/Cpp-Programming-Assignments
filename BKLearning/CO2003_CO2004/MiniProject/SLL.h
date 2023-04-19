#include<iostream>

#include "IList.h"

using namespace std;

template <class T>
class SLL: public IList<T>{
    public:
        class Node{
            private:
                T data;
                Node* next;
                friend class SLL<T>;
            public:
                Node(){
                    this->data = 0;
                    this->next = nullptr;
                }
                Node(T data, Node* next = nullptr){
                    this->data = data;
                    this->next = next;
                }
        };
    protected:
        Node* head;
        Node* tail;
        int count;
    public:
        SLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->count = 0;
        }
        ~SLL(){
            head = tail = nullptr;
            count = 0;
        }

        void    add(T e){
            // add(T e): append item "e" to the list
            if(head == nullptr){
                head = tail = new Node(e, nullptr);
            }else{
                tail->next = new Node(e, nullptr);
                tail = tail->next;
            }
            count++;
        }

        void    add(int index, T e){
            if(index < 0 || index >= count || head == nullptr){
                throw out_of_range("Out of range");
            }else if(index == 0){
                head = tail = new Node(e, nullptr);
                // add(e);
            }else if(index == count - 1){
                tail->next = new Node(e, nullptr);
                tail = tail->next;
                // add(e);
            }else{
                Node* tmp = head;
                Node* prev = nullptr;
                for(int i = 0; i < index; i++){
                    while(tmp->data != e){
                        prev = tmp;
                        tmp = tmp->next;
                    }
                    prev->next = new Node(e, tmp);
                    delete tmp;
                }
            }
            count++;
        }

        // T       removeAt(int index){
        //     if(index < 0 || index >= count || head == nullptr){
        //         throw out_of_range("Out of range");
        //     }else if(index == 0){
        //         head = head->next; 
        //     }else if(index == count - 1){
        //         Node* tmp = head;
        //         while(tmp->next != tail){
        //             tmp = tmp->next;
        //         }
        //         tail = tmp;
        //         tail->next = nullptr;
        //         delete tmp;
        //     }else{
        //         Node* tmp = head;
        //         Node* prev = nullptr;
        //         for(int i = 0; i < index; i++){
        //             prev = tmp;
        //             tmp = tmp->next;
        //         }
        //         prev->next = tmp->next;
        //         delete prev;
        //         delete tmp;
        //     }
        //     count--;
        // }

        // bool    removeItem(T item, void (*removeItemData)){
        //     // hỏng biết là ktlt có học rồi luôn :v 
        //     return false;
        // } 

        bool    removeItem(T item){
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

        bool    empty(){
            return count == 0;
        }

        int     size(){
            return count;
        }

        void    clear(){
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

        T&       get(int index){
            if(index < 0 || index >= count || head == nullptr){
                throw out_of_range("Out of range");
            }else{
                Node* tmp = head;
                for(int i = 0; i < index; i++){
                    tmp = tmp->next;
                }
                return tmp->data;
            }
        } 

        /* indexOf(T item): return the index of item
        *      if item is not found, then return -1
        */
        int     indexOf(T item){
            if(head == nullptr){
                return -1;
            }else if(head->data == item){
                return 0;
            }else if(tail->data == item){
                return count - 1;
            }else{
                Node* tmp = head;
                for(int i = 0; i < count - 1; i++){
                    if(tmp->data == item){
                        return i;
                    }else{
                        tmp = tmp->next;
                    }
                }
            }
            return - 1;
        }

        bool    contains(T item){
            return indexOf(item) == - 1;
        }
};

/*
argument:
- int a: -> copy đem đi use -> xong -> copy result và trả về bản copy đó
- int& a: -> use trực tiếp -> change a inside => outside change
- const int& a: use trực tiếp => ngăn change value
*/