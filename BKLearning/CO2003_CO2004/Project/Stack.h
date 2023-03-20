#include<iostream>

#include "IDeck.h"
#include "IList.h"
#include "SLL.h"

using namespace std;

template<class T>
class Stack: public IDeck<T>{
    private:
        SLL<T>* list;
        int count;
    public:
        Stack(){
            this->count = 0;
        }
        ~Stack(){}

        void push(T item){
            list->add(0, item);
        }

        T pop(){ // delete
            if(list->empty()){
                return -1;
            }else{
                count--;
                return list->removeAt(0);
            }
        }
        
        T& peek(){ //get val
            if(list->empty()){
                return -1;
            }else{
                return list->get(0);
            }
        }

        bool empty(){
            return list->empty();
        }

        int size(){
            return count;
        }

        void clear(){
            list->clear();
            count = 0;
        }

        bool remove(T item){
            count--;
            return list->removeItem(item);
        }

        bool contains(T item){
            return list->contains(item);
        }
};
