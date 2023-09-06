#include <iostream>
#include <iomanip>
#include "util/ArrayLib.h"
#include "sorting/ISort.h"
#include "sorting/StraightInsertionSort.h"
#include "sorting/ShellSort.h"

using namespace std;


void demo_sorting(){
    int size = 10;
    int* ptr = genIntArray(size, -100, 100, true, 2021);
    print(ptr, size); cout << endl;
    
    StraightInsertionSort<int> sorter;
    sorter.sort(ptr, size, &SortSimpleOrder<int>::compare4Ascending);
    print(ptr, size); cout << endl;
    
    sorter.sort(ptr, size, &SortSimpleOrder<int>::compare4Desending);
    print(ptr, size); cout << endl;
}

void demo_shellsort(){
    int size = 10;
    int* ptr = genIntArray(size, -100, 100, true, 2021);
    print(ptr, size); cout << endl;
    
    int segments[] = {1, 3, 5};
    int num_phases = 3;
    ShellSort<int> sorter(segments, num_phases);
    sorter.sort(ptr, size, &SortSimpleOrder<int>::compare4Ascending);
    print(ptr, size); cout << endl;
    
    sorter.sort(ptr, size, &SortSimpleOrder<int>::compare4Desending);
    print(ptr, size); cout << endl;
}
int main(int argc, char** argv){
    demo_shellsort();
    return 0;
}

