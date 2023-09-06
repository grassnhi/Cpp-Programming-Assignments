/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include <sstream>
using namespace std;

void demo_array_list(){
    XArrayList<int> list;
    list.add(10);
    list.add(15);
    list.add(21);
    list.println();
    list.removeAt(1);
    list.println();
}
void demo_slinked_list(){
    SLinkedList<int> list;
    list.add(10);
    list.add(15);
    list.add(21);
    list.println();
    cout << list.indexOf(21) << endl;
}
void demo_dlinked_list(){
    DLinkedList<int> list;
    list.add(10);
    list.add(15);
    list.add(21);
    list.add(24);
    list.println();
    list.removeItem(21);
    list.println();
}

string itemstr(int*& item){
    stringstream os;
    os << *item;
    return os.str();
}
void removeData(int* ptr){
    delete ptr;
}
void demo_dlinked_list_ptr(){
    DLinkedList<int*> list;
    list.add(new int(10));
    list.add(new int(15));
    list.add(new int(21));
    list.println(itemstr);
    int* key = new int(21);
    list.removeItem(key, removeData);
    delete key;
}

int __main(int argc, char** argv){
    demo_dlinked_list_ptr();
    return 0;
}