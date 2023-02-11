#include <iostream>
#include <iomanip>
#include <string>
#include "sorting/BubbleSort.h"
#include "sorting/HeapSort.h"
#include "sorting/ISort.h"
#include "sorting/DLinkedListSE.h"
#include "sorting/QuickSort.h"
#include "sorting/SLinkedListSE.h"
#include "sorting/ShellSort.h"
#include "sorting/StraightInsertionSort.h"
#include "sorting/StraightSelectionSort.h"
#include "sorting/XArrayListSE.h"
#include "geom/Vector3D.h"


using namespace std;


void quiz_11(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    XArrayListSE<int> list;
    for(int item: array) list.add(item);
    list.sort();
    list.println();    
}
void quiz_12(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    SLinkedListSE<int> list;
    for(int item: array) list.add(item);
    list.sort();
    list.println();    
}
void quiz_13(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    DLinkedListSE<int> list;
    for(int item: array) list.add(item);
    list.sort();
    list.println();    
}
void quiz_14(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    IList<int>* list = new XArrayListSE<int>();
    for(int item: array) list->add(item);
    dynamic_cast<XArrayListSE<int>*>(list)->sort();
    dynamic_cast<XArrayListSE<int>*>(list)->println();    
    delete list;
}

int comparator1(int& a, int& b){
    if (a < b) return -1;
    else if (a > b) return +1;
    else return 0;
}
int comparator2(int& a, int& b){
    if (a < b) return +1;
    else if (a > b) return -1;
    else return 0;
}
void quiz_21(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    XArrayListSE<int> list;
    for(int item: array) list.add(item);
    list.sort(&comparator1);
    list.println();
}
void quiz_22(){
    int array[] = {10, 2, 100, 20, 80, 40, 15, 55};
    XArrayListSE<int> list;
    for(int item: array) list.add(item);
    list.sort(&comparator2);
    list.println();
}

int main(int arc, char** argv){
   quiz_11(); 
   quiz_12();
   quiz_13();
   quiz_14();
   quiz_21();
   quiz_22();
}
