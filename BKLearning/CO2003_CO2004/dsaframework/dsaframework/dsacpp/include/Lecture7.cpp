
#include <iostream>
#include <iomanip>
#include "graph/DGraphModel.h"
#include "graph/UGraphModel.h"
#include "list/DLinkedList.h"
#include "graph/TopoSorter.h"
#include "graph/DModelZoo.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "hash/XHashMap.h"

using namespace std;


bool vertex_EQ(char& lhs, char& rhs){
    return lhs==rhs;
}
string vertex_2str(char& v){
    stringstream os;
    os << v;
    return os.str();
}

void DGraphDemo_1(){
    DGraphModel<char> graph(vertex_EQ, vertex_2str);
    
    char vertices[] = {'A', 'B', 'C', 'D'};
    char from[] = {'A', 'A', 'B', 'D'};
    char to[]   = {'B', 'D', 'C', 'B'};
    
    for(int idx=0; idx < 4; idx++) 
        graph.add(vertices[idx]);
    for(int idx=0; idx < 4; idx++) 
        graph.connect(from[idx], to[idx]);
    
    //
    graph.println();
}

bool vertex_EQ(int& lhs, int& rhs){
    return lhs==rhs;
}
string vertex_2str(int& v){
    stringstream os;
    os << v;
    return os.str();
}

DGraphModel<int>* create_network(){
    DGraphModel<int>* graph = new DGraphModel<int>(vertex_EQ, vertex_2str);
    
    int from[] = {0, 1, 4, 4};
    int to[]   = {4, 4, 3, 2};
    
    for(int vidx=0; vidx < 5; vidx++) graph->add(vidx);
    for(int idx=0; idx < 4; idx++) graph->connect(from[idx], to[idx]);
    
    return graph;
}

int most_influential_person(DGraphModel<int>* graph){
    DLinkedList<int> vlist = graph->vertices();
    DLinkedList<int>::Iterator it;
    
    int largest = -1;
    int mip = -1;
    for(it = vlist.begin(); it != vlist.end(); it++){
        int vertex = *it;
        int indeg = graph->inDegree(vertex);
        if (indeg > largest){
            largest = indeg;
            mip = vertex;
        }
    }
    return mip;
}

int most_influential_person_V2(DGraphModel<int>* graph){
    DGraphModel<int>::Iterator it;
    
    int largest = -1;
    int mip = -1;
    for(it = graph->begin(); it != graph->end(); it++){
        int vertex = *it;
        int indeg = graph->inDegree(vertex);
        if (indeg > largest){
            largest = indeg;
            mip = vertex;
        }
    }
    return mip;
}

void demo_mip(){
    DGraphModel<int>* graph = create_network();
    int mip = most_influential_person_V2(graph);
    cout << "MIP: " << mip << endl;
    
    delete graph;
}


DGraphModel<string> * dsa_modules(){
    string vertices[] = {
        "SortAlgorithm",
        "List",
        "Heap",
        "StackQueue",
        "Tree",
        "Hash",
        "Graph"
    };
    Edge<string> edges[] = {
        Edge<string>("SortAlgorithm", "Heap"),
        Edge<string>("List", "SortAlgorithm"),
        Edge<string>("StackQueue", "List"),
        Edge<string>("StackQueue", "Heap"),
        Edge<string>("Tree", "List"),
        Edge<string>("Tree", "StackQueue"),
        Edge<string>("Hash", "List"),
        Edge<string>("Graph", "List"),
        Edge<string>("Graph", "StackQueue"),
        Edge<string>("Graph", "Hash"),
       
    };
    return DGraphModel<string>::create(
            vertices, 7,
            edges, 10,
            &vertexEQ, &vertex2str);
}
int hash_simple(string& key, int size){
    int sum =0;
    for(int idx=0; idx < key.length(); idx++)
        sum += key[idx];
    return sum%size;
}

void compile(string modulename){
    cout << "Compiling: " << modulename << "... Done" << endl;
}

void demo_topo(){
    DGraphModel<string> *graph = dsa_modules();
    //cout << graph->toString() << endl;
    
    TopoSorter<string> sorter(graph, hash_simple);
    DLinkedList<string> topo = sorter.sort();
    DLinkedList<string>::BWDIterator it;
    for(it = topo.bbegin(); it != topo.bend(); it--){
        string name = *it;
        compile(name);
    }
}

IGraph<int>* create_graph(){
    UGraphModel<int> * graph = new UGraphModel<int>(vertex_EQ, vertex_2str);
    for(int v=0; v < 9; v++) graph->add(v);
    int from[]  = {0, 0, 0, 1, 1, 2, 4, 5, 5, 6};
    int to[]    = {1, 4, 8, 2, 4, 3, 5, 6, 8, 7};
    for(int idx=0; idx < 10; idx++)
        graph->connect(from[idx], to[idx]);
    return graph;
}

void process(int vertex){
    cout << vertex << endl; //real-life task here!
}
int hash_vertex(int& vertex, int size){
    return vertex%size;
}
void demo_traversal_dft(){
    IGraph<int>* graph = create_graph();
    int start = 0, goal = 3;
    //
    Stack<int> opened;
    XHashMap<int, int> opened_map(hash_vertex);
    XHashMap<int, int> closed(hash_vertex);
    
    opened.push(start);
    opened_map.put(start, start);
    
    while(!opened.empty()){
        int current = opened.pop();
        opened_map.remove(current);
        
        //process current
        process(current); 
        //to closed
        closed.put(current, current);
        
        // hit goal => stop
        if(current == goal) break; 
        
        //generate children + push all to opened
        DLinkedList<int> children = graph->getOutwardEdges(current);
        DLinkedList<int>::Iterator it;
        for(it = children.begin(); it != children.end(); it++){
            int child = *it;
            if(closed.containsKey(child)) continue;
            if(opened_map.containsKey(child)){
                // child in opened => to be processed
                opened.remove(child);
                opened.push(child);
            }
            else{
                // child not in opened
                opened.push(child);
                opened_map.put(child, child);
            }
        }
    }
    
    delete graph;
}

void demo_traversal_bft(){
    IGraph<int>* graph = create_graph();
    int start = 0, goal = 3;
    //
    Queue<int> opened;
    XHashMap<int, int> opened_map(hash_vertex);
    XHashMap<int, int> closed(hash_vertex);
    
    opened.push(start);
    opened_map.put(start, start);
    
    while(!opened.empty()){
        int current = opened.pop();
        opened_map.remove(current);
        
        //process current
        process(current); 
        //to closed
        closed.put(current, current);
        
        // hit goal => stop
        if(current == goal) break; 
        
        //generate children + push all to opened
        DLinkedList<int> children = graph->getOutwardEdges(current);
        DLinkedList<int>::Iterator it;
        for(it = children.begin(); it != children.end(); it++){
            int child = *it;
            if(closed.containsKey(child)) continue;
            if(opened_map.containsKey(child)){
                // child in opened => to be processed
               
            }
            else{
                // child not in opened
                opened.push(child);
                opened_map.put(child, child);
            }
        }
    }
    
    delete graph;
}


int main(int argc, char** argv){
    demo_topo();
    
    return 0;
}