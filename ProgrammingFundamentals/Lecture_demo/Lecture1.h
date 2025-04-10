/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture1.h
 * Author: ltsach
 *
 * Created on January 15, 2025, 12:56 PM
 */

#ifndef LECTURE1_H
#define LECTURE1_H
#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

void demo_1(){
    cout << "demo_1" << endl;
}
void demo_2(){
    cout << "demo_2" << endl;
}
void show_cm_args(int argc, char** argv){
    cout << "main:" << endl;
    cout << "argc:" << argc << endl << endl;
    
    for(int idx=0; idx < argc; idx++){
        cout << "argv[" << idx << "]:\t" << argv[idx] << endl;
    }
}

void datatypes_1(){
    //(A) Numerical
    // (A.1) Integer
    signed char c1, c2;
    unsigned char uc1, uc2, uc3;
    
    signed short s1, s2;
    unsigned short us1;
    
    signed int d1, d2;
    unsigned int ud1;
    
    signed long l1, l2;
    unsigned long ul1;
    
    signed long long ll;
    unsigned long long ull;
    
    cout << "sizeof(signed char): " << sizeof(signed char) << endl;
    cout << "sizeof(unsigned char): " << sizeof(unsigned char) << endl;
    
    cout << "sizeof(signed short): " << sizeof(signed short) << endl;
    cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;
    
    cout << "sizeof(signed int): " << sizeof(signed int) << endl;
    cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
    
    cout << "sizeof(signed long long): " << sizeof(signed long long) << endl;
    cout << "sizeof(unsigned long long): " << sizeof(unsigned long long) << endl;
    
    
    // (A.2) Decimal
    float f1;
    double dd1, dd2;
    
    cout << "sizeof(float): " << sizeof(float) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    
    //(B) Boolean
    bool b1, b2;
    cout << "sizeof(bool): " << sizeof(bool) << endl;
    
    //(C) Character
    
    char c = 65;
    cout << "c = " << c << endl;
    cout << "c (as int) = " << int(c) << endl;
    cout << char(c + 5) << endl;
    //(D) Array
}

void datatypes_2(){
    cout << "sizeof(uint8): " << sizeof(uint8) << endl;
    cout << "sizeof(uint16): " << sizeof(uint16) << endl;
    cout << "sizeof(uint32): " << sizeof(uint32) << endl;
}

void datatypes_3(){
    bool b1 = true, b2 = false;
    int d1 = b1, d2 = b2;
    
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
}

void const_demo(){
    int a;
    const int A = 9; //initiailized: MUST BE
    
    cout << "a = " << a << endl;
    cout << "A = " << A << endl;
}
void const_demo_2(){
   
}
void static_func(){
    static int count=0;
    count++;
    cout << "count: " << count << endl;
}

void static_demo(){
    for(int idx=0; idx < 10; idx++){
        static_func();
    }
}

void type_conversion(){
    char c = 65;
    int n = 9999;
    cout << "BEFORE:" << endl;
    cout << "c, n: " << c << n << endl;
    
    c = n;
    cout << "AFTER:" << endl;
    cout << "c, n: " << c << ", " << n << endl;
}

void array_demo_1(){
    int a[3];
    float f[5];
}

void array_demo_2(){
    int a[3] = {10, 20};
    float f[5] = {3.5f, 4.5f, 3.0f};
    
    cout << "a = " << a << endl; //array = pointer = address
    cout << "a[0] = " << a[0] << endl;
    cout << "a[1] = " << a[1] << endl;
    cout << "a[2] = " << a[2] << endl;
    
    //
    a[0] = 999;
    cout << endl;
    cout << "a[0] = " << a[0] << endl;
    cout << "a[1] = " << a[1] << endl;
    cout << "a[2] = " << a[2] << endl;
    
}

void array_demo_3(){
    int a[3] = {10, 20};
    
    cout << "&a[0] = " << &a[0] << endl;
    cout << "&a[1] = " << &a[1] << endl;
    cout << "&a[2] = " << &a[2] << endl;
    
}



#endif /* LECTURE1_H */

