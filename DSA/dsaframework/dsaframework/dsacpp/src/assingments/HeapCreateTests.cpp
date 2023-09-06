/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapCreateTests.cpp
 * Author: ltsach
 *
 * Created on July 8, 2021, 5:39 PM
 */

#include <iostream>
#include <iomanip>
#include "testassignments/HeapGenTest.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int sizes[] = {0, 5, 10, 15, 20, 50, 100, 1000, 10000, 100000};
    int nsizes = 10;
    
    string master_file="heap_dat/heap_tests.csv";
    create_heap_tests(sizes, nsizes, master_file);
    
    cout << "Create tests: Done" << endl;
    return 0;
}

