#include <iostream>
#include <iomanip>
#include <sstream>
#include "tree/BST.h"
#include "tree/AVL.h"
#include "list/DLinkedList.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "heap/Heap.h"


using namespace std;


/**
 * {10 | 40,| 22, 43, 20, 10, 45, 50}
 *              10
 *             
 * 
 * 
 * 
 */
void demo_1(){
    Heap<int> heap;
    int array[] = {100, 40, 22, 43, 20, 10, 45, 50};
    heap.heapify(array, 8);
    heap.println();
}

//WHY: passed by reference????

/*
 min heap: a < b <=> a - b < 0 <=> negative == return -1
 max heap: reversed way
 * 
 */
int compare(int& a, int& b){
    if(a < b ) return +1;
    else if(a > b) return -1;
    else return 0;
}

int compare3(int& a, int& b){
    if(a < b ) return -1;
    else if(a > b) return +1;
    else return 0;
}

void demo_2(){
    Heap<int> heap(&compare);
    int array[] = {100, 40, 22, 43, 20, 10, 45, 50};
    heap.heapify(array, 8);
    heap.println();
}

void demo_3(){
    Heap<int> heap(&compare3);
    int array[] = {100, 40, 22, 43, 20, 10, 45, 50};
    heap.heapify(array, 8);
    heap.println();
}



int vector_compare(Vector3D*& a, Vector3D*& b ){
    if(a->length() < b->length()) return -1;
    else if(a->length() > b->length())  return +1;
    else return 0;
}

/*
T = Vector3D
T = Vector3D*

T&   <=> Vector3D*&
=> T = T&
 
*/

//Item Type (T)

string vec2str(Vector3D*& vec){
    return Vector3D::toString(vec);
}
void demo_4(){
    Heap<Vector3D*> heap(&vector_compare, &Heap<Vector3D*>::free);
    Vector3D array[] = {
        Vector3D(1,2,3),
        Vector3D(3,-2,3),
        Vector3D(10,2,3),
        Vector3D(1,29,3),
        Vector3D(100,23,3),
        Vector3D(1,2,300)
    };
    int size = 6;
    for(int idx=0; idx < size; idx++){
        heap.push(new Vector3D( array[idx] ));
    }
    heap.println(&vec2str);
}


int main(int arc, char** argv){
    demo_4();
    
    return 0;
}


//Huffman encoding

/*
 Range: 0-7
 * 1bit: 2 states => 3 bits => 2^3 (states)
 data: 0, 0, 1, 0, 3, 3, 3, 2, 4, 2, 7, 2, 5, 5, 6, 6, 3, 5, 1, 1
 #bits needed for 20 items: 20 x 3 (un-compressed)
 * 
 * Compressed?? need LESS THAN 60 bits for storing 20 items above
 * 0: 3/20 = 15%
 * 1: 3/20 = 15%
 * 2: 3/20 = 15%
 * 3: 4/20 = 20%
 * 4: 1/20 = 0.05 = 5%
 * 5: 3/20 = 15%
 * 6: 2/20 = 10%
 * 7: 1/20 = 5%
 * 
 * probability mass function (pmf)
 * varying bits: 
 */     
        
