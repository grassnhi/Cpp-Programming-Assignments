/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture3A.h
 * Author: ltsach
 *
 * Created on February 5, 2025, 1:04 PM
 */

#ifndef LECTURE3A_H
#define LECTURE3A_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

/*
 * Pointer = Address
 */

void pointer_1(){
    int a; //a: an integer (4 bytes) 
    int *ptr;   //ptr: a pointer = address of memory block that contains integers.
                //ptr: mostly 64bits = 8bytes
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(int*): " << sizeof(int*) << endl;
    
}

struct Point3D{
    float x, y, z;
};

void pointer_2(){
    int *ptr;  
    char *pa, *pb;
    char *pa1, pb1;
    Point3D* ps;
    string *pstr;
}
void pointer_3(){
    //CASE 1: Uninitialized pointer
    int *ptr;  // undefined value!!!
    
    //CASE 2: Initialized with null-pointer
    int *ptr1 = nullptr;    //null pointer
    int *ptr2 = NULL;       //null pointer
    int *ptr3 = 0;          //null pointer
    
    int a = 100;
    //
    
    //CASE 3: Initialized with address of an integer
    int * ptr_a = &a;
    
    cout << "value of 'a': " << a << endl;
    cout << "value of 'a': " << *ptr_a << endl;
    
    
    //CASE 4: Initialized by allocating an integer
    int *ptr_dyn = new int(999);
    cout << "value of '*ptr_dyn': " << *ptr_dyn << endl;
    
    
    //CASE 5: Initialized by allocating a dynamic array
    int *ptr_dyn_arr = new int[10]; //10*4 = 40 bytes
    
    /*
     * CASE 4 + 5: NEED to deallocate
     * WHY: ptr_dyn + ptr_dyn_arr keep addresses of blocks returned by "new"
     */
    delete ptr_dyn;
    delete []ptr_dyn_arr;
}

/*
 * How to use pointer
 */
void pointer_4(){
    const int size = 5;
    
    int arr[size]; //static array
    cout << "arr: " << arr << endl;
    
    
    ////////////
    
    int* ptr = new int[size]; //dynamic array
    cout << "ptr: " << ptr << endl;
    
    //use:
    //METHOD-1: array-style
    for(int idx=0; idx < size; idx++){
        ptr[idx] = idx*idx; //assign/write
    }
    
    for(int idx=0; idx < size; idx++){
        cout << ptr[idx] << ", "; //read 
    }
    cout << endl;
    
    //METHOD-2: address-style
    /*
     ptr[idx] = *(ptr + idx)
     */
    for(int idx=0; idx < size; idx++){
        *(ptr + idx) = idx*idx; //assign/write
    }
    
    for(int idx=0; idx < size; idx++){
        cout << *(ptr + idx) << ", "; //read 
    }
    cout << endl;
    
    //
    for(int idx=size-1; idx >=0; idx--){
        cout << *(ptr + idx) << ", "; //read 
    }
    cout << endl;
    
    //
    /*
     size: 5
     ptr: 0, 1, 4, 9, 16
     
     */
    int *pend = ptr + (size-1);
    for(int idx=0; idx < size; idx++){
        cout << *(pend - idx) << ", "; //read 
    }
    cout << endl;
    
    
    //deallocate:
    delete []ptr; // the different between static vs dynamic array
}

/**
 * Operator with pointer:
 * Important ops:
 *  move-forward: +, +=
 *  move-backward: -, -=
 *  CANNOT APPLY: *, /, etc
 */
void pointer_5(){
    const int size = 5;
    int *ptr = nullptr; //initialization
    int a = 99;
    ptr = &a; //assignment
    ptr = new int[size]; //allocation
    //size: 5
    //ptr: [ITEM-0, ITEM-1, ITEM-2, ITEM-3, ITEM-4]
    //      ^
    
    int* temp = ptr + 4; //ADD: move-forward 4 items
    temp - 2; // move-backward 2 items => address of ITEM-2
    
    temp -= 2; //move-backward 2 items and do assignments
    
    
    
    delete []ptr; //deallocation
}

void pointer_pointer(){
    int *ptr1;  //LEFT SIDE of "ptr1": int*; so, ptr1: array of integers
    int * * ptr2; 
    /* WHAT?, LEFT SIDE of "ptr2": int**
     * ((int *) *) ptr2;
     * (E *) ptr2; => ptr2: array of E
     *  E: (int *) => ptr2: array of array of integer
     */
    
   
    
    int ***ptr3; //WHAT?
    int ****ptr4; //WHAT?
    
}
void pointer_pointer_2(){
    const int size1= 5, size2= 4;
    int ** ptr;
    //allocation:
    ptr = new int*[size1];
    for(int idx=0; idx < size1; idx++){
        ptr[idx] = new int[size2];
    }
    
    //use, initialize:
    for(int i=0; i < size1; i++){
        for(int j=0; j < size2; j++){
           ptr[i][j] = i*j;
        }
    }
     //use, print:
    for(int i=0; i < size1; i++){
        for(int j=0; j < size2; j++){
           cout << ptr[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
    
    //de-allocation:
    for(int idx=0; idx < size1; idx++){
        delete []ptr[idx];
    }
    delete []ptr;
}

void pointer_in_apps_1(){
    vector<int> v = {10, 30, 45, 50};
    //vector<int>: dynamic array of integers
    
    for(auto e: v){
        cout << e << ", ";
    }
    cout << endl;
    
}

void pointer_in_apps_2(){
    string s = "computer science and engineering, hcmut, vnu-hcm";
    //string: dynamic array of characters
    
    for(auto e: s){
        cout << e << ", ";
    }
    cout << endl;
    
    cout << "sizeof(string): " << sizeof(string) << endl;
}


#endif /* LECTURE3A_H */

