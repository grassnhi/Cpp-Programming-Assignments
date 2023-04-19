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
};

class queue{  // queue->table
    public:
        int count = 0;
        table *recentTable;

        queue(){
            recentTable = nullptr;
        }

        ~queue(){
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

        void reverseTable(){
            if (recentTable == nullptr || recentTable->next == recentTable) {
                return;
            }
            table* last = recentTable;
            table* curr = recentTable->next;
            table* foll = curr->next;

            while (curr != recentTable)
            {
                curr->next = last;
                last = curr;
                curr = foll;
                if(foll != nullptr){
                    foll = foll->next;
                }
                    
            }
            curr->next = last;
            last = curr->next;
            recentTable = curr;
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
};


int main(){
    queue* r = new queue();

    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable,i,"n",0);
    }

    
    
}

