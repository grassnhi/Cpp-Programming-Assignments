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
#include "tree/AVL.h"

using namespace std;

bool vertexEQ(int& lhs, int& rhs){
    return lhs == rhs;
}
bool vertexEQ(char& lhs, char& rhs){
    return lhs == rhs;
}
string vertex2str(int& item){
    return std::to_string(item);
}
string vertex2str(char& item){
    string ret="";
    ret.push_back(item);
    return ret;
}

void quiz_1(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3};
    int to[]   = {3, 3, 4, 5};
    int nedges = 4;
    UGraphModel<int> graph(&vertexEQ, &vertex2str);
    for(int v: vertices) graph.add(v);
    for(int idx=0; idx < nedges; idx++) graph.connect(from[idx], to[idx]);
    graph.println();
}
void quiz_2(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3};
    int to[]   = {3, 3, 4, 5};
    int nedges = 4;
    DGraphModel<int> graph(&vertexEQ, &vertex2str);
    for(int v: vertices) graph.add(v);
    for(int idx=0; idx < nedges; idx++) graph.connect(from[idx], to[idx]);
    graph.println();
    
}
void quiz_3(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3};
    int to[]   = {3, 3, 4, 5};
    int nedges = 4;
    IGraph<int>* graph = new UGraphModel<int>(&vertexEQ, &vertex2str);
    for(int v: vertices) graph->add(v);
    for(int idx=0; idx < nedges; idx++) graph->connect(from[idx], to[idx]);
    dynamic_cast<UGraphModel<int>*>(graph)->println();
    cout << graph->toString() << endl;
    delete graph;
}
void quiz_4(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3};
    int to[]   = {3, 3, 4, 5};
    int nedges = 4;
    IGraph<int>* graph = new DGraphModel<int>(&vertexEQ, &vertex2str);
    for(int v: vertices) graph->add(v);
    for(int idx=0; idx < nedges; idx++) graph->connect(from[idx], to[idx]);
    dynamic_cast<UGraphModel<int>*>(graph)->println();
    delete graph;
}

void quiz_5(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3};
    int to[]   = {3, 3, 4, 5};
    int nedges = 4;
    UGraphModel<int> graph(&vertexEQ, &vertex2str);
    for(int v: vertices) graph.add(v);
    for(int idx=0; idx < nedges; idx++) graph.connect(from[idx], to[idx]);
    DLinkedList<int> list = graph.getOutwardEdges(3);
    list.println();
}

int hash_code(int& key, int size){
    return key % size;
}
int hash_code(char& key, int size){
    return (int)key % size;
}

void bft(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Queue<char> open;
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclosed(&hash_code);
    
    open.push(start);
    inopen.put(start, start);
    while(!open.empty()){
        char v = open.pop();
        inopen.remove(v);
        processedList.add(v);
        inclosed.put(v, v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort();
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.containsKey(*cit)) continue;
            
            if(!inopen.containsKey(*cit)){
                open.push(*cit);
                inopen.put(*cit,*cit);
            }
        }
    }
    processedList.println();
}



void dft(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Stack<char> open;
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclosed(&hash_code);
    
    open.push(start);
    inopen.put(start, start);
    while(!open.empty()){
        char v = open.pop();
        inopen.remove(v);
        processedList.add(v);
        inclosed.put(v, v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort();
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.containsKey(*cit)) continue;
            
            if(!inopen.containsKey(*cit)){
                open.push(*cit);
                inopen.put(*cit,*cit);
            }
            else{
                //in open
                open.remove(*cit);
                open.push(*cit); //move item on the top
            }
        }
    }
    processedList.println();
}

/////////////////
void traversal_1(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Queue<char> open;
    XHashMap<char, char> inclosed(&hash_code);
    
    open.push(start);
    while(!open.empty()){
        char v = open.pop();
        inclosed.put(v, v);
        processedList.add(v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort(); //only used for testing
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.containsKey(*cit)) continue;
            
            if(!open.contains(*cit)){
                open.push(*cit);
            }
        }
    }
    processedList.println();
}

void traversal_2(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Queue<char> open;
    DLinkedList<char> inclosed;
    
    open.push(start);
    while(!open.empty()){
        char v = open.pop();
        inclosed.add(v);
        processedList.add(v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort(); //only used for testing
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.contains(*cit)) continue;
            
            if(!open.contains(*cit)){
                open.push(*cit);
            }
        }
    }
    processedList.println();
}
void traversal_3(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Queue<char> open;
    AVL<char, char*> inclosed;
    
    open.push(start);
    while(!open.empty()){
        char v = open.pop();
        inclosed.add(v);
        processedList.add(v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort(); //only used for testing
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            bool contains=false; inclosed.search(*cit, contains);
            if(contains) continue;
            
            if(!open.contains(*cit)){
                open.push(*cit);
            }
        }
    }
    processedList.println();
}
void traversal_4(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Queue<char> open;
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclosed(&hash_code);
    
    open.push(start);
    inopen.put(start, start);
    while(!open.empty()){
        char v = open.pop();
        inopen.remove(v);
        processedList.add(v);
        inclosed.put(v, v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort(); //only used for testing
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.containsKey(*cit)) continue;
            
            if(!inopen.containsKey(*cit)){
                open.push(*cit);
                inopen.put(*cit,*cit);
            }
        }
    }
    processedList.println();
}

void traversal_5(IGraph<char>* graph, char start){
    DLinkedList<char> processedList;
    Stack<char> open;
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclosed(&hash_code);
    
    open.push(start);
    inopen.put(start, start);
    while(!open.empty()){
        char v = open.pop();
        inopen.remove(v);
        processedList.add(v);
        inclosed.put(v, v);
        
        DLinkedListSE<char> children = graph->getOutwardEdges(v);
        children.sort();
        for(DLinkedListSE<char>::Iterator cit=children.begin(); cit != children.end(); cit++){
            if(inclosed.containsKey(*cit)) continue;
            
            if(!inopen.containsKey(*cit)){
                open.push(*cit);
                inopen.put(*cit,*cit);
            }
            else{
                //in open
                open.remove(*cit);
                open.push(*cit); //move item on the top
            }
        }
    }
    processedList.println();
}

////////////////
char    A='A', B='B', C='C', D='D', E='E', \
        F='F', G='G', H='H', I='I', J='J', \
        K='K', L='L', M='M', N='N', O='O', \
        P='P', Q='Q', R='R', S='S', T='T', \
        U='U', V='V', X='X', Y='Y', Z='Z';

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
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for(char v: vertices) graph->add(v);
    for(Edge<char> edge: edges) graph->connect(edge.from, edge.to);
    return graph;
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
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for(char v: vertices) graph->add(v);
    for(Edge<char> edge: edges) graph->connect(edge.from, edge.to);
    return graph;
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
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for(char v: vertices) graph->add(v);
    for(Edge<char> edge: edges) graph->connect(edge.from, edge.to);
    return graph;
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
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for(char v: vertices) graph->add(v);
    for(Edge<char> edge: edges) graph->connect(edge.from, edge.to);
    return graph;
}
IGraph<char>* reverse_edges(IGraph<char>* graph){
    IGraph<char>* reverse = new DGraphModel<char>(&vertexEQ, &vertex2str);
    DGraphModel<char>* pgraph = dynamic_cast<DGraphModel<char>*>(graph);
    DGraphModel<char>::Iterator it;
    
    //Add vertices:
    for(it = pgraph->begin(); it != pgraph->end(); it++){
        char vertex = *it;
        reverse->add(vertex);
    }
    //Add reversed edges
    for(it = pgraph->begin(); it != pgraph->end(); it++){
        char from = *it;
        DLinkedList<char> children = pgraph->getOutwardEdges(from);
        DLinkedList<char>::Iterator lit;
        for(lit = children.begin(); lit != children.end(); lit++){
            char to = *lit;
            float weight = pgraph->weight(from, to);
            reverse->connect(to, from, weight);
        }
    }
    return reverse;
}


void demo_bft_1(){
    IGraph<char>* graph = create_graph_1();
    bft(graph, G);
    delete graph;
}
void demo_dft_1(){
    IGraph<char>* graph = create_graph_1();
    dft(graph, G);
    delete graph;
}

void demo_bft_2(){
    IGraph<char>* graph = create_graph_2();
    bft(graph, C);
    delete graph;
}
void demo_dft_2(){
    IGraph<char>* graph = create_graph_2();
    dft(graph, C);
    delete graph;
}


void demo_traversal_1(){
    IGraph<char>* graph = create_graph_2();
    traversal_1(graph, C);
    delete graph;
}
void demo_traversal_2(){
    IGraph<char>* graph = create_graph_2();
    traversal_2(graph, C);
    delete graph;
}
void demo_traversal_3(){
    IGraph<char>* graph = create_graph_2();
    traversal_3(graph, C);
    delete graph;
}
void demo_traversal_4(){
    IGraph<char>* graph = create_graph_2();
    traversal_4(graph, C);
    delete graph;
}

//[A, X, G, H, P, E, Y, M, J]
//[A, X, G, H, P, E, Y, M, J]
void demo_topo_1(){
    IGraph<char>* graph = create_graph_1();
    TopoSorter<char> sorter(dynamic_cast<DGraphModel<char>*>(graph));
    DLinkedList<char> topo = sorter.sort(TopoSorter<char>::BFS);
    topo.println();
    delete graph;
}
void demo_topo_2(){
    IGraph<char>* graph = create_graph_3();
    TopoSorter<char> sorter(dynamic_cast<DGraphModel<char>*>(graph));
    DLinkedList<char> topo = sorter.sort(TopoSorter<char>::BFS);
    topo.println();
    delete graph;
}
void demo_topo_3(){
    IGraph<char>* graph = create_graph_3();
    TopoSorter<char> sorter(dynamic_cast<DGraphModel<char>*>(graph));
    DLinkedList<char> topo = sorter.sort(TopoSorter<char>::DFS);
    topo.println();
    delete graph;
}

void demo_compilation(){
    IGraph<char>* g = create_graph_4();
    IGraph<char>* graph = reverse_edges(g);
    TopoSorter<char> sorter(dynamic_cast<DGraphModel<char>*>(graph));
    DLinkedList<char> topo = sorter.sort(TopoSorter<char>::DFS);
    topo.println();
    delete graph;
    delete g;
}


int main(int arc, char** argv){
    //demo_topo_2();
    demo_compilation();
    
}
