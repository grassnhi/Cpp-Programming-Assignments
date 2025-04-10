/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture4A.h
 * Author: ltsach
 *
 * Created on February 12, 2025, 1:00 PM
 */

#ifndef LECTURE4A_H
#define LECTURE4A_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;


//forward declaration
float sum(float, float); //no body
void fa();
void fb();
void fc();
/**
 * float: type of the return value
 * sum: function name
 * float a, float b: parameters, and its type
 * sum(float a, float b): the signature of function
 * @param a
 * @param b
 * @return 
 */

void fa(){
    cout << "fa" << endl;
    fb();
    fc();
}
void fb(){
    cout << "fb" << endl;
}
void fc(){
    cout << "fc" << endl;
}



float sum(float a, float b){
    return a + b;
}

void func_demo_1(){
    float a = 2.5, b = 4.5;
    cout << sum(a, b) << endl;
    /*
     * call sum(a, b):
     *  a, b: arguments
     */
    
    cout << sum(3.5, 3) << endl;
}

/*
 * Implementation: interative-technique
 */
int sumel(int* head, int count){
    int sum = 0;
    for(int idx=0; idx < count; idx++){
        sum += head[idx]; // head[idx] = *(head + idx)
    }
        
    return sum;
}
void func_demo_2(){
    int array[] = {5, 1, 3, 10, 45};
    int count = sizeof(array)/sizeof(int);
    cout    << "sum of elements: " 
            << sumel(array, count)
            << endl;
}

void func_demo_3(int x, int y){
    int a;
    {
        int a;
        int b;
        {
            char c;
            float f;
            {
                bool b;
                int d;
            }
            char d;
        }
        double d;
    }
    cout << "func_demo_3" << endl;
}

/*
 1. Passing by values
 * From: C Language
 */
float square(float v){
    v = 10;
    return v*v;
}
/*
 2. Passing by pointers
 * From: C Language
 */


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = *a;
}

/*
 3. Passing by reference
 * From: C++ Language
 */
void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

float quadratic(float x){
    return x*x + x + 1;
}
float linear(float x){
    return 2*x + 1;
}
void func_passing_method(){
    //1. by value
    cout << "(1+0.3)^2: " << square(1 + 0.3) << endl;
    float a = 1.5f;
    cout << "Before calling to square:" << endl;
    cout << "a: " << a << endl;
    cout << "a^2: " << square(a) << endl;
    
    cout << "After calling to square:" << endl;
    cout << "a: " << a << endl;
    cout << endl;
    
    //by pointer;
    int x = 10, y = 99;
    cout << "Before calling to swap:" << endl;
    cout << "x, y: " << x << ", " << y << endl;
    swap(&x, &y); 
    cout << "After calling to swap:" << endl;
    cout << "x, y: " << x << ", " << y << endl;
    
    //by reference;
    int c = 10, d = 99;
    cout << "Before calling to swap:" << endl;
    cout << "c, d: " << c << ", " << d << endl;
    swap(c, d); 
    cout << "After calling to swap:" << endl;
    cout << "c, d: " << c << ", " << d << endl;
    
}

void drawing(){
    float (*func)(float) = &linear; //linear
    for(int x=-4; x < 5; x+=1){
        cout    << "x, f(x):\t" 
                << x << ", "
                << func(x) << endl;
    }
    
}

/*
 * Implementation: recursive-technique
 * RECURSIVE-FUNC: alway have two parts
 * 1. Stopping
 * 2. Recursive
 */
int sumel_recur_v1(int* head, int count){
    if(count == 0) return 0;
    return head[count-1] + sumel_recur_v1(head, count -1);
}

int sumel_recur_v2(int* head, int count){
    if(count == 0) return 0;
    return head[0]+ sumel_recur_v2(head + 1, count-1);
}

void demo_recursive(){
    int array[] = {7, 10, 8, 3, 2, 20};
    int count = sizeof(array)/sizeof(int);
    
    cout << "sumel: " << sumel(array, count) << endl;
    cout << "sumel: " << sumel_recur_v1(array, count) << endl;
    cout << "sumel: " << sumel_recur_v2(array, count) << endl;
}

#endif /* LECTURE4A_H */

