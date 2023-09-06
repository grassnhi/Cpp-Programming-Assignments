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
            clear();
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

        void reverseTable(){ // reverse -> curr = last (id 15)
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

        table* removeTable(table *last){ //from head, the next of last
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
            table* curr = recentTable->next;  // head of queue -> ra
            table* elder = curr;
            for (int i = 1; i <= NUM; i++){
                table* tmp = curr;
                for (int j = i + 1; j <= count; j++){
                    if (tmp->age > elder->age){
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

void REG(int ID, string name, int age, restaurant* r, list* queue, list* history, list* merged);
void REGM(string name, int age, int NUM, restaurant* r, list* history, list* merged);
void CLE(int ID, restaurant* r, list* queue, list* history, list* merged);
void PS(int NUM, list* queue, list* history);
void PQ(int NUM, list* queue);
void PT(restaurant* r, list* history);
void SQ(int NUM, list* queue);

void simulate(string filename, restaurant* r)
{ 
    list* queue = new list();
    list* history = new list();
    list* merged = new list();

    for (int i = 1; i <= MAXSIZE/2; i++)
    {
        queue->recentTable = queue->insert(queue->recentTable,i,"nhi",2*i);
    }

    ifstream orders(filename);
    string command;

    if (orders.is_open()) {
        while (getline(orders, command)){
            int space = 0;
            for(char c: command){
                if (c == ' '){
                    space++;
                }
            }

            string request = "";
            int ID = 0;
            string name = ""; 
            int age = 0;
            int NUM = 0;

            if(space == 3){
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1+1);
                int pos3 = command.find_first_of(" ", pos2+1);

                request = command.substr(0, pos1);
                if(request == "REG"){
                    ID = stoi(command.substr(pos1+1, pos2-pos1-1));
                    name = command.substr(pos2+1, pos3-pos2-1);
                    age = stoi(command.substr(pos3+1));

                    REG(ID, name, age, r, queue, history, merged);
                }else{
                    name = command.substr(pos1+1, pos2-pos1-1);
                    age = stoi(command.substr(pos2+1, pos3-pos2-1));
                    NUM = stoi(command.substr(pos3+1));

                    REGM(name, age, NUM, r, history, merged);
                }
                
            }else if(space == 2){
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1+1);

                request = command.substr(0, pos1);
                name = command.substr(pos1+1, pos2-pos1-1);
                age = stoi(command.substr(pos2+1));

                REG(ID, name, age, r, queue, history, merged);
            }else if(space == 1){
                int pos1 = command.find_first_of(" ");

                request = command.substr(0, pos1);
                if(request == "CLE"){
                    ID = stoi(command.substr(pos1+1));
                    CLE(ID, r, queue, history, merged);
                }else if(request == "PS"){
                    NUM = stoi(command.substr(pos1+1));
                    PS(NUM, queue, history);
                }else if(request == "PQ"){
                    NUM = stoi(command.substr(pos1+1));
                    PQ(NUM, queue);
                }else if(request == "SQ"){
                    NUM = stoi(command.substr(pos1+1));
                    SQ(NUM, queue);
                }
            }else{
                if(request == "PS"){
                    PS(NUM, queue, history);
                }else if(request == "PQ"){
                    PQ(NUM, queue);
                }else{
                    PT(r, history);
                }  
            }
        }
        orders.close();
    }
    
    cout << "Queue:" << endl;
    for(int i = 0; i < queue->count; i++){
        queue->print();
        queue->recentTable = queue->recentTable->next;
    }

    table* curr = merged->recentTable;
    table* tmp = nullptr;
    cout << "Merged:" << endl;
    while(tmp != curr){
        merged->print();
        merged->recentTable = merged->recentTable->next;
        tmp = merged->recentTable;
    }

    
    cout << "History:" << endl;
    for(int i = 0; i < history->count; i++){
        history->print();
        history->recentTable = history->recentTable->next;
    }
}

void REG(int ID, string name, int age, restaurant* r, list* queue, list* history, list* merged){
    cout << ID << " " << name << " " << age << endl;
}

void REGM(string name, int age, int NUM, restaurant* r, list* history, list* merged){
    cout << "REGM: " << name << " " << age << " " << NUM << endl;
    
}

void CLE(int ID, restaurant* r, list* queue, list* history, list* merged){
    cout << "CLE: " << ID << endl;
}

void PS(int NUM, list* queue, list* history){
    cout << "PS: " << NUM << endl;
    if(NUM == 0){
        table* curr = queue->recentTable->next;
        for(int i = 0; i < queue->count; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
    }else if(queue->recentTable == nullptr){
        cout << "Empty" << endl;
    }else if(NUM <= queue->count){
        table* curr = queue->recentTable->next;
        for(int i = 0; i < NUM; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
    }else if(NUM > queue->count && NUM <= MAXSIZE){
        table* curr = queue->recentTable->next;
        for(int i = 0; i < MAXSIZE; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
}

void PQ(int NUM, list* queue){
cout << "PQ: " << NUM << endl;
}

void PT(restaurant* r, list* history){
    cout << "PT" << endl;
}

void SQ(int NUM, list* queue){
    cout << "SQ: " << NUM << endl;
}

int main(){
    restaurant* r = new restaurant();

    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable,i,"",0);
    }

    simulate("test.txt", r);

    cout << "Restaurant:" << endl;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->print();
        r->recentTable = r->recentTable->next;
    }
    
}

