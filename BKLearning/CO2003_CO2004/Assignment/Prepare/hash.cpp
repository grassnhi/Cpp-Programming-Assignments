#include <iostream>
using namespace std;

const int MAXSIZE = 6; // maximum size of data array
const int TABLE_SIZE = MAXSIZE/2;



class HashMap {
public:
    class HashNode {
    public:
        int key;
        int value;
        HashNode(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
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
        }
        delete[] table;
    }
};

int main() {
    int data[MAXSIZE] = {5, 10, 15, 20, 25, 30};
    HashMap myMap;
    for (int i = 0; i < MAXSIZE; i++) {
        myMap.insert(data[i], i);
    }
    cout << myMap.getValue(15); //prints 2
    return 0;
}
