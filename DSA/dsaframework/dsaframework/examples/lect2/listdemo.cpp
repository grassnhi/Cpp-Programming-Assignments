#include <iostream>
#include <iomanip>

#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "geom/Vector3D.h"

/*
 (1) How to use
 (2) How to implement
 */

using namespace std;

void demo_arraylist(){
    XArrayList<Vector3D> list;
    
    Vector3D points[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,3),
        Vector3D(4.5, 8.5, 4),
    };
    for(Vector3D v: points) list.add(v);
    
    list.println();
    //
    //show length of vector: time complexity is O(size)
    for(int idx=0; idx< list.size(); idx++){
        Vector3D v = list.get(idx);
        cout << v << ":\t" << v.length() << endl;
    }
    
    //time complexity is O(size)
    XArrayList<Vector3D>::Iterator it;
    for(it = list.begin(); it != list.end(); it++){
        Vector3D v = *it;
        cout << v << ":\t" << v.length() << endl;
    }
    
}

void demo_arraylist_ptr(){
    XArrayList<Vector3D*> list(XArrayList<Vector3D*>::free); //OKay
    list.add(new Vector3D(1,2,3));
    list.add(new Vector3D(3,4,3));
    list.add(new Vector3D(4.5, 8.5, 4));
    
    //Do some kinds of processing here.
    list.println(Vector3D::toString);
}

void demo_slist(){
    SLinkedList<Vector3D> list;
    Vector3D points[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,3),
        Vector3D(4.5, 8.5, 4),
    };
    for(Vector3D v: points) list.add(v);
    
    list.println();
    ////show length of vector: time complexity is O(size^2)
    for(int idx=0; idx< list.size(); idx++){
        Vector3D v = list.get(idx);
        cout << v << ":\t" << v.length() << endl;
    }
    
    //time complexity is O(size)
    SLinkedList<Vector3D>::Iterator it;
    for(it = list.begin(); it != list.end(); it++){
        Vector3D v = *it;
        cout << v << ":\t" << v.length() << endl;
    }
}
void demo_dlist(){
    DLinkedList<Vector3D> list;
    Vector3D points[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,3),
        Vector3D(4.5, 8.5, 4),
    };
    for(Vector3D v: points) list.add(v);
    
    list.println();
    
    cout << endl;
    //show length of vector: time complexity is O(size^2)
    for(int idx=0; idx< list.size(); idx++){
        Vector3D v = list.get(idx);
        cout << v << ":\t" << v.length() << endl;
    }
    
    //time complexity is O(size)
    cout << endl;
    DLinkedList<Vector3D>::Iterator it;
    for(it = list.begin(); it != list.end(); it++){
        Vector3D v = *it;
        cout << v << ":\t" << v.length() << endl;
    }
}



void demo_dlist_ptr_notgood(){
    DLinkedList<Vector3D*> list; //memory leaks
    list.add(new Vector3D(1,2,3));
    list.add(new Vector3D(3,4,3));
    list.add(new Vector3D(4.5, 8.5, 4));
    
    //Do some kinds of processing here.
    list.println(Vector3D::toString);
   
}
void demo_dlist_ptr(){
    DLinkedList<Vector3D*> list(DLinkedList<Vector3D*>::free, Vector3D::equals); //OKay
    Vector3D* points[] = {
        new Vector3D(1,2,3),
        new Vector3D(3,4,3),
        new Vector3D(4.5, 8.5, 4)
    };
    
    for(Vector3D* p: points) list.add(p);
   
    //Do some kinds of processing here.
    list.println(Vector3D::toString);
    
    
    Vector3D* removed = new Vector3D(3,4,3);
    //remove
    list.removeItem(removed);
    //print
    list.println(Vector3D::toString);
    delete removed;
   
}
int main(int argc, char** argv){
    demo_dlist_ptr();
    return 0;
}