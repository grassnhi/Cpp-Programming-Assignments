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
                if(command == "PS"){
                    PS(NUM, queue, history);
                }else if(command == "PQ"){
                    PQ(NUM, queue);
                }else{
                    PT(r, history);
                }  
            }
        }
        orders.close();
    }
}

void REG(int ID, string name, int age, restaurant* r, list* queue, list* history, list* merged){
    // cout << ID << " " << name << " " << age << endl;
    if(age < 16 || age > 115){
        return;
    }else if(ID > 0 && ID <= MAXSIZE){
        if(queue->recentTable != nullptr && queue->count < MAXSIZE){ // kín bàn
            queue->recentTable = queue->insert(queue->recentTable, ID, name, age);
        }else if(queue->recentTable == nullptr){                              // maybe trống bàn
            table* tmp = r->recentTable;
            while (tmp->ID != ID){
                tmp = tmp->next;
            }
            while (tmp->name != "" && tmp != r->recentTable){
                tmp = tmp->next; 
            }
            if(tmp->name == "" ){ // trống bàn
                tmp->name = name;
                tmp->age = age;
                history->recentTable = history->insert(history->recentTable, tmp->ID, name, age);
            }else{ // hết bàn vô queue
                queue->recentTable = queue->insert(queue->recentTable, ID, name, age);
            }
            
        }
    }else if(ID == 0){
        table* tmp = r->recentTable->next;
        while (tmp->name != "" && tmp != r->recentTable){
            tmp = tmp->next; 
        }
        if(tmp->name == "" ){ // trống bàn
            tmp->name = name;
            tmp->age = age;
            history->recentTable = history->insert(history->recentTable, tmp->ID, name, age);
        }else{ // hết bàn vô queue
            queue->recentTable = queue->insert(queue->recentTable, ID, name, age);
        }
    }
}

void REGM(string name, int age, int NUM, restaurant* r, list* history, list* merged){
    //cout << name << " " << age << " " << NUM << endl;
    if(age < 16 || age > 115){
        return;
    }else if(merged->recentTable == nullptr){
        int count = 0, id = 0, maxID = 0;
        table* curr = r->recentTable->next;
        for(int i = 0; i < NUM + MAXSIZE; i++){
            if(curr->name == ""){
                count++;
                if(count == NUM){
                    count = count - 1;
                    id = curr->ID;
                    if(maxID <= id && id >= NUM){
                        maxID = id - NUM + 1;
                    }else if(maxID > id && id < NUM){
                        maxID = id + MAXSIZE - NUM + 1;
                    }
                }
            }else{
                count = 0;
            }
            curr = curr->next;
        }

        if(maxID != 0){
            curr = r->recentTable;
            while (curr->ID != maxID){
                curr = curr->next;
            }
            curr->name = name;
            curr->age = age;
            merged->recentTable = curr->next;
            table* tmp = curr;
            for(int i = 1; i < NUM; i++){
                tmp = tmp->next;
            }
            curr->next = tmp->next;
            tmp->next = merged->recentTable;
            merged->count = maxID; // lưu id bàn merged
            history->recentTable = history->insert(history->recentTable, curr->ID, curr->name, curr->age);
        }
    }
}

void CLE(int ID, restaurant* r, list* queue, list* history, list* merged){
    cout << "CLE: " << ID << endl;
    if(ID < 0 || ID > MAXSIZE){
        return;
    }
    if(merged == nullptr || (merged != nullptr && ID != merged->count)){
        table* curr = r->recentTable;
        while (curr->ID != ID){
            curr = curr->next;
        }
        if(curr->name != ""){
            curr->name = "";
            curr->age = 0; // trả bàn

            table* tmp = history->recentTable->next;
            table* prev = tmp;
            while (tmp->ID != ID){ // segmentation fault
                prev = tmp;
                tmp = tmp->next;
            }
            history->recentTable = history->removeTable(prev);  // res xóa his

            if(queue->recentTable != nullptr){ // add queue vào (add head vào)
                curr->name = queue->recentTable->next->name;
                curr->age = queue->recentTable->next->age;
                queue->recentTable = queue->removeTable(queue->recentTable); // xóa queue
                history->recentTable = history->insert(history->recentTable, curr->ID, curr->name, curr->age); //update his
            }
        }  
    }else if(ID == merged->count){
        table* curr = r->recentTable;
        while (curr->ID != ID){
            curr = curr->next;
        }
        curr->name = "";
        curr->age = 0; // xóa bàn gộp

        table* tmp = history->recentTable;
        table* prev = nullptr;
        while (tmp->ID != ID){
            prev = tmp;
            tmp = tmp->next;
        }
        history->recentTable = history->removeTable(prev); // xóa lịch sử

        tmp = curr->next;
        curr->next = merged->recentTable->next;
        merged->recentTable->next = tmp;
        merged->clear();  // trả merged về r

        table* fifo = queue->recentTable->next;
        table* save = curr;
        bool added = false;
        while (save != tmp)
        {
            while (curr != tmp)
            {
                if(curr->ID == fifo->ID){
                    added = true;
                    curr->name = fifo->name;
                    curr->age = fifo->age;
                    queue->recentTable = queue->removeTable(queue->recentTable);
                    history->recentTable = history->insert(history->recentTable, fifo->ID, fifo->name, fifo->age);
                    fifo = fifo->next;
                }
                curr = curr->next;
            }
            if(added == false){
                save->name = fifo->name;
                save->age = fifo->age;
                history->recentTable = history->insert(history->recentTable, fifo->ID, fifo->name, fifo->age);
                queue->recentTable = queue->removeTable(queue->recentTable);
                fifo = fifo->next;    
            }
            save = save->next;
            curr = save;
            added = false;
        }
        
    }
}

void PS(int NUM, list* queue, list* history){
    //cout << NUM << endl;
    if(NUM == 0 && queue->recentTable == nullptr){
        history->reverseTable();
        table* curr = history->recentTable;
        for(int i = 0; i < history->count; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
        history->reverseTable();
    }else if((NUM == 0 && queue->recentTable != nullptr) || NUM > queue->count + history->count){
        queue->reverseTable();
        table* curr = queue->recentTable;
        for(int i = 0; i < queue->count; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
        queue->reverseTable();

        history->reverseTable();
        curr = history->recentTable;
        for(int i = 0; i < history->count; i++){
            cout << curr->name << endl;
            curr = curr->next;
        }
        history->reverseTable();
    }else if(NUM < queue->count + history->count){
        if(queue->count == 0){ 
            history->reverseTable();
            table* curr = history->recentTable;
            for(int i = 0; i < NUM; i++){
                cout << curr->name << endl;
                curr = curr->next;
            }
            history->reverseTable();
        }else if(NUM < queue->count){
            queue->reverseTable();
            table* curr = queue->recentTable;
            for(int i = 0; i < NUM; i++){
                cout << curr->name << endl;
                curr = curr->next;
            }
            queue->reverseTable();
        }else if(NUM > queue->count){
            queue->reverseTable();
            table* curr = queue->recentTable;
            for(int i = 0; i < queue->count; i++){
                cout << curr->name << endl;
                curr = curr->next;
            }
            queue->reverseTable();

            NUM = NUM - queue->count;

            history->reverseTable();
            curr = history->recentTable;
            for(int i = 0; i < NUM; i++){
                cout << curr->name << endl;
                curr = curr->next;
            }
            history->reverseTable();
        }
    }
}

void PQ(int NUM, list* queue){
    //cout << NUM << endl;
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

void PT(restaurant* r, list* history){
    //cout << NUM << endl;
    
    int lastID = history->recentTable->ID;
    table* curr = r->recentTable;
    while (curr->ID != lastID){
        curr = curr->next;
    }
    for(int i = lastID; i <= MAXSIZE; i++){
        if(curr->name != ""){
            cout << curr->ID << "-" << curr->name << endl;
        }else{
            cout << "Empty" << endl;
        }
        curr = curr->next;
    }
    for(int i = 1; i < lastID; i++){
        if(curr->name != ""){
            cout << curr->ID << "-" << curr->name << endl;
        }else{
            cout << "Empty" << endl;
        }
        curr = curr->next;
    }
    
}

void SQ(int NUM, list* queue){
    //cout << NUM << endl;
    if(queue->count == 0){
        cout << "Empty" << endl;
    }else if(NUM <= queue->count){
        queue->selectionSort(NUM);
    }else if(NUM > queue->count && NUM <= queue->count){
        queue->selectionSort(queue->count);
    }
}

int main(){
    restaurant* r = new restaurant();

    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable,i,"",0);
    }

    simulate("input1.txt", r);
}

