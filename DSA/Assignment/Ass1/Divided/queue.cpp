#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std;
#define MAXSIZE 15

class table
{
public:
    int ID;
    string name;
    int age;
    table* next;
    table(int ID, string name, int age, table* next)
    {
        this->ID = ID;
        this->name = name;
        this->age = age;
        this->next = next;
    }
};

class restaurant
{
public:
    table *recentTable;
    restaurant()
    {
        recentTable = nullptr;
    }
    ~restaurant()
    {
        delete recentTable;
    }
    table* finsert(table *last, int ID, string name, int age)
    {   // adds a new table to the list when the list is empty or has only one element
        if (last != nullptr)
            return last;
        table *temp = new table(ID, "", age, last);

        last = temp;
        last->next = last;
        return last;
    }
    table *insert(table *last, int ID, string name, int age)
    {   // adds a new table to the list if it's not empty.
        if (last == NULL)
            return finsert(last, ID, name, age);
        table *temp = new table (ID, name, age, last->next);
        last -> next = temp;
        last = temp;
        return last;
    }
    void print(){
        cout << recentTable->ID << " " << recentTable->name << " " << recentTable->age << endl;
    }
};

class list{  // list->table
    public:
        int count = 0;
        table *recentTable;

        list(){
            recentTable = nullptr;
        }

        ~list(){
            delete recentTable;
        }

        table* finsert(table *last, int ID, string name, int age)
        {   // adds a new table to the list when the list is empty or has only one element
            if (last != nullptr)
                return last;
            table *temp = new table(ID, name, age, last);

            last = temp;
            last->next = last;

            count++;
            return last;
        }

        table *insert(table *last, int ID, string name, int age) // to tail
        {   // adds a new table to the list if it's not empty.
            if (last == NULL)
                return finsert(last, ID, name, age);
            table *temp = new table (ID, name, age, last->next);
            last -> next = temp;
            last = temp;
            count++;
            return last;
        }

        void print(){
            cout << recentTable->ID << " " << recentTable->name << " " << recentTable->age << endl;
        }

        void clear(){
            if (recentTable != nullptr) {
                table* curr = recentTable;
                table* prev = recentTable;

                while (curr->next != recentTable) {
                    prev = curr;
                    curr = curr->next;
                    delete prev;
                }

                delete curr;
                recentTable = nullptr;
            }
            count = 0;
        }

        void reverseTable() {
            if (recentTable == nullptr || recentTable->next == recentTable) {
                return;
            }

            table* last = recentTable;
            table* curr = recentTable->next;
            table* foll = curr->next;

            while (curr != recentTable) {
                curr->next = last;
                last = curr;
                curr = foll;
                foll = foll->next;
            }
            curr->next = last;
            recentTable->next = last; //previous beginning node connects with new beginning node  
            recentTable = last; //new start of the list
        }


        table* removeTable(table *last){ //from head
            if(last == nullptr || last->next == last){
                last = nullptr;
                count = 0;
            }else{
                last->next = last->next->next;
                count--;
            }
            return last;
        }

        void swapTable(table* curr, table* elder){
            int id = curr->ID;
            curr->ID = elder->ID;
            elder->ID = id;

            string name = curr->name;
            curr->name = elder->name;
            elder->name = name;

            int age = curr->age;
            curr->age = elder->age;
            elder->age = age;
        }

        void selectionSort(int NUM){
            table* curr = recentTable->next;  // head of list -> ra
            table* elder = curr;
            for (int i = 1; i <= NUM; i++){
                table* tmp = curr;
                for (int j = i + 1; j <= count; j++){
                    if(tmp->age == elder->age && tmp->ID > elder->ID){
                        elder = tmp;
                    }
                    if(tmp->age > elder->age){
                        elder = tmp;
                    }
                    tmp = tmp->next;
                }            
                swapTable(curr, elder);
                curr = curr->next;
                elder = curr;
            }
        }

        
};


int main(){
    list* queue = new list();
    list* store = new list();
    queue->recentTable = queue->insert(queue->recentTable,7,"n",80); // 7
    queue->recentTable = queue->insert(queue->recentTable,2,"nh",70); //2

    cout << "Original:" << endl;
    for (int i = 1; i <= 2; i++)
    {
        queue->print();
        queue->recentTable = queue->recentTable->next;
    }

    queue->reverseTable();

    cout << "Reverse:" << endl;
    for (int i = 1; i <= 2; i++)
    {
        queue->print();
        queue->recentTable = queue->recentTable->next;
    }

    queue->reverseTable();

    cout << "Reverse again:" << endl;
    for (int i = 1; i <= 2; i++)
    {
        queue->print();
        queue->recentTable = queue->recentTable->next;
    }

}

