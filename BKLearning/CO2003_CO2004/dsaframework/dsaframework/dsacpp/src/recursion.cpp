#include <iostream>
#include <iomanip>
#include "geom/Vector3D.h"
using namespace std;

/* Guideline for using assertion in C++
 * https://www.softwaretestinghelp.com/assert-in-cpp/
 */

//#define NDEBUG    //uncomment if you want to disable assert
#include <cassert>

/*
 * recursion: 
 *  'size' decreased => checking (size <= 1) to break the recursion
 */
int sum_recursion_by_size(int* head, int size){
    if(size <= 1) return *head;
    return *head + sum_recursion_by_size(head + 1, size -1);
}

/*
 * recursion: 
 *  'from' increased => checking (from >= size - 1) to break the recursion
 */
int sum_recursion_by_index(int* head, int size, int from){
    if(from >= size - 1) return head[from];
    return head[from] + sum_recursion_by_index(head, size, from + 1);
}

void demo_recursion(){
    int array[] = {1,2,3,4,5};
    int sum_1 = sum_recursion_by_size(array, 5);
    int sum_2 = sum_recursion_by_index(array, 5, 0);
    
    assert(sum_1 == 15); //expectation
    assert(sum_2 == 15); //expectation
    cout << "SUM, by some algorithms:" << sum_1 << "; " << sum_2 << endl;
}

template<class T>
struct SNode{
    T data;
    SNode<T>* next;
    SNode(T data, SNode<T>* next = NULL){
        this->data = data;
        this->next = next;
    }
};

SNode<int>* create_schain(){
    int array[] = {10, 50, 20, 90, 70};
    
    SNode<int>* head = NULL;
    for(int idx=4; idx >= 0; idx--) head = new SNode<int>(array[idx], head);
    return head;
}
void println_schain(SNode<int>* head){
    SNode<int>* cursor;
    for(cursor=head; cursor != NULL; cursor=cursor->next)
        cout << cursor->data << " ";
    cout << endl;
}
void delete_schain(SNode<int>* head){
    SNode<int>* cursor;
    SNode<int>* backup;
    for(cursor=head; cursor != NULL; cursor=backup){
        backup = cursor->next;
        delete cursor;
    }
}
int main(int argc, char** argv){
    SNode<int>* head = create_schain();
    println_schain(head);
    delete_schain(head);
    return 0;
}

