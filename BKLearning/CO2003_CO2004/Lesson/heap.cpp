#include <math.h>
#include <string>
#include <sstream>


#include "heap/Heap.h"
#include "util/Point.h"
#include "util/sampleFunc.h"

void demo_5(){
    Heap<int> minHeap;
    int priorities[] = {57, 78, 3, 14, 37, 27, 98, 5}
    minHeap.heapify(priorities, sizeof(priorities)/sizeof(int));
}
/*
                3
            5       27
        14  37   57     98
    78
*/

void demo_6(){
    Heap<int> minHeap;
    int priorities[] = {57, 78, 3, 14, 37, 27, 98, 5}
    for(int idx = 0; idx < izeof(priorities)/sizeof(int); idx++){
        minHeap.push(priorities[idx]);
    }
    minHeap.println();
}             
/*
- Right order: parent <= child
- Wrong order: parent > child
            57                                     3                            3
        78      3??? => ReHeapUp (RHU)  =>      78  57                      14      57              => ....
                                            14??    => Wrong => Swap    78     37 => Right order 

                3                                                                  3
        14              27                                                  5               27
    78      37      57      98                                          14      37      57      98
5 => wrong, move 5 up swap with 78 => still wrong => move up =>     78
*/

void demo_8(){
    Heap<int> minHeap;
    int priorities[] = {57, 5, 12, 78, 3,
                        14, 76, 55, 37, 27,
                        98, 15, 48, 33, 23};
    minHeap.heapify(priorities, sizeof(priorities)/sizeof(int));
    minHeap.println();
    minHeap.remove(12);
    minHeap.println();
}

string toString(int*& item){
    stringstream os;
    os << *item;
    return os.str();
}

int addr_comparator(int*& lhs, int*& rhs){
    if(*lhs < *rhs){
        return -1;
    }else if(*lhs > *rhs){
        return +1;
    }else{
        return 0;
    }
}

void demo_9(){
    Heap<int> minHeap(addr_comparator);
    int priorities[] = {57, 5, 12, 78, 3,
                        14, 76, 55, 37, 27,
                        98, 15, 48, 33, 23};
    for(int idx = 0; idx < sizeof(priorities)/sizeof(int); idx++){
        minHeap.push(new int(priorities[idx]));
    }
    minHeap.println(toString);
    cout << "Peek: " << *minHeap.peek() << endl;
    int* pWanted = new int(12);
    minHeap.remove(pWanted);
}

int main(){
    demo_5();
    demo_6();
    return 0;
}