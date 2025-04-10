/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture3B.h
 * Author: ltsach
 *
 * Created on February 5, 2025, 3:01 PM
 */

#ifndef LECTURE3B_H
#define LECTURE3B_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;


/*
 Pointer: a data type
 * Pointer = address of memory block
 */

void pointer_1(){
    int a; //a: a variable = name of memory block, it contains an integer
    a = 100;
    
    int *ptr;
    /* ptr: pointer
     * ptr: a variable = name of memory block, 
        it contains address of ANOTHER memory block that contains integers
     */
    
    //CASE 1: assign with null-pointer
    // null-pointer: SHOULD NOT read it
    ptr = nullptr; 
    ptr = NULL;
    ptr = 0;
    
    //CASE 2:
    ptr = &a; //ptr keeps the address of variable "a"
    
    cout << "address of a: " << &a << endl;
    cout << "address of a: " << ptr << endl;
    
    cout << "value of a: " << a << endl;
    cout << "value of a: " << *ptr << endl;
    
    cout << "sizeof a: " << sizeof(int) << endl;
    cout << "sizeof ptr: " << sizeof(int*) << endl;
    
    //delete ptr; //runtime error
}

void pointer_2(){
    int* ptr; //ptr: a pointer, it keeps an address
    
    //CASE 3: one integer
    ptr = new int(99); // allocate an integer with value 99
    
    //use ptr:
    cout << "address: " << ptr << endl;
    cout << "value  : " << *ptr << endl;
    
    delete ptr; //de-allocate, remove from heaps
    
    /*
     * Question: What happend? if without "delete"
     * Maybe with runtime error: stack overflow
     */
    
    
    //CASE 4: a dynamic array of integers
    const int size = 10;
    ptr = new int[size]; // allocate an array of 10 integers (dynamic array)
    
    //use ptr:
    
    
    delete []ptr; //de-allocate, remove from heaps
}

/*
 static array vs dynamic array
 */
void pointer_3(){
    const int size = 10;
    //static array
    int array[size] = {10, 20, 45};
    cout << "array (address): " << array << endl;
    //METHOD-1:
    for(int idx=0; idx < size; idx++){
        array[idx] = idx*idx;
    }
    
    for(int idx=0; idx < size; idx++){
        cout << array[idx] << ", ";
    }
    cout << endl;
    
    //METHOD-2:
    for(int idx=0; idx < size; idx++){
       *(array + idx) = idx+1; //array[idx] = *(array + idx)
    }
    
    for(int idx=0; idx < size; idx++){
        cout << *(array + idx) << ", ";
    }
    cout << endl;
    
    cout << endl;
    
    
    //dynamic array
    int *ptr = new int[size];
    cout << "ptr (address): " << ptr << endl;
    
     //METHOD-1:
    for(int idx=0; idx < size; idx++){
        ptr[idx] = idx*idx;
    }
    
    for(int idx=0; idx < size; idx++){
        cout << ptr[idx] << ", ";
    }
    cout << endl;    

    //METHOD-2:
    for(int idx=0; idx < size; idx++){
       *(ptr + idx) = idx+1; //ptr[idx] = *(ptr + idx)
    }
    
    for(int idx=0; idx < size; idx++){
        cout << *(ptr + idx) << ", ";
    }
    cout << endl;
    //
    delete []ptr;
}

/*
 Operators with pointers:
 move-forward: +, +=
 move-backward: -, -=
 
 */
void pointer_4(){
    const int size = 5;
    int values[]={10, 15, 45, 50, 60};
    
    int *ptr = new int[size];
    for(int idx=0; idx < size; idx++) ptr[idx] = values[idx];
    for(int idx=0; idx < size; idx++) 
        cout << ptr[idx] << ", ";
    cout << endl;
    
    int *pend = ptr + (size-1); //MOVE-FORWARD
    cout << "value at pend: " << *pend << endl;
    cout << "value at (pend-2):" << *(pend-2) << endl; //MOVE-BACKWARD
     
}


struct Point3D{
    float x, y, z;
};
void pointer_5(){
    const int size = 5;
    Point3D *table = new Point3D[size];
    table + 1; //next item, i.e, item at index 1
    table + 2; //next of next item, i.e, item at index 2
}

void pointer_6(){
    const int size = 5;
    
    //declare and allocate/initialize
    Point3D *table = new Point3D[size];
    //use:
    table[1] ; //type of table[1] is "Point3D" (struct)
    table[1].x = 0.5; table[1].y = 1.5; table[1].z = 2.5;
    
    (table + 1); //type of (table + 1) is  "Point3D*" (pointer to struct)
    //(table + 1)->x = 4.5; (table + 1)->y = 6.5; (table + 1)->z = 1.5;
    
    cout << "table[1].x     :" << table[1].x << endl; 
    cout << "(table + 1)->x :" << (table + 1)->x << endl; 
    //de-allocate
    delete []table;
    
}

void pointer_7(){
    int a;  //an integer, 4 bytes
    int* ptr1; //an adress, 8 bytes
    
    int** ptr2; //an adress, 8 bytes
    int*** ptr3; //an adress, 8 bytes
    int**** ptr4; //an adress, 8 bytes
    
}

void pointer_8(){
    const int size1=10, size2 = 5;
    int** ptr;
    //Allocation:
    ptr = new int*[size1];
    for(int idx=0; idx < size1; idx++){
        ptr[idx] = new int[size2];
    }
    
    //Use:
    for(int r=0; r < size1; r++){
        for(int c=0; c < size2; c++){
            ptr[r][c] = r * c;
        }
    }
    
    for(int r=0; r < size1; r++){
        for(int c=0; c < size2; c++){
            cout << ptr[r][c] << ", ";
        }
        cout << endl;
    }
    
    //De-Allocation:
    for(int idx=0; idx < size1; idx++){
        delete []ptr[idx];
    }
    delete []ptr;
}

void pointers_in_apps(){
    vector<int> v1;
    vector<Point3D> v2;
    string s = "computer science and engineering, hcmut, vnu-hcm";
    string s1 = "hcmut";
    cout << "sizeof vector<int>: " << sizeof(vector<int>) << endl;
    cout << "sizeof vector<Point3D>: " << sizeof(vector<Point3D>) << endl;
    cout << "sizeof s: " << sizeof(s) << endl;
    cout << "sizeof s1: " << sizeof(s1) << endl;
}
#endif /* LECTURE3B_H */

