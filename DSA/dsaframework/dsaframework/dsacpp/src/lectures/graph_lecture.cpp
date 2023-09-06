#include <iostream>
#include <iomanip>
#include <string>
#include "geom/Vector3D.h"
#include "graph/IGraph.h"
#include "graph/UGraphModel.h"
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/PriorityQueue.h"
#include "hash/XHashMap.h"
#include "sorting/DLinkedListSE.h"
#include "graph/DModelZoo.h"
#include "graph/TopoSorter.h"
#include "util/FuncLib.h"

using namespace std;

////////////////

void demo_1(){
    UGraphModel<char> model(&vertexEQ, &vertex2str);
    char vertices[] = {A, B, C, D, F};
    Edge<char> edges[] = {
        Edge<char>(A, B, 100),
        Edge<char>(B, D, 200),
        Edge<char>(C, D, 400),
        Edge<char>(F, D, 500)
    };
    for(char v: vertices) model.add(v);
    for(Edge<char> e: edges) model.connect(e.from, e.to, e.weight);
    for(char v: vertices){
        cout << v 
             << ":"  << model.inDegree(v) 
             << "\t" << model.outDegree(v) << endl;
    }
    
    for(char v: vertices){
        DLinkedList<char> inward = model.getInwardEdges(v);
        DLinkedList<char> outward = model.getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" <<
                outward.toString() << endl;
    }
    
    cout << model.weight(C, D) << endl;
    cout << ((model.connected(A, B)) ? "has a connection": "no connection") << endl;

    model.remove(D);
    model.println();
}

IGraph<char>* create_graph_0(){
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(F, H),
        Edge<char>(G, F),
        Edge<char>(G, H),
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

IGraph<char>* create_graph_1(){
    char vertices[] = {'A', 'X', 'G', 'H', 'P', 'E', 'Y', 'M', 'J'};
    Edge<char> edges[] = {
        Edge<char>('A', 'X'),
        Edge<char>('X', 'G'),
        Edge<char>('X', 'H'),
        Edge<char>('G', 'H'),
        Edge<char>('G', 'P'),
        Edge<char>('H', 'P'),
        Edge<char>('H', 'E'),
        Edge<char>('E', 'M'),
        Edge<char>('E', 'Y'),
        Edge<char>('Y', 'M'),
        Edge<char>('M', 'J')
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

IGraph<char>* create_graph_2(){
    char vertices[] = {S, A, B, C, D, E, F, T};
    Edge<char> edges[] = {
        Edge<char>(S, A, 2),
        Edge<char>(S, C, 4),
        Edge<char>(S, E, 1),
        Edge<char>(A, B, 5),
        Edge<char>(C, A, 2),
        Edge<char>(C, F, 3),
        Edge<char>(E, D, 2),
        Edge<char>(E, F, 3),
        Edge<char>(B, T, 3),
        Edge<char>(D, B, 5),
        Edge<char>(D, T, 2),
        Edge<char>(F, T, 1)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

IGraph<char>* create_graph_3(){
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(G, F),
        Edge<char>(G, H),
        Edge<char>(F, H)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

IGraph<char>* create_graph_4(){
    char vertices[] = {A, B, C, D, E, F, G, H, I, J, K};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(C, A),
        Edge<char>(D, A),
        Edge<char>(E, D),
        Edge<char>(F, D),
        Edge<char>(E, G),
        Edge<char>(F, G),
        Edge<char>(H, D),
        Edge<char>(I, D),
        Edge<char>(J, H),
        Edge<char>(J, I),
        Edge<char>(K, J)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}
IGraph<char>* create_graph_5(){
    char vertices[] = {A, B, C, D, E, F, G, H, I, J, K};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(C, A),
        Edge<char>(D, A),
        Edge<char>(E, D),
        Edge<char>(F, D),
        Edge<char>(E, G),
        Edge<char>(F, G),
        Edge<char>(H, D),
        Edge<char>(I, D),
        Edge<char>(J, H),
        Edge<char>(J, I),
        Edge<char>(K, J)
    };
    return UGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

void demo_2(){
    IGraph<char>* model = create_graph_0();
    cout << model->toString() << endl;
    
    DLinkedList<char> vertices = model->vertices();
    DLinkedList<char>::Iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++){
        char v = *it;
        DLinkedList<char> inward = model->getInwardEdges(v);
        DLinkedList<char> outward = model->getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" <<
                outward.toString() << endl;
    }
    
    delete model;
}
void demo_3(){
    IGraph<char>* model = create_graph_1();
    cout << model->toString() << endl;
    
    DGraphModel<char>* dmodel = dynamic_cast<DGraphModel<char>*>(model);
    DGraphModel<char>::Iterator it;
    
    for(it = dmodel->begin(); it != dmodel->end(); it++){
        char v = *it;
        DLinkedList<char> inward = dmodel->getInwardEdges(v);
        DLinkedList<char> outward = dmodel->getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" <<
                outward.toString() << endl;
    }
    
    delete model;
}

void demo_4(){
    DGraphModel<char> model(&vertexEQ, &vertex2str); 
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(F, H),
        Edge<char>(G, F),
        Edge<char>(G, H),
    };
    for(char v: vertices) model.add(v);
    for(Edge<char> e: edges) model.connect(e.from, e.to, e.weight);
    
    //
    DLinkedList<char> list = model.vertices();
    list.println();
    
    DGraphModel<char>::Iterator it;
    for(it = model.begin(); it != model.end(); it++){
        cout << *it << endl;
    }
    
    
}

int hash_code(char& key, int size){
    return (int)key % size;
}

void dft(IGraph<char>* model, char start){
    DLinkedList<char> results;
    
    Stack<char> open; //contain nodes TO BE processed in future
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclose(&hash_code); //contains vertices that have been processed
    
    open.push(start);
    inopen.put(start, start);
    
    while(!open.empty()){
        char vertex = open.pop();
        inopen.remove(vertex);
        //process
        results.add(vertex); //save it to results and then process later
        inclose.put(vertex, vertex);
        
        //generate children + push to open
        DLinkedListSE<char> children = model->getOutwardEdges(vertex);
        children.sort();
        DLinkedListSE<char>::Iterator it;
        for(it = children.begin(); it != children.end(); it++){
            char child = *it;
            if(inclose.containsKey(child)) continue;
            if(inopen.containsKey(child)){
                open.remove(child);
                open.push(child);
                continue;
            }
            
            open.push(child);
            inopen.put(child, child);
        }
    }
    
    //
    results.println();    
}


void bft(IGraph<char>* model, char start){
    DLinkedList<char> results;
    
    Queue<char> open; //contain nodes TO BE processed in future
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclose(&hash_code); //contains vertices that have been processed
    
    open.push(start);
    inopen.put(start, start);
    
    while(!open.empty()){
        char vertex = open.pop();
        inopen.remove(vertex);
        //process
        results.add(vertex); //save it to results and then process later
        inclose.put(vertex, vertex);
        
        //generate children + push to open
        DLinkedListSE<char> children = model->getOutwardEdges(vertex);
        children.sort();
        DLinkedListSE<char>::Iterator it;
        for(it = children.begin(); it != children.end(); it++){
            char child = *it;
            if(inopen.containsKey(child)) continue;
            if(inclose.containsKey(child)) continue;
            
            open.push(child);
            inopen.put(child, child);
        }
    }
    
    //
    results.println();
}

void demo_dft(){
    IGraph<char>* model = create_graph_0();
    dft(model, A);
    delete model;
}
void demo_bft(){
    IGraph<char>* model = create_graph_0();
    bft(model, A);
    delete model;
}

int hash_code(int& key, int size){
    return key % size;
}


void topo_demo(){
    IGraph<int>* model = dag_lattice_0_9();
    
    TopoSorter<int> sorter(dynamic_cast<DGraphModel<int>*>(model), &hash_code);
    DLinkedList<int> bfs = sorter.sort(TopoSorter<int>::BFS);
    cout << left << setw(15) << "Topo-order (BFS): " << bfs.toString() << endl;
    
    DLinkedList<int> dfs = sorter.sort(TopoSorter<int>::DFS);
    cout << left << setw(15) << "Topo-order (DFS): " << dfs.toString() << endl;
    
    delete model;
}

IGraph<string>* reverse_edges(IGraph<string>* graph){
    IGraph<string>* reverse = new DGraphModel<string>(&vertexEQ, &vertex2str);
    DGraphModel<string>* pgraph = dynamic_cast<DGraphModel<string>*>(graph);
    DGraphModel<string>::Iterator it;
    
    //Add vertices:
    for(it = pgraph->begin(); it != pgraph->end(); it++){
        string vertex = *it;
        reverse->add(vertex);
    }
    //Add reversed edges
    for(it = pgraph->begin(); it != pgraph->end(); it++){
        string from = *it;
        DLinkedList<string> children = pgraph->getOutwardEdges(from);
        DLinkedList<string>::Iterator lit;
        for(lit = children.begin(); lit != children.end(); lit++){
            string to = *lit;
            float weight = pgraph->weight(from, to);
            reverse->connect(to, from, weight);
        }
    }
    return reverse;
}

void dsaframework_demo(){
    IGraph<string>* dependency = dsaframework();
    IGraph<string>* model = reverse_edges(dependency);
    cout << model->toString() << endl;
    
    TopoSorter<string> sorter(dynamic_cast<DGraphModel<string>*>(model), &hash_murmur);
    DLinkedList<string> bfs = sorter.sort(TopoSorter<string>::BFS);
    DLinkedList<string>::Iterator it;
    cout << "Compilation Order:" << endl;
    int count =1;
    for(it = bfs.begin(); it != bfs.end(); it++)
        cout << setw(3) << count++ << ": " << *it << endl;
    
    //
    delete model;
    delete dependency;
}
void dsamodules_demo(){
    IGraph<string>* dependency = dsamodules();
    IGraph<string>* model = reverse_edges(dependency);
    cout << model->toString() << endl;
    
    TopoSorter<string> sorter(dynamic_cast<DGraphModel<string>*>(model), &hash_murmur);
    DLinkedList<string> bfs = sorter.sort(TopoSorter<string>::BFS);
    DLinkedList<string>::Iterator it;
    cout << "Compilation Order:" << endl;
    int count =1;
    for(it = bfs.begin(); it != bfs.end(); it++)
        cout << setw(3) << count++ << ": " << *it << endl;
    
    //
    delete model;
    delete dependency;
}

int main(int arc, char** argv){
    //dsaframework_demo();
    dsamodules_demo();
    //topo_demo();
    return 0;
}