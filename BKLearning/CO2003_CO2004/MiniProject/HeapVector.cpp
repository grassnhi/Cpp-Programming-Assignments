#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "heap/IHeap.h"

template<class T>
class Heap: public IHeap<T>{
    private:
        int compare(T& a, T& b){
            if (a < b) return -1;
            else if(a > b) return 1;
            else return 0;
        }

        bool aLTb(T& a, T& b){
            return compare(a, b) < 0;
        }

        bool aGTb(T& a, T& b){
            return compare(a, b) > 0;
        }

        void swap(int a, int b){
            T temp = this->elements[a];
            this->elements[a] = this->elements[b];
            this->elements[b] = temp;
        }

        int getItem(T item){
            if (this->count == 0) return -1;
            for (int i = 0; i < this->count; ++i) {
                if (this->elements[i] == item) return i;
            }
            return -1;
        }

    protected:
        int count;
        std::vector<T> elements;
        
    public:
        Heap(){
            this->count = 0;
        }

        ~Heap(){
            this->count = 0;
        }

        void heapify(T array[], int size){
            this->count = size;
            for (unsigned int i = 0; i < size; i++)
            {
                insert(array[i]);
            }
            
        }

        void insert(T item){
            elements.push_back(item);
            count++;
            reHeapUp(count - 1);
        }

        void reHeapUp(int position){
            if(position <= 0){
                return;
            }
            int parent = (position - 1) / 2;
            if(aLTb(this->elements[position], this->elements[parent])){
                swap(position, parent);
                reHeapUp(parent);
            }
        }

        void remove(T item){
            int foundIdx = this->getItem(item);
            if (foundIdx == -1) return;
            else {
                this->elements[foundIdx] = this->elements[this->count - 1];
                --this->count;
                this->reHeapDown(foundIdx);
            }
        }

        void reHeapDown(int position){
            int leftChild = position*2 + 1;
            int rightChild = position*2 + 2;
            int lastPosition = this->count - 1;

            if(leftChild <= lastPosition){
                int smallChild = leftChild; //by default => leftChild valid but rightChild invalid
                if(rightChild <= lastPosition){
                    if(aLTb(this->elements[rightChild], this->elements[leftChild])) 
                        smallChild = rightChild;
                }

                if(aLTb(this->elements[smallChild], this->elements[position])){
                    swap(smallChild, position);
                    reHeapDown(smallChild);
                }
            }
        }
};


#endif /* HEAP_H */
