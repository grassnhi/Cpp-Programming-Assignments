#include<iostream>

#include "IDeck.h"
#include "IList.h"
#include "SLL.h"

using namespace std;

template<class T>
class Queue: public IDeck<T>{
    private:
        SLL<T> list;
        int count;
    public:
        Queue(){
            this->count = 0;
        }

        ~Queue(){ }

        void push(T item){
            list.add(item);
            count++;
        }

        T pop(){
            if(list->empty()){
                return -1;
            }else{
                count--;
                return list.removeAt(0);
            }
        }

        T& peek(){
            if(list->empty()){
                return -1;
            }else{
                return list.get(0);
            }
        }

        bool empty(){
            return list.empty();
        }

        int size(){
            return count;
        }

        void clear(){
            list.clear();
            count = 0;
        }

        bool remove(T item){
            count--;
            return list.removeItem(item);
        }

        bool contains(T item){
            return list.contains(item);
        }
};