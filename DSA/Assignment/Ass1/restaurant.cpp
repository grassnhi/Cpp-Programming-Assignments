#include "main.h"

class list {  // list->table
public:
    int count = 0;
    table* recentTable;

    list() {
        recentTable = nullptr;
    }

    ~list() {
        clear();
        delete recentTable;
    }

    table* finsert(table* last, int ID, string name, int age)
    {   // adds a new table to the list when the list is empty or has only one element
        if (last != nullptr)
            return last;
        table* temp = new table(ID, name, age, last);

        last = temp;
        last->next = last;

        this->count++;
        return last;
    }

    table* insert(table* last, int ID, string name, int age) // to tail
    {   // adds a new table to the list if it's not empty.
        if (last == NULL)
            return finsert(last, ID, name, age);
        table* temp = new table(ID, name, age, last->next);
        last->next = temp;
        last = temp;
        this->count++;
        return last;
    }

    void print() {
        cout << recentTable->ID << " " << recentTable->name << " " << recentTable->age << endl;
    }

    void clear() {
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

    void reverseTable() { // reverse -> curr = last (id 15)
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
            if (foll != nullptr) {
                foll = foll->next;
            }

        }
        curr->next = last;
        last = curr->next;
        recentTable = curr;
    }

    void removeTable(table* last) { //from head, the next of last
        if (last == nullptr || last->next == last) {
            recentTable = nullptr;
            last = nullptr;
            count = 0;
        }
        else {
            table* tmp = last->next;
            if (last->next == recentTable) recentTable = last;
            last->next = last->next->next;
            delete tmp;
            count--;
        }
    }

    void swapTable(table* curr, table* elder) {
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

    void selectionSort(int NUM) {
        table* curr = recentTable->next;  // head of queue -> ra
        table* elder = curr;
        for (int i = 1; i <= NUM; i++) {
            table* tmp = curr;
            for (int j = i+1; j <= count; j++) {
                if (tmp->age == elder->age && tmp->ID > elder->ID) {
                    elder = tmp;
                }
                if (tmp->age > elder->age) {
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

void REG(int ID, string name, int age, restaurant* r);
void REGM(string name, int age, int NUM, restaurant* r);
void CLE(int ID, restaurant* r);
void PS(int NUM);
void PQ(int NUM);
void PT(restaurant* r);
void SQ(int NUM);

list* queue = new list();
list* waitting = new list();
list* history = new list();
list* archive = new list();
table* newEdited = nullptr;
table* merged = nullptr;

void simulate(string filename, restaurant* r)
{
    ifstream orders(filename);
    string command;

    if (orders.is_open()) {
        while (getline(orders, command)) {
            int space = 0;
            for (char c : command) {
                if (c == ' ') {
                    space++;
                }
            }

            string request = "";
            int ID = 0;
            string name = "";
            int age = 0;
            int NUM = 0;

            if (space == 3) {
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1 + 1);
                int pos3 = command.find_first_of(" ", pos2 + 1);

                request = command.substr(0, pos1);
                if (request == "REG") {
                    ID = stoi(command.substr(pos1 + 1, pos2 - pos1 - 1));
                    name = command.substr(pos2 + 1, pos3 - pos2 - 1);
                    age = stoi(command.substr(pos3 + 1));

                    REG(ID, name, age, r);
                }
                else {
                    name = command.substr(pos1 + 1, pos2 - pos1 - 1);
                    age = stoi(command.substr(pos2 + 1, pos3 - pos2 - 1));
                    NUM = stoi(command.substr(pos3 + 1));

                    REGM(name, age, NUM, r);
                }

            }
            else if (space == 2) {
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1 + 1);

                request = command.substr(0, pos1);
                name = command.substr(pos1 + 1, pos2 - pos1 - 1);
                age = stoi(command.substr(pos2 + 1));

                REG(ID, name, age, r);
            }
            else if (space == 1) {
                int pos1 = command.find_first_of(" ");

                request = command.substr(0, pos1);
                if (request == "CLE") {
                    ID = stoi(command.substr(pos1 + 1));
                    CLE(ID, r);
                }
                else if (request == "PS") {
                    NUM = stoi(command.substr(pos1 + 1));
                    PS(NUM);
                }
                else if (request == "PQ") {
                    NUM = stoi(command.substr(pos1 + 1));
                    PQ(NUM);
                }
                else if (request == "SQ") {
                    NUM = stoi(command.substr(pos1 + 1));
                    SQ(NUM);
                }
            }
            else {
                if (command == "PS") {
                    PS(NUM);
                }
                else if (command == "PQ") {
                    PQ(NUM);
                }
                else if (command == "PT") {
                    PT(r);
                }
            }
        }
        orders.close();
    }

    table *curr = r->recentTable->next;
	while (curr != r->recentTable) {
		table* tmp = curr;
		curr = curr->next;
		delete tmp;
	}

    history->clear();
    queue->clear();
    waitting->clear();
    archive->clear();

    delete newEdited;

    delete merged;

}

void REG(int ID, string name, int age, restaurant* r) {
    if (age < 16 || age > 115) {
        return;
    }
    else if (ID > 0 && ID <= MAXSIZE) {
        if (history->count == MAXSIZE && queue->count < MAXSIZE) {
            queue->recentTable = queue->insert(queue->recentTable, ID, name, age);
            waitting->recentTable = waitting->insert(waitting->recentTable, ID, name, age);
            archive->recentTable = archive->insert(archive->recentTable, ID, name, age);
        }
        else if (history->count < MAXSIZE) {
            bool check = false;
            if (merged != NULL) {
                for (int i = 0; i < merged->age; i++) {
                    int c = merged->ID + i;
                    if(c > 15){
                        c = c % 15;
                    }
                    if (ID == c) {
                        check = true;
                        break;
                    }

                }
            }
            if (check == true) {
                table* tmp = r->recentTable->next;
                int c = merged->ID + merged->age;
                if(c > 15) c = c%15 ;
                while (tmp->ID != c) {

                    tmp = tmp->next;
                } 
                while (tmp->name != "") {
                    tmp = tmp->next;
                }  
                tmp->name = name;
                tmp->age = age;
                history->recentTable = history->insert(history->recentTable, tmp->ID, name, age);
                archive->recentTable = archive->insert(archive->recentTable, tmp->ID, name, age);
                newEdited = new table(tmp->ID, name, age, nullptr);
            }
            else {
                table* tmp = r->recentTable->next;
                while (tmp->ID != ID) {
                    tmp = tmp->next;
                }
                while (tmp->name != "") {
                    tmp = tmp->next;
                }
                tmp->name = name;
                tmp->age = age;
                history->recentTable = history->insert(history->recentTable, tmp->ID, name, age);
                archive->recentTable = archive->insert(archive->recentTable, tmp->ID, name, age);
                newEdited = new table(tmp->ID, name, age, nullptr);
            }

        }
    }
    else if (ID == 0) {
        if (history->count == MAXSIZE && queue->count < MAXSIZE) {
            queue->recentTable = queue->insert(queue->recentTable, ID, name, age);
            waitting->recentTable = waitting->insert(waitting->recentTable, ID, name, age);
            archive->recentTable = archive->insert(archive->recentTable, ID, name, age);
        }
        else if (history->count < MAXSIZE) {
            table* tmp = r->recentTable->next;
            while (tmp->name != "") {
                tmp = tmp->next;
            }
            tmp->name = name;
            tmp->age = age;
            history->recentTable = history->insert(history->recentTable, tmp->ID, name, age);
            archive->recentTable = archive->insert(archive->recentTable, tmp->ID, name, age);
            newEdited = new table(tmp->ID, name, age, nullptr);
        }
    }
}

void REGM(string name, int age, int NUM, restaurant* r) {
    if (age < 16 || age > 115) {
        return;
    }
    else if (merged == nullptr) {
        int count = 0, id = 0, maxID = 0;
        table* curr = r->recentTable->next;
        for (int i = 0; i < NUM + MAXSIZE; i++) {
            if (curr->name == "") {
                count++;
                if (count == NUM) {
                    count = count - 1;
                    id = curr->ID;
                    if (maxID <= id && id >= NUM) {
                        maxID = id - NUM + 1;
                    }
                    else if (maxID > id && id < NUM) {
                        maxID = id + MAXSIZE - NUM + 1;
                    }
                }
            }
            else {
                count = 0;
            }
            curr = curr->next;
        }

        if (maxID != 0) {
            curr = r->recentTable->next;
            while (curr->ID != maxID) {
                curr = curr->next;
            }
            curr->name = name;
            curr->age = age;

            table* tmp = curr;
            for (int i = 1; i < NUM; i++) {
                tmp = tmp->next;
                tmp->name = "";
            }
            merged = new table(curr->ID, curr->name, NUM, nullptr);

            history->recentTable = history->insert(history->recentTable, curr->ID, curr->name, curr->age);
            history->count += NUM - 1;
            archive->recentTable = archive->insert(archive->recentTable, curr->ID, curr->name, curr->age);
            newEdited = new table(curr->ID, curr->name, curr->age, nullptr);
        }
    }
}

void CLE(int ID, restaurant* r) {
    if (ID < 1 || ID > MAXSIZE) {
        return;
    }
    if (merged != NULL) {
        bool check = false;
        for (int i = 1; i < merged->age; i++) {
            if (ID == merged->ID + i) {
                check = true;
                break;
            }
        }
        if (check == true) return;
    }
    if (merged == nullptr || (merged != nullptr && ID != merged->ID)) {
        table* curr = r->recentTable;
        while (curr->ID != ID) {
            curr = curr->next;
        }
        if (curr->name != "") {
            newEdited = new table(curr->ID, "", curr->age, nullptr);
            string name = curr->name;
            int age = curr->age;
            curr->name = "";
            curr->age = 0;
            table* tmp = history->recentTable->next;
            table* prev = history->recentTable;
            while (tmp->ID != ID) {
                prev = tmp;
                tmp = tmp->next;
            }
            history->removeTable(prev);
            table* prevD = archive->recentTable->next;
            table* del = prevD->next;
            while (del->name != name || del->age != age) {
                prevD = del;
                del = del->next;
            }
            archive->removeTable(prevD);

            if (queue->recentTable != nullptr) {
                curr->name = queue->recentTable->next->name;
                curr->age = queue->recentTable->next->age;

                table* tmp = waitting->recentTable->next;
                table* prev = waitting->recentTable;
                while (tmp->name != curr->name || tmp->age != curr->age) {
                    prev = tmp;
                    tmp = tmp->next;
                }
                queue->removeTable(queue->recentTable);
                waitting->removeTable(prev);

                history->recentTable = history->insert(history->recentTable, curr->ID, curr->name, curr->age);
                newEdited = new table(curr->ID, curr->name, curr->age, nullptr);
            }
        }
    }
    else if (ID == merged->ID) {
        table* curr = r->recentTable;
        while (curr->ID != ID) {
            curr = curr->next;
        }
        newEdited = new table(curr->ID, "", curr->age, nullptr);

        table* prevD = archive->recentTable->next;
        table* del = prevD->next;
        while (del->name != curr->name || del->age != curr->age) {
            prevD = del;
            del = del->next;
        }
        archive->removeTable(prevD);

        for (int i = 0; i < merged->age; i++) {
            curr->name = "";
            curr->age = 0;
            curr = curr->next;
        }
        table* tmp = history->recentTable->next;
        table* prev = history->recentTable;
        while (tmp->ID != ID) {
            prev = tmp;
            tmp = tmp->next;
        }

        history->removeTable(prev);
        history->count -= merged->age - 1;

        // Add in4 to merged tables from queue
        table* fifo = queue->recentTable->next;
        for (int i = 0; i < merged->age; i++) {
            if(history->count < MAXSIZE && queue->recentTable != nullptr){
                if (fifo->ID > 0 && fifo->ID <= MAXSIZE){
                    table* tmp = r->recentTable;
                    while (tmp->ID != fifo->ID)
                    {
                        tmp = tmp->next;
                    }
                    while (tmp->name != "") {
                        tmp = tmp->next;
                    }
                    tmp->name = fifo->name;
                    tmp->age = fifo->age;

                    table* del = waitting->recentTable->next;
                    table* prev = waitting->recentTable;
                    while (del->name != tmp->name || del->age != tmp->age) {
                        prev = del;
                        del = del->next;
                    }
                    newEdited = new table(tmp->ID, fifo->name, fifo->age, nullptr);
                    history->recentTable = history->insert(history->recentTable, tmp->ID, fifo->name, fifo->age);
                    fifo = fifo->next;
                    queue->removeTable(queue->recentTable);
                    waitting->removeTable(prev);
                }else if(fifo->ID == 0){
                    table* tmp = r->recentTable->next;
                    while (tmp->name != "") {
                        tmp = tmp->next;
                    }
                    tmp->name = fifo->name;
                    tmp->age = fifo->age;

                    table* del = waitting->recentTable->next;
                    table* prev = waitting->recentTable;
                    while (del->name != tmp->name || del->age != tmp->age) {
                        prev = del;
                        del = del->next;
                    }
                    newEdited = new table(tmp->ID, fifo->name, fifo->age, nullptr);
                    history->recentTable = history->insert(history->recentTable, tmp->ID, fifo->name, fifo->age);
                    fifo = fifo->next;
                    queue->removeTable(queue->recentTable);
                    waitting->removeTable(prev);
                }
            }   
        }
        merged = nullptr;
    }
}

void PS(int NUM) {
    if (NUM > 2 * MAXSIZE) {
        return;
    }
    else if (archive->count == 0) {
        cout << "Empty" << endl;
    }
    else if (NUM == 0 || (NUM > archive->count && NUM <= 2 * MAXSIZE)) {
        archive->reverseTable();
        table* curr = archive->recentTable;
        for (int i = 0; i < archive->count; i++) {
            cout << curr->name << endl;
            curr = curr->next;
        }
        archive->reverseTable();
    }
    else if (NUM <= archive->count) {
        archive->reverseTable();
        table* curr = archive->recentTable;
        for (int i = 0; i < NUM; i++) {
            cout << curr->name << endl;
            curr = curr->next;
        }
        archive->reverseTable();
    }
}

void PQ(int NUM) {
    if (waitting->recentTable == nullptr) {
        cout << "Empty" << endl;
    }
    else if (NUM == 0) {
        table* curr = waitting->recentTable->next;
        for (int i = 0; i < waitting->count; i++) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
    else if (NUM <= waitting->count) {
        table* curr = waitting->recentTable->next;
        for (int i = 0; i < NUM; i++) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
    else if (NUM > waitting->count && NUM <= MAXSIZE) {
        table* curr = waitting->recentTable->next;
        for (int i = 0; i < waitting->count; i++) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
}

void PT(restaurant* r) {
    int lastID = newEdited->ID;
    table* curr = r->recentTable;
    while (curr->ID != lastID) {
        curr = curr->next;
    }
    for (int i = lastID; i <= MAXSIZE; i++) {
        if (curr->name != "") {
            cout << curr->ID << "-" << curr->name << endl;
        }
        curr = curr->next;
    }
    for (int i = 1; i < lastID; i++) {
        if (curr->name != "") {
            cout << curr->ID << "-" << curr->name << endl;
        }
        curr = curr->next;
    }
}

void SQ(int NUM) {
    if (queue->count == 0) {
        cout << "Empty" << endl;
        return;
    }
    else if (NUM <= queue->count) {
        table* tmp = queue->recentTable->next;
        for (int i = 0; i < queue->count; i++) {
            table* t = waitting->recentTable->next;
            int count = 0;
            while(tmp->name != t->name || tmp->age != t->age){
                t = t->next;
                count++;
            }
            tmp->ID = count;
            tmp = tmp->next;
        }
        queue->selectionSort(NUM);
        table* curr = archive->recentTable;
        tmp = queue->recentTable;
        for (int i = 0; i < queue->count; i++) {
            for (int j = 0; j < archive->count; j++) {
                if (curr->age == tmp->age && curr->name == tmp->name) {
                    tmp->ID = curr->ID;
                }
                curr = curr->next;
            }
            tmp = tmp->next;
        }
    }
    else if (NUM > queue->count && NUM <= MAXSIZE) {
        table* tmp = queue->recentTable->next;
        for (int i = 0; i < queue->count; i++) {
            table* t = waitting->recentTable->next;
            int count = 0;
            while(tmp->name != t->name || tmp->age != t->age){
                t = t->next;
                count++;
            }
            tmp->ID = count;
            tmp = tmp->next;
        }
        queue->selectionSort(queue->count);
        table* curr = archive->recentTable;
        tmp = queue->recentTable;
        for (int i = 0; i < queue->count; i++) {
            for (int j = 0; j < archive->count; j++) {
                if (curr->age == tmp->age && curr->name == tmp->name) {
                    tmp->ID = curr->ID;
                }
                curr = curr->next;
            }
            tmp = tmp->next;
        }
    }

    table* tmp = queue->recentTable->next;
    table* prev = tmp;
    while (prev != queue->recentTable)
    {
        prev = tmp;
        cout << tmp->name << endl;
        tmp = tmp->next;
    }
}