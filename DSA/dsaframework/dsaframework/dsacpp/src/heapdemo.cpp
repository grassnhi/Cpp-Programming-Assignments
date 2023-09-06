#include <iostream>
#include <iomanip>
#include <sstream>
#include "tree/BST.h"
#include "tree/AVL.h"
#include "list/DLinkedList.h"
#include "geom/Point3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "heap/Heap.h"

using namespace std;


int comparator_1(int& lhs, int& rhs){
    if(lhs < rhs) return -1;
    else if(lhs > rhs) return +1;
    else return 0;
}
int comparator_2(int& lhs, int& rhs){
    if(lhs < rhs) return -5;
    else if(lhs > rhs) return +5;
    else return 0;
}
int comparator_3(int& lhs, int& rhs){
    if(lhs < rhs) return +1;
    else if(lhs > rhs) return -1;
    else return 0;
}
int comparator_4(int& lhs, int& rhs){
    if(lhs < rhs) return +5;
    else if(lhs > rhs) return -5;
    else return 0;
}

void heap_quiz_0(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int> heap;
    heap.heapify(ptr, 6);
    heap.println();
}
void heap_quiz_1(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int> heap(&comparator_1);
    heap.heapify(ptr, 6);
    heap.println();
}
void heap_quiz_2(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int> heap(&comparator_2);
    heap.heapify(ptr, 6);
    heap.println();
}
void heap_quiz_3(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int> heap(&comparator_3);
    heap.heapify(ptr, 6);
    heap.println();
}
void heap_quiz_4(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int> heap(&comparator_4);
    heap.heapify(ptr, 6);
    heap.println();
}


int comparator(int*& lhs, int*& rhs){
    if(*lhs < *rhs) return -1;
    else if(*lhs > *rhs) return +1;
    else return 0;
}
int comparator2(int*& lhs, int*& rhs){
    if(*lhs < *rhs) return +1;
    else if(*lhs > *rhs) return -1;
    else return 0;
}
string item2str(int*& item){
    stringstream os;
    os << *item;
    return os.str();
}
void heap_quiz_5(){
    int ptr[] = {50, 20, 70, 5, 15, 80};
    Heap<int*> heap(&comparator);
    for(int idx=0; idx< 6; idx++) heap.push(&ptr[idx]);
    heap.println(&item2str);
}

void heap_quiz_6(){
    int ptr[] = {85, 15, 20, 75, 45, 10};
    Heap<int> heap(&comparator_2); 
    heap.heapify(ptr, 6);
    heap.println();
    
    heap.remove(45);
    heap.remove(75);
    heap.println();
}

void heap_quiz_7(){
    int ptr[] = {5, 90, 15, 20, 70, 5};
    Heap<int> heap(&comparator_2); 
    heap.heapify(ptr, 6);
    heap.println();
    for(; !heap.empty();){
        int v = heap.pop();
        cout << v << " ";
    }
}

int main(int arc, char** argv){
    heap_quiz_7();
}
