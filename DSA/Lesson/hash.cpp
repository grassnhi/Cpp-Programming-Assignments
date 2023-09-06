int countryHash(string& country, int size){
    int sum = 0;
    for(int idx = 0; idx < country; idx++){
        sum += country[idx];
    }
    return sum%size;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <memory.h>
using namespace std;

#include "hash/IMap.h"


template<class K, class V>
class XHashMap: public IMap<K,V>{
public:
    class Entry; //forward declaration
    
protected:
    DLinkedList<Entry<K, V>>** table; // -> array of dll
    int capacity;   //size of table
    int count;      //number of entries stored hash-map
    int (*hashCode)(K&,int); //hasCode(K key, int tableSize): tableSize means capacity

public:
    
    //Entry: BEGIN
    class Entry{
    private:
        K key;
        V value;
        Entry* prev;
        Entry* next;
        friend class XHashMap<K,V>;
        
    public:
        Entry(){
            this->prev = 0;
            this->next = 0;
        }
        Entry(K key, V value, Entry* prev=0, Entry* next=0){
            this->key = key;
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
    };
    
    //Entry: END

public:
    MyHash(int (*hashCode)(K&, V)){
        table = new 
    }

    V put(K key, V value){
        index = this-> hashCode(key, this->capacity);
        DLinkedList<Entry>:: Iterator it;
        for(int it = table[index])
    }
};