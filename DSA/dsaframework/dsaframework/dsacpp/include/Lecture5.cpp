
#include <iostream>
#include <iomanip>
#include "heap/Heap.h"

using namespace std;


int min_comparator(int& lhs, int& rhs){
    if(lhs > rhs) return +1;
    else if ( lhs < rhs) return -1;
    else return 0; //equal
    
}

int max_comparator(int& lhs, int& rhs){
    if(lhs > rhs) return -1;
    else if ( lhs < rhs) return +1;
    else return 0; //equal
    
}
void demo_min_heap(){
    int items[] = {90, 10, 87, 3, 87, 17, 56, 39};
    Heap<int> heap;
    
    //Build a min-heap
    heap.heapify(items,8);
    heap.println();
}
void demo_min_heap2(){
    int items[] = {90, 10, 87, 3, 87, 17, 56, 39};
    Heap<int> heap(min_comparator);
    
    //Build a min-heap
    heap.heapify(items,8);
    heap.println();
}
void demo_max_heap(){
    int items[] = {90, 10, 87, 3, 87, 17, 56, 39};
    Heap<int> heap(max_comparator);
    
    //Build a min-heap
    heap.heapify(items,8);
    heap.println();
}

void sort_demo_desc(){
    int items[] = {90, 10, 87, 3, 87, 17, 56, 39};
    Heap<int> heap(max_comparator);
    
    //Build a min-heap
    heap.heapify(items,8);
    
    //POP to get data
    cout << "items: ";
    while(!heap.empty()){
        cout << heap.pop() << ", ";
    }
    cout << endl;
        
}

void sort_demo_asc(){
    int items[] = {90, 10, 87, 3, 87, 17, 56, 39};
    Heap<int> heap(min_comparator);
    
    //Build a min-heap
    heap.heapify(items,8);
    
    //POP to get data
    cout << "items: ";
    while(!heap.empty()){
        cout << heap.pop() << ", ";
    }
    cout << endl;
        
}
    

int main(int argc, char** argv){
    demo_max_heap();
    sort_demo_desc();
    sort_demo_asc();
    
    return 0;
}