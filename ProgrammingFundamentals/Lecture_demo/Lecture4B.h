/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture4B.h
 * Author: ltsach
 *
 * Created on February 12, 2025, 2:54 PM
 */

#ifndef LECTURE4B_H
#define LECTURE4B_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

//Forward declaration
// List the header of functions:
void fa();
void fb();
void fc();
/*
header of function: int sumel(int* first, int size)
 * return type: int
 * name of function: sumel (identifier)
 * list of parameters: int* first, int size
 *      > first parameter: first, type: int*
 *      > second parameter: size, type: int
 * body of function: { ...}
 */
int sumel(int* first, int size);



void demo_func_1(){
    int array[] = {10, 3, 8, 2, 7, 20};
    int count = sizeof(array)/sizeof(int);
    
    cout << "elements:" << endl;
    for(auto v: array){
        cout << v << ", ";
    }
    cout << endl;
    cout    << "sum of elements: " 
            << sumel(array, count) << endl;
    /*
     * sumel(array, count):
     *  array, count: arguments
     */
}


void fa(){
    
}
void fb(){
    fa(); //fine
    fc(); //fail
}
void fc(){
    fa(); //fine
}



void scope_demo(){
    int a;
    {
        int a;
        char c;
        {
            char c;
            float f;
            {
                int a;
                int b;
            }
            int a;
            float g;
        };
        bool b;
    }
    double d;
}
struct Point{
    float a, b, c;
};


/*Passing method
 * 1. Passing by values
 * 2. Passing by pointers
 * 3. Passing by references
 */

/*
 * 1. Passing by values
 */
float square(float x){
    float v = x;
    x = 9999;
    return v*v;
}

/*
 * 2. Passing by pointers
 */
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
 * 3. Passing by references
 */

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


void passing_demo_1(){
    float x = 0.5;
    cout    << "(1 + x)^2: "
            << square(1 + x) << endl;
    cout    << "(1.7)^2: "
            << square(1.7) << endl;
    cout    << "x^2: "
            << square(x) << endl;
    //Error:
    //swap((1+x),6);
}
void passing_demo_2(){
    int a = 10, b = 99;
    cout << "Before calling swap: " << endl;
    cout << "a, b: " << a << ", " << b << endl;
    
    swap(&a, &b);
    
    cout << "After calling swap: " << endl;
    cout << "a, b: " << a << ", " << b << endl;
    
}

void passing_demo_3(){
    int a = 10, b = 99;
    cout << "Before calling swap: " << endl;
    cout << "a, b: " << a << ", " << b << endl;
    
    swap(a, b);
    
    cout << "After calling swap: " << endl;
    cout << "a, b: " << a << ", " << b << endl;
    
}


void func_ptr_1(){
    int a;
    int* ptr_a = &a;
    
    int (*sum)(int*, int);
    int array[] = {10, 20, 30};
    sum = sumel;
    cout << sum(array, 3) << endl;
}


float linear(float x){
    return 2*x + 1;
}

float quadratic(float x){
    return x*x + x + 1;
}
//...

void drawing(){
    float (*ptr)(float) = quadratic; //quadratic
    
    for(float x=-4; x < 5; x+=1){
        cout << x << ",\t" << ptr(x) << endl;
    }
}

// Iterative-technique
int sumel(int* first, int size){
    int sum = 0;
    for(int idx=0; idx < size; idx++){
        sum += first[idx]; //first[idx] = *(first + idx)
    }
    return sum;
}
/*
 * Stoping part:
 * Recursive part:
 */
int sumel_recur_v1(int* first, int size){
    if(size <= 0) return 0;
    return first[size-1] + sumel_recur_v1(first, size-1);
}
int sumel_recur_v2(int* first, int size){
    if(size <= 0) return 0;
    return first[0] + sumel_recur_v2(first + 1, size - 1);
}

void demo_recursive(){
    int array[] = {10, 8, 7, 2, 3, 20};
    int count = sizeof(array)/sizeof(int);
    cout << sumel(array, count) << endl;
    cout << sumel_recur_v1(array, count) << endl;
    cout << sumel_recur_v2(array, count) << endl;
    
}

#endif /* LECTURE4B_H */

