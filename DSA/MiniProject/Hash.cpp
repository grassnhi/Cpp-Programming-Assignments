#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <memory.h>
using namespace std;

const int MAXSIZE = 32; // maximum size of data array
const int TABLE_SIZE = MAXSIZE/2;

class HashMap
{
public:
    class Entry
    {
    private:
        int key; // name (result) -> hashCode
        int value; // name (result)
        int ID; // table ID
        friend class HashMap;
    public:
        Entry(int key, int value, int ID){
            this->key = key;
            this->value = value;
            this->ID = ID;
        }
    };
    
protected:
    Entry** table;
    int capacity;
    int count;
public:
    HashMap(){
        this->capacity = TABLE_SIZE;
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
        return key % TABLE_SIZE;
    }

    void insert(int key, int value, int ID){
        int index = this->hashFunct(key);

        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }
        if (table[index] != nullptr) {
            table[index]->value = value;
            table[index]->ID = ID;
        }else{
            table[index] = new Entry(key, value, ID);
            count++;
        }
    }

    int getValue(int key){
        int index = this->hashFunct(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }
        if (table[index] == nullptr) {
            return -1;
        } else {
            return table[index]->value;
        }
    }

    void remove(int key){
        int index = this->hashFunct(key);
        
        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }

        if (table[index] == nullptr) {
            return;
        }else{
            delete table[index];
            table[index] = nullptr;
            count--;
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
                cout << table[i]->ID << "-" << table[i]->value << endl;
            }
        } 
    }
};



int main(){
    HashMap *hashMap = new HashMap();

    // Test inserting one element
    hashMap->insert(1, 10, 1001);
    if(hashMap->getValue(1) != 10) {
        cout << "Test failed: Inserting one element and getting value" << endl;
    }

    // Test inserting multiple elements
    hashMap->insert(2, 20, 1002);
    hashMap->insert(3, 30, 1003);
    if(hashMap->getValue(2) != 20 || hashMap->getValue(3) != 30) {
        cout << "Test failed: Inserting multiple elements and getting values" << endl;
    }

    // Test inserting the same element twice
    hashMap->insert(1, 15, 1004);
    if(hashMap->getValue(1) != 15) {
        cout << "Test failed: Inserting the same element twice and getting value" << endl;
    }

    // Test removing an element
    hashMap->remove(3);
    if(hashMap->getValue(3) != -1) {
        cout << "Test failed: Removing an element and getting value" << endl;
    }

    // Test printing the table
    stringstream buffer;
    hashMap->printTable();
    string output = buffer.str();

    delete hashMap;
    return 0;
}
