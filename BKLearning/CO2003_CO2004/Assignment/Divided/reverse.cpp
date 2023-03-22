
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

void reverseTable(restaurant* r) {
    if (r->recentTable == nullptr || r->recentTable->next == r->recentTable) {
        return;
    }

    table* last = r->recentTable;
    table* curr = r->recentTable->next;
    table* foll = curr->next;

    while (curr != r->recentTable) {
        foll = curr->next;
        curr->next = last;
        last = curr;   
        curr = foll;
    }

    recentTable->next = nullptr; // set new tail to point at null
    recentTable = last; // update 
}

void testQueue(queue* line){
    

    cout << "Original:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->print();
        line->aQueue->recentTable = line->aQueue->recentTable->next;
    }

    reverseTable(line->aQueue);

    cout << "Reverse:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->print();
        line->aQueue->recentTable = line->aQueue->recentTable->next;
    }

    reverseTable(line->aQueue);

    cout << "Reverse again:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->print();
        line->aQueue->recentTable = line->aQueue->recentTable->next;
    }


}

void testRestaurant(restaurant* r){
    

    cout << "Original:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->print();
        r->recentTable = r->recentTable->next;
    }

    reverseTable(r);

    cout << "Reverse:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->print();
        r->recentTable = r->recentTable->next;
    }

    reverseTable(r);

    cout << "Reverse again:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->print();
        r->recentTable = r->recentTable->next;
    }

}

int main(int argc, char* argv[]) {
    queue* line = new queue();
    
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->recentTable = line->aQueue->insert(line->aQueue->recentTable, i, "nhii", 0);
        line->count++;
    }

    restaurant* r = new restaurant();
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable, i, "", 0);
    }

    restaurant* history = new restaurant();

    for (int i = 1; i <= MAXSIZE; i++)
    {
        history->recentTable = history->insert(history->recentTable, i*2, "n", 0);
    }

    int NUM = 10;

    //testQueue(line);
    testRestaurant(r);

}
