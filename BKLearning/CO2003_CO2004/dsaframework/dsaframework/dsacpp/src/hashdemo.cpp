#include <iostream>
#include <iomanip>
#include "hash/XHashMap.h"
#include "util/ArrayLib.h"

using namespace std;

int hash_code(int& key, int capacity){
    //(1) uniformly distribute keys in whole address space
    //(2) Gaussian Distirbution in whole address space
    return 0;
}
void demo_1(){
    XHashMap<int, int> map(&hash_code, 0.75);
    int size = 4;
    int* ptr = genIntArray(size, 5, 200, true, 2021);
    for(int idx = 0; idx < size; idx++){
        map.put(ptr[idx], idx*ptr[idx]);
    }
    map.println();
    DLinkedList<int> clashes = map.clashes();
    clashes.println();
    
    delete []ptr;
}
int main(int argc, char** argv){
    demo_1();
    
    return 0;
}

/*
 hashing-function(key) => index (name: home address)
 * probability & statistics: uniform distribution (phan phoi deu)
 * p(v) = 1/(b-a + 1)
 * [a, b] = [0, 9]
 */

