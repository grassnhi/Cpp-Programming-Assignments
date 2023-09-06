
#include <iostream>
#include <iomanip>

#include "hash/XHashMap.h"
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"

#include "util/ArrayLib.h"
#include "util/FuncLib.h"
#include <sstream>
using namespace std;

int hash_function(int& key, int size){
    //simple: bc key is already integer
    return key % size;
}

XHashMap<int,string> create_map(){
    XHashMap<int,string> map(hash_function);
    int keys[]      = {1,       2,      3};
    string values[] = {"one",   "two",  "three"};
    
    for(int idx=0; idx < 3; idx++) map.put(keys[idx], values[idx]);
    //
    return map;
}

void demo_map(){
     XHashMap<int,string> map = create_map();
     map.println(); //for debuging
     cout << map.get(1) << endl; //expectation:  "one"
     cout << map.get(2) << endl; //expectation:  "two"
}

bool vertexEQ(int& v1, int& v2){
    return v1 == v2;
}

string vertex2str(int& v){
    stringstream os;
    os << v;
    return os.str();
}


DGraphModel<int>* create_graph(){
    DGraphModel<int>* graph = new DGraphModel<int>(vertexEQ, vertex2str);
    //(1) add vertices
    for(int v=0; v < 4; v++) graph->add(v);
    //(2) add edges
    int from[]  = {0, 0, 1, 1, 3, 3, 3};
    int to[]    = {1, 2, 2, 3, 0, 1, 2};
    for(int idx=0; idx<7; idx++) graph->connect(from[idx], to[idx]);
    
    return graph;
}

void show_info(DGraphModel<int>* graph){
    //list of vertices:
    //Traverse on list of vertices of graph:
    DGraphModel<int>::Iterator it;
    cout    << setw(12) << "Vertex" 
            << setw(4) << "InDeg"
            << setw(4) << "OutDeg"
            << setw(4) << "Inward edges" << endl;
            
    for(it = graph->begin(); it != graph->end(); it++){
        int vertex = *it; // de-reference => type T (int)
        DLinkedList<int> inList = graph->getInwardEdges(vertex);
        cout    << setw(12) << vertex  
                << setw(4) << graph->inDegree(vertex)
                << setw(4) << graph->outDegree(vertex)
                << setw(4) << inList.toString() << endl;
    }
    
}
void demo_graph(){
    DGraphModel<int>* graph = create_graph();
    show_info(graph);
    delete graph;
}

int main(int argc, char** argv){
    cout << "Lecture 5 " << endl;
    demo_graph();
    
    return 0;
}

string itemstr(int*& item){
    stringstream os;
    os << *item;
    return os.str();
}
void removeData(int* ptr){
    delete ptr;
}
