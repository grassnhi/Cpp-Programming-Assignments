#include <iostream>
using namespace std;

const int TABLE_SIZE = 3;

class HashNode {
public:
    int key;
    int value;
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashMap {
private:
    HashNode **table;
public:
    HashMap() {
        table = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }
    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }
    void insert(int key, int value) {
        int hash = hashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashFunc(hash + 1);
        }
        if (table[hash] != NULL) {
            delete table[hash];
        }
        table[hash] = new HashNode(key, value);
    }
    int getValue(int key) {
        int hash = hashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashFunc(hash + 1);
        }
        if (table[hash] == NULL) {
            return -1;
        } else {
            return table[hash]->value;
        }
    }
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
            delete[] table;
        }
    }
};

int main() {
    HashMap myMap;
    myMap.insert(3, 10); //inserting key=3, value=10
    myMap.insert(6, 20); //inserting key=6, value=20
    myMap.insert(9, 30); //inserting key=9, value=30
    cout << myMap.getValue(6); //prints 20
    return 0;
}
