
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

int main(int argc, char* argv[]) {
    queue* line = new queue();

    //initialize table with ID, name and age
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->recentTable = line->aQueue->insert(r->recentTable, i, "", 0);
    }

    cout << "Original:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        line->aQueue->print();
        line->aQueue->recentTable = line->aQueue->recentTable->next;
    }

    delete line;

    return 0;
}
