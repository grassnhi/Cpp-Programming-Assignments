#include<iostream>

using namespace std;

class DLinkedList{
public:
    class Table
    {
    private:
        int ID; // ID bàn
        int name; // tên khách == result
        int NUM; // số lần gọi món
        Table* next;
        Table* prev; // new pointer added for double linked list
        friend class DLinkedList;
    public:
        Table(){
            this->next = next;
            this->prev = prev;
        }
        
        Table(int ID, int name, int NUM = 0, Table* next = nullptr, Table* prev = nullptr)
        {
            this->ID = ID;
            this->name = name;
            this->NUM = NUM;
            this->next = next;
            this->prev = prev;
        }
    };
protected:
    int count;
    Table* head;
    Table* tail;
    
public:
    DLinkedList(int count = 0, Table* head = nullptr, Table* tail = nullptr){
        this->count = count;
        this->head = head;
        this->tail = tail;
    }
    ~DLinkedList(){
        clear();
    }

    void    add(int ID, int name, int NUM = 0){
        Table* node = new Table(ID, name, NUM);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        count++;
    }

    int     size(){
        return count;
    }

    bool    empty(){
        return count == 0;
    }

    void    set(int index, int e);

    bool    contains(int item){
        Table* tmp = head;
        int i = 0;
        while (tmp != nullptr) {
            if (tmp->name == item) {
                return true;
            }
            tmp = tmp->next;
            i++;
        }
        return false;
    }

    void    removeAt(int index){
        if(index < 1 || index > count || head == nullptr){
            return;
        }else if(index == 1){
            if(head == tail){
                head = tail = nullptr;
                count--;
            }
            head = head->next;
            head->prev = nullptr;
            count--;
        }else if(index == count){
            tail = tail->prev;
            tail->next = nullptr;
            count--;
        }else{
            if(index < count /2){
                Table* tmp = head;
                Table* prev = nullptr;
                for(int i = 0; i < index; i++){
                    prev = tmp;
                    tmp = tmp->next;
                }
                prev->next = tmp->next;
                tmp = tmp->next;
                tmp->prev = prev;
            }else{
                Table* tmp = tail;
                Table* follow = nullptr;
                for(int i = count - 1; i > index; i--){
                    follow = tmp;
                    tmp = tmp->prev;
                }
                follow->prev = tmp->prev;
                tmp = tmp->prev;
                tmp->next = follow;
            }
            count--;
        }
    }

    void    clear(){
        Table* tmp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        tail = nullptr;
        count = 0;
    }
};

int main(){
    DLinkedList* list;
    list->add(1, 01);
    list->clear();
    
}