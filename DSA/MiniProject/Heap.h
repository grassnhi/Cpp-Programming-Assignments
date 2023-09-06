#ifndef HEAP_H
#define HEAP_H

#include <memory.h>
#include <sstream>

#include "heap/IHeap.h"

template<class T>
class Heap: public IHeap<T>{
    protected:
        T* elements;
        int capacity;
        int count;

    public:
        Heap(){
            capacity = 10;
            count = 0;
            elements = new T[capacity];
        }

        ~Heap(){
            delete []elements;

            capacity = 10;
            count = 0;
            elements = new T[capacity];
        }

        void ensureCapacity(int capacity){
            if(capacity >= this->capacity){
                int oldCapacity = capacity;
                capacity = oldCapacity + 
            }
        }

        void heapify(T array[], int size){
            for(int idx=0; idx < size; idx++) push(array[idx]);
        }


}


#endif /* HEAP_H */
