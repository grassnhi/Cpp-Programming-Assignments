#include<iostream>

using namespace std;

class Table{
    public:
        int ID; // ID bàn

        Table* next;
        Table* prev; 
        
        friend class DLinkedList;
    public:
        Table(){
            this->next = next;
            this->prev = prev;
        }
        
        Table(int ID, Table* next = nullptr, Table* prev = nullptr)
        {
            this->ID = ID;
            this->next = next;
            this->prev = prev;
        }
    };
class DLinkedList{   
public:
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

    // chưa có gì thì insert cho có :>
    void insert(int ID){
        Table* node = new Table(ID);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        count++;
    }

    // có thì xóa add lại :> 
    void update(int ID){
        if(head == nullptr){
            head = tail = new Table(ID);
        }else{
            remove(ID);
            insert(ID);
        }
    }

    void removeAt(int index){
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

    // có ID thì xóa :>
    void remove(int ID){
        if(head == nullptr){
            return;
        }else{
            Table* tmp = head;
            for (int i = 0; i < count; i++) {
                if (tmp->ID == ID){
                    removeAt(i);
                    return;
                }
                tmp = tmp->next;
            }
        }
    }

    Table* getHead(){
        return this->head;
    }

    void clear(){
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

    int size(){
        return count;
    }

    bool empty(){
        return count == 0;
    }
};

int main(){
    DLinkedList* list = new DLinkedList();
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);
    list->insert(5);
    Table* tmp = list->head;
    if(list->head->ID == 1){
        cout << "10" << endl;
    }
}