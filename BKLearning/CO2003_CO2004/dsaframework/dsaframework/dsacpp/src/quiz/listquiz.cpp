#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "geom/Vector3D.h"
using namespace std;


void println_arraylist_index(XArrayList<int>* plist){
    for(int idx=0; idx < plist->size(); idx++) cout << plist->get(idx) << " ";
    cout << endl;
}
void println_arraylist_iterator(XArrayList<int>* plist){
    XArrayList<int>::Iterator it;
    for(it=plist->begin(); it != plist->end(); it++) cout << *it << " ";
    cout << endl;
}
XArrayList<int>* arraylist_add_head(int *ptr, int size){
    XArrayList<int>* plist = new XArrayList<int>();
    for(int idx=0; idx < size; idx++) plist->add(0, ptr[idx]);
    return plist;
}

XArrayList<int>* arraylist_append(int *ptr, int size){
    XArrayList<int>* plist = new XArrayList<int>();
    for(int idx=0; idx < size; idx++) plist->add(ptr[idx]);
    return plist;
}
XArrayList<int>* create_arraylist(){
    XArrayList<int>* ptr = new XArrayList<int>();
    int array[] = {0,1,2,3,4};
    for(int x: array) ptr->add(x);
    return ptr;
}


//DLINKEDLIST
void println_dlinked_index(DLinkedList<int>* plist){
    for(int idx=0; idx < plist->size(); idx++) cout << plist->get(idx) << " ";
    cout << endl;
}
void println_dlinked_iterator(DLinkedList<int>* plist){
    DLinkedList<int>::Iterator it;
    for(it=plist->begin(); it != plist->end(); it++) cout << *it << " ";
    cout << endl;
}
void println_dlinked_iterator_backward(DLinkedList<int>* plist){
    DLinkedList<int>::BWDIterator it;
    for(it=plist->bbegin(); it != plist->bend(); it--) cout << *it << " ";
    cout << endl;
}

DLinkedList<int>* dlist_add_head(int *ptr, int size){
    DLinkedList<int>* plist = new DLinkedList<int>();
    for(int idx=0; idx < size; idx++) plist->add(0, ptr[idx]);
    return plist;
}

DLinkedList<int>* dlist_append(int *ptr, int size){
    DLinkedList<int>* plist = new DLinkedList<int>();
    for(int idx=0; idx < size; idx++) plist->add(ptr[idx]);
    return plist;
}

//SLINKEDLIST
void println_slinked_index(SLinkedList<int>* plist){
    for(int idx=0; idx < plist->size(); idx++) cout << plist->get(idx) << " ";
    cout << endl;
}
void println_slinked_iterator(SLinkedList<int>* plist){
    SLinkedList<int>::Iterator it;
    for(it=plist->begin(); it != plist->end(); it++) cout << *it << " ";
    cout << endl;
}

SLinkedList<int>* slist_add_head(int *ptr, int size){
    SLinkedList<int>* plist = new SLinkedList<int>();
    for(int idx=0; idx < size; idx++) plist->add(0, ptr[idx]);
    return plist;
}

SLinkedList<int>* slist_append(int *ptr, int size){
    SLinkedList<int>* plist = new SLinkedList<int>();
    for(int idx=0; idx < size; idx++) plist->add(ptr[idx]);
    return plist;
}

////ArrayList Impl

void array_quiz_1(){
    int array[20] = {30, 20, 10, 50, 70};
    int size = 5; 
    /*array's capacity: 20; currently stores 'size' items; size = 5*/
    
}
///////////////// SLINKED
template<class T>
struct SNode{
    T data;
    SNode<T>* next;
    SNode(T data, SNode<T>* next = NULL){
        this->data = data;
        this->next = next;
    }
};

template<class T>
T sum_loop(SNode<T>* head){
    T sum = 0;
    SNode<T>* cursor = head;
    while(cursor != NULL){
        sum += cursor->data;
        cursor = cursor->next;
    }
    return sum;
}

template<class T>
T sum_recursion(SNode<T>* head){
    if(head == NULL) return 0;
    return head->data + sum_recursion(head->next);
}

void println_schain(SNode<int>* head){
    SNode<int>* cursor = head;
    while(cursor != NULL){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
}
void create_empty_schain(){
    /*
    SNode<int> head = new SNode<int>(0);
    SNode<int> tail = new SNode<int>(0);
    head.next = tail; tail.next = head;
     */
}
SNode<int>* create_empty_schain_2(){
    SNode<int>* head = 0;
    head = new SNode<int>(80,
            new SNode<int>(70, 
            new SNode<int>(60,
            new SNode<int>(50, head))));
    return head;
}

///////////////// DLINKED
template<class T>
struct DNode{
    T data;
    DNode<T>* next, *prev;
    DNode(T data, DNode<T>* next = NULL, DNode<T>* prev=NULL){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

void create_empty_dchain(){
    /*
    DNode<int> head = new DNode<int>(0);
    DNode<int> tail = new DNode<int>(0);
    head.next = tail; tail.next = NULL;
    head.prev = 0; tail.prev = head;
    */
}

/*
 head->[dummy]<->(10)<->(20)<->(30)<->[dummy]<-tail
 */
void create_dchain(DNode<int>*& head, DNode<int>*& tail){
    head = new DNode<int>(0);
    tail = new DNode<int>(0);
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    int array[] = {10, 20, 30};
    DNode<int>* cursor = head;
    for(int v: array){
        cursor->next = new DNode<int>(v, cursor->next, cursor);
        cursor = cursor->next;
    }
}

/*
 head->[dummy]<->(1,2,3)<->(2,3,4)<->(3,4,5)<->[dummy]<-tail
 */
void demo_dchain_points(){
    DNode<Vector3D>* head = new DNode<Vector3D>(Vector3D());
    DNode<Vector3D>* tail = new DNode<Vector3D>(Vector3D());
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    Vector3D points[] = {
        Vector3D(1,2,3),Vector3D(2,3,4),Vector3D(3,4,5)
    };
    DNode<Vector3D>* cursor = head;
    for(Vector3D v: points){
        cursor->next = new DNode<Vector3D>(v, cursor->next, cursor);
        cursor = cursor->next;
    }
    //
    cursor = head->next;
    while(cursor != tail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
    
}
void demo_dchain_points_2(){
    DNode<Vector3D>* head = new DNode<Vector3D>(Vector3D());
    DNode<Vector3D>* tail = new DNode<Vector3D>(Vector3D());
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    Vector3D points[] = {
        Vector3D(1,2,3),Vector3D(2,3,4),Vector3D(3,4,5)
    };
    DNode<Vector3D>* cursor = head;
    for(Vector3D v: points){
        DNode<Vector3D>* node = new DNode<Vector3D>(v);
        node->next = cursor->next;node->prev = cursor;
        cursor->next = node;
        cursor = cursor->next;
    }
    //
    cursor = head->next;
    while(cursor != tail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
    
}

void println_dchain_fwd(){
    DNode<int> *phead, *ptail;
    create_dchain(phead, ptail);
    DNode<int>* cursor = phead->next;
    while(cursor != ptail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
}

/*
 head->[dummy]<->(3)<->(5)<->(7)<->(9)<->[dummy]<-tail
 */
void demo_dchain_int_1(){
    DNode<int>* head = new DNode<int>(0);
    DNode<int>* tail = new DNode<int>(0);
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    int values[] = {
        3,5,7,9
    };
    DNode<int>* cursor = head;
    for(int v: values){
        cursor->next = new DNode<int>(v, cursor->next, cursor);
        cursor = cursor->next;
    }
    //
    DNode<int>* removed = head->next->next;
    cout << removed->data << endl;
    
    //remove:
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    delete removed;
    //
    cursor = head->next;
    while(cursor != tail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
    
}

/*
 head->[dummy]<->(3)<->(5)<->(7)<->(9)<->[dummy]<-tail
 */
void demo_dchain_insertion(){
    DNode<int>* head = new DNode<int>(0);
    DNode<int>* tail = new DNode<int>(0);
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    int values[] = {
        3,5,7,9
    };
    DNode<int>* cursor = head;
    for(int v: values){
        cursor->next = new DNode<int>(v, cursor->next, cursor);
        cursor = cursor->next;
    }
    
    int index = 2;
    int cursor_idx;
    for(cursor_idx=-1, cursor=head; cursor_idx < index; cursor_idx++, cursor=cursor->next);
    cout << cursor->data << endl;
    //insert
    DNode<int>* prev = cursor->prev;
    DNode<int>* node = new DNode<int>(99, cursor, prev);
    prev->next = node; cursor->prev = node;
    //
    cursor = head->next;
    while(cursor != tail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
    
}

void demo_dchain_index2ptr(){
    DNode<int>* head = new DNode<int>(0);
    DNode<int>* tail = new DNode<int>(0);
    head->next = tail; tail->next = NULL;
    head->prev = NULL; tail->prev = head;
    
    int values[] = {
        3,5,7,9
    };
    DNode<int>* cursor = head;
    for(int v: values){
        cursor->next = new DNode<int>(v, cursor->next, cursor);
        cursor = cursor->next;
    }
    //
    int index = 2;
    int cursor_idx = -1;
    cursor = head;
    while(cursor_idx < index){
        cursor_idx += 1;
        cursor = cursor->next;
    }
    cout << cursor->data << endl;
    
    //index: 2 (means item value: 7)
    for(cursor_idx=-1, cursor=head; cursor_idx < index; cursor_idx++, cursor=cursor->next);
    cout << cursor->data << endl;
    //
    cursor = head->next;
    while(cursor != tail){
        cout << cursor->data << " ";
        cursor = cursor->next;
    }
    cout << endl;
    
}

int main(int argc, char** argv){
    demo_dchain_insertion();
    return 0;
}