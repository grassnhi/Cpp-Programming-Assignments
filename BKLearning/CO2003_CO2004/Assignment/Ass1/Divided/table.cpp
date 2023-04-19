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

class queue{
    public:
        int count = 0;
        restaurant* aQueue;

        queue(){
            aQueue = new restaurant();
            count = 0;
        }

        ~queue(){
            clear();
            delete aQueue;
            count = 0;
        }

        void clear(){
            if (aQueue != nullptr && aQueue->recentTable != nullptr) {
                table* curr = aQueue->recentTable;
                table* prev = nullptr;

                while (curr->next != aQueue->recentTable) {
                    prev = curr;
                    curr = curr->next;
                    delete prev;
                }

                delete curr;
                aQueue->recentTable = nullptr;
            }
            
            aQueue = nullptr;
            count = 0;
        }
};

void reverseTable(restaurant* r){
    if (r == nullptr || r->recentTable->next == r->recentTable) {
        return;
    }
    table* last = r->recentTable;
    table* curr = r->recentTable->next;
    table* foll = curr->next;

    while (curr != r->recentTable)
    {
        curr->next = last;
        last = curr;
        curr = foll;
        foll = foll->next;
    }
    curr->next = last;
    last = curr->next;
    r->recentTable = curr;
    //delete last;
    //delete curr;
    //delete foll;
}


int main(){
    restaurant* r = new restaurant();

    queue* line = new queue();

    restaurant* history = new restaurant();

    table* fifo = line->aQueue->recentTable;


    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable,i,"n",0);
    }

    restaurant* last = r;
    table* curr= r->recentTable->next;

    int ID = 0;
    string name = "John";
    int age = 35;


    if(age < 16){
        throw out_of_range("Age less than 16.");
    }


    if(ID >0 && ID <= MAXSIZE){
        while(curr->ID != ID){
            curr = curr->next;
        }

        while (curr->name != "" || curr != last->recentTable)
        {
            curr = curr->next;
        }

        if(curr->name == ""){
            curr->name = name;
            curr->age = age;   
            history->recentTable = history->insert(history->recentTable, ID, name, age);  
        }else{
            if(line->aQueue->recentTable == nullptr){
                line->aQueue->recentTable = line->aQueue->insert(line->aQueue->recentTable, ID, name, age);
                line->count++;
            }else if(line->count < MAXSIZE){
                line->aQueue->recentTable = line->aQueue->insert(line->aQueue->recentTable, ID, name, age);
                fifo = line->aQueue->recentTable->next;
                line->count++;
            }else{
                throw out_of_range("Full queue!");
            }
            
        }
    }else if(ID == 0){
        while (curr->name != "" || curr == last->recentTable->next)
        {
            curr = curr->next;
        }

        if(curr->name == "" ){
            curr->name = name;
            curr->age = age;
        }else{
            if(line->aQueue->recentTable == nullptr){
                line->aQueue->recentTable = line->aQueue->insert(line->aQueue->recentTable, ID, name, age);
                line->count++;
            }else if(line->count < MAXSIZE){
                line->aQueue->recentTable = line->aQueue->insert(line->aQueue->recentTable, ID, name, age);
                fifo = line->aQueue->recentTable->next;
                line->count++;
            }else{
                throw out_of_range("Full queue!");
            }
        }
    }

    cout << "RESTAURANT:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        last->print();
        last->recentTable = last->recentTable->next;
    }

    cout << "RESTAURANT:" << endl;
    for (int i = 1; i <= line->count; i++)
    {
        line->aQueue->print();
        line->aQueue->recentTable = line->aQueue->recentTable->next;
    }
    
}
