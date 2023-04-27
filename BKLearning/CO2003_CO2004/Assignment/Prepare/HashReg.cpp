class HashMap
{
public:
    class Entry
    {
    private:
        int key; // name (result) -> hashCode
        string name; // name 
        int ID; // table ID
        int NUM;
        friend class HashMap;
    public:
        Entry(int key, string name, int NUM = 1, int ID){
            this->key = key;
            this->name = name;
            this->NUM = NUM;
            this->ID = ID;
        }
    };
    
protected:
    Entry** table;
    int capacity;
    int count;
public:
    HashMap(){
        this->capacity = HALFMAX;
        this->count = 0;
        this->table = new Entry*[capacity];
        for(int i = 0; i < capacity; i++){
            this->table[i] = nullptr;
        }
    }

    ~HashMap(){
        deleteMap();
    }

    int hashFunct(int key) {
        return key % HALFMAX;
    }

    void insert(int key, string name, int ID){
        int index = this->hashFunct(key);

        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }
        if (table[index] != nullptr) {
            table[index]->name = name;
            table[index]->ID = ID;
            table[index]->NUM = 1;
        }else{
            table[index] = new Entry(key, name, ID);
            count++;
        }
    }

    void updateOrders(string name){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->name == name) { 
                table[i]->NUM++;
            }
        }
    }

    bool search(string name){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->name == name) { 
                return true;
            }
        }
        return false;
    }

    int getCount(){
        return this->count;
    }

    void remove(int ID){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->ID == ID) { 
                delete table[i];
                table[i] = nullptr;
                count--;
            }
        }
    }

    void deleteMap(){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr) { 
                delete table[i];
                table[i] = nullptr;
            }
        }
        delete[] table;
        this->count = 0;
    }

    void printTable() {
        for(int i = 0; i < capacity; i++) {
            if(table[i] != nullptr) {
                cout << table[i]->ID << "-" << table[i]->result << "-" << table[i]->NUM << endl;
            }
        } 
    }
};