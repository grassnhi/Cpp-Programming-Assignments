#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include "list/SLinkedList.h"
#include "geom/Vector3D.h"

using namespace std;


void demo_array_list(){
    XArrayList<Vector3D> list;
    Vector3D data[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,5),
        Vector3D(2,3,4)
    };
    for(Vector3D v: data) list.add(v);
    list.println();
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D vec = list.get(idx);
        cout << vec << ":\t" << vec.length() << endl;
    }
}
void demo_array_list_ptr(){
    XArrayList<Vector3D*> list(XArrayList<Vector3D*>::free);
    list.add(new Vector3D(1,2,3));
    list.add(new Vector3D(3,4,5));
    list.add(new Vector3D(2,3,4));
    list.println(Vector3D::toString);
    
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D* pvec = list.get(idx);
        cout << *pvec << ":\t" << pvec->length() << endl;
    }
}

void demo_slinked_list(){
    SLinkedList<Vector3D> list;
    Vector3D data[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,5),
        Vector3D(2,3,4)
    };
    for(Vector3D v: data) list.add(v);
    list.println();
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D vec = list.get(idx);
        cout << vec << ":\t" << vec.length() << endl;
    }
}
void demo_slinked_list_ptr(){
    SLinkedList<Vector3D*> list(SLinkedList<Vector3D*>::free);
    list.add(new Vector3D(1,2,3));
    list.add(new Vector3D(3,4,5));
    list.add(new Vector3D(2,3,4));
    list.println(Vector3D::toString);
    
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D* pvec = list.get(idx);
        cout << *pvec << ":\t" << pvec->length() << endl;
    }
}

void demo_dlinked_list(){
    DLinkedList<Vector3D> list;
    Vector3D data[] = {
        Vector3D(1,2,3),
        Vector3D(3,4,5),
        Vector3D(2,3,4)
    };
    for(Vector3D v: data) list.add(v);
    list.println();
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D vec = list.get(idx);
        cout << vec << ":\t" << vec.length() << endl;
    }
}
void demo_dlinked_list_ptr(){
    DLinkedList<Vector3D*> list(DLinkedList<Vector3D*>::free);
    list.add(new Vector3D(1,2,3));
    list.add(new Vector3D(3,4,5));
    list.add(new Vector3D(2,3,4));
    list.println(Vector3D::toString);
    
    //
    for(int idx=0; idx < list.size(); idx++){
        Vector3D* pvec = list.get(idx);
        cout << *pvec << ":\t" << pvec->length() << endl;
    }
}

int main(int argc, char** argv){
    demo_array_list();
    demo_array_list_ptr();
    demo_slinked_list();
    demo_slinked_list_ptr();
    demo_dlinked_list();
    demo_dlinked_list_ptr();
}