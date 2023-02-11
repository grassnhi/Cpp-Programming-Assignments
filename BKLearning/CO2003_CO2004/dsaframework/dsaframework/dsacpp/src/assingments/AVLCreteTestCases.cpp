#include <iostream>
#include <iomanip>
using namespace std;
#include "util/FileIOLib.h"
#include "testassignments/AVLGenTest.h"

void demo(){
    int sizes[] = {0, 5, 10, 15, 20, 50, 100, 1000, 10000, 100000};
    int nsizes = 10;
    string master_file="dat/test_avl_const.csv";
    test_avl_construction(sizes, nsizes, master_file);
    
    int ssizes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    float am_percents[] = {0.6, 0.6};
    int n_am = 2;
    master_file="dat/test_add_remove.csv";
    
    test_add_remove(ssizes, nsizes, am_percents, n_am, master_file);
}

void demo_2(){
    int size = 1000;
    int *items = genIntArray(size, -500, 500, true, 2021);
    
    AVL<int, int*> tree;
    for(int k=0; k < size; k++) tree.add(items[k], new int(items[k]));
    cout << "height: " << tree.height() << endl;
    int k=0;
    while(!tree.empty()){
        bool success = false;
        int* v = tree.remove(items[k], &success);
        if(success) delete v;
        k++;
    }
    cout << "height: " << tree.height() << endl;
    
    delete []items;
}
int main(int argc, char** argv) {
    demo();
    
    return 0;
}

