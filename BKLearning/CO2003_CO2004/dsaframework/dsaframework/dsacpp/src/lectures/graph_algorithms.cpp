#include <iostream>
#include <iomanip>
#include <string>
#include "graph/DModelZoo.h"
#include "graph/TopoSorter.h"
#include "list/DLinkedList.h"
#include "util/FuncLib.h"

using namespace std;

int hash_code(char& key, int size){
    return (int)key %size;
}
int hash_code(int& key, int size){
    return key %size;
}


void demo_topo_1(){
    IGraph<char> *model = burglary_earthquake();
    TopoSorter<char> sorter(dynamic_cast<DGraphModel<char>*>(model), &hash_code);
    DLinkedList<char> bfs = sorter.sort(TopoSorter<char>::BFS, true);
    DLinkedList<char> dfs = sorter.sort(TopoSorter<char>::DFS, true);
    bfs.println();
    dfs.println();
    
    delete model;
}

void demo_topo_2(){
    IGraph<int> *model = dag_lattice_0_9();
    TopoSorter<int> sorter(dynamic_cast<DGraphModel<int>*>(model), &hash_code);
    DLinkedList<int> bfs = sorter.bfsSort(true);
    DLinkedList<int> dfs = sorter.dfsSort(true);
    bfs.println();
    dfs.println();
    
    delete model;
}



void demo_dsaframework(){
    IGraph<string> *model = dsaframework();
    TopoSorter<string> sorter(dynamic_cast<DGraphModel<string>*>(model), &hash_murmur);
    DLinkedList<string> bfs = sorter.bfsSort(true);
    cout << "You should compile classes in the following order:" << endl;
    DLinkedList<string>::BWDIterator it;
    int i =1;
    for(it = bfs.bbegin(); it != bfs.bend(); it--){
        cout << setw(3) << i++ << ": " << *it << endl;
    }
    
    delete model;
}
int main(int arc, char** argv){
    demo_dsaframework();
    return 0;
}