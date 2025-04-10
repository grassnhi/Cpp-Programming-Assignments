/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture2B.h
 * Author: ltsach
 *
 * Created on January 15, 2025, 2:52 PM
 */

#ifndef LECTURE2B_H
#define LECTURE2B_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream

using namespace std;

void array_demo_1(){
    int a[5] = {20, 25, 50};
    cout << "Address:" << endl;
    cout << "a:     " << a << endl;
    cout << "&a[0]: " << &a[0] << endl;
    cout << "&a[1]: " << &a[1] << endl;
    cout << "&a[2]: " << &a[2] << endl;
    cout << "&a[3]: " << &a[3] << endl;
    cout << "&a[4]: " << &a[4] << endl;
    //cout << "&a[5]: " << &a[5] << endl; //DO NOT USE THIS
    
    cout << endl;
    cout << "Values:" << endl;
    cout << "a[0]: " << a[0] << endl;
    cout << "a[1]: " << a[1] << endl;
    cout << "a[2]: " << a[2] << endl;
    cout << "a[3]: " << a[3] << endl;
    cout << "a[4]: " << a[4] << endl;
    
    cout << endl;
    a[0] = 99;
    cout << "a[0]: " << a[0] << endl;
    
    a[0] += 1;
    cout << "a[0]: " << a[0] << endl;
}

void array_demo_2(){
    const int size = 10;
    int values[size];
    //assignments
    for(int idx=0; idx<size; idx++){
        values[idx] = idx;
    }
    
    //process:
    int sum=0;
    for(int idx=0; idx<size; idx++){
        sum += values[idx];
    }
    //output
    cout << "sum: " << sum << endl;
}


/*
 * NOTE: Array = address = pointer
 * array[k] === *(array + k)
 */
void array_demo_3(){
    const int size = 10;
    int values[size];
    //assignments
    for(int idx=0; idx<size; idx++){
        *(values + idx ) = idx;
    }
    
    //process:
    int sum=0;
    for(int idx=0; idx<size; idx++){
        sum += *(values + idx );
    }
    //output
    cout << "sum: " << sum << endl;
}

/**
 * Object "list" of type "vector"
 *  containt:
 *      (1) data
 *      (2) methods
 * 
 */
void array_demo_4(){ 
    vector<int> list = {20, 25, 50};
    
    cout << "num. of items: " << list.size() << endl;
    
    //Method (1)
    for(int idx=0; idx < list.size(); idx++){
        cout << list[idx]  << ",";
    }
    cout << endl;
    
    //Method (2): foreach ..
    for(auto e: list){
        cout << e  << ",";
    }
    cout << endl;
}

void array_demo_5(){ 
    int v[] = {10, 40, 20, 35, 65};
    for(auto e: v){
        cout << e  << ",";
    }
    cout << endl;
}
void string_demo_1(){
    string name = "HCM City University of Technology";
    string s; //empty string
    string s1= "";
    
    cout << "empty: " << s << endl;
    cout << "name: " << name << endl;
}

void string_demo_2(){
    string s1 = "CSE", s2 = "HCMUT", s3 = "VNU-HCMC";
    string s = s1 + string("@") + s2 + ", " + s3;
    cout << s << endl;
    cout << "length: " << s.size() << endl;
    cout << "length: " << s.length() << endl;
    
}

/*
 * NOTES:
 * number to string API: to_string
 
 */
void string_demo_3(){
    string s="";
    float values[]={1.5f, 3.5f, 1.25f};
    for(auto e: values){
        s += to_string(e) + ", ";
    }
    cout << s << endl;
}

void string_demo_4(){
    string s1 = "A";
    string s2 = "A";
    
    cout << "s1.compare(s2):" <<
            s1.compare(s2) << endl;
}
void string_demo_5(){
    string s1 = "A";
    string s2 = "a";
    
    cout << "s1.compare(s2):" <<
            s1.compare(s2) << endl;
}
void string_demo_6(){
    string s1 = "A";
    string s2 = "Ad";
    
    cout << "s1.compare(s2):" <<
            s1.compare(s2) << endl;
}

void string_demo_7(){
    string s = "ABCDEFGHIABCDE";
    for(int idx=0; idx < s.length(); idx ++){
        cout << setw(3) << left << idx;
    }
    cout << endl;
    for(int idx=0; idx < s.length(); idx ++){
        cout << setw(3) << left << s[idx];
    }
    cout << endl;
    
    cout << "POS of DE (fwd)" << s.find("DE") << endl;
    cout << "POS of DE (bwd)" << s.rfind("DE") << endl;
    
    cout << ".substr(4, 5): " << s.substr(4, 5) << endl;
}

/*
 others to string
 */
void string_demo_8(){
    stringstream os;
    
    os << 123.5f << ", " << 35*3 << endl;
    
    string out = os.str();
    cout << out << endl;
}

void string_demo_9(){
    int values[] = {10, 20, 30, 50}; 
    //tostring: [10, 20, 30, 50]
    
    stringstream os;
    int size = sizeof(values)/sizeof(int); //4
    
    for(auto v: values){
        os << v << ", "; //insertion operator
    }; //10, 20, 30, 50,
    string str = os.str();
    cout << "intermediate: " << str << endl;
    
    if(size > 0){
        str = str.substr(0, str.rfind(","));
    }
    str = "[" + str + "]";
    cout << str << endl;
}

void string_demo_10(){
    string s="123.4 454";
    stringstream os(s);
    float f1, f2;
    os >> f1 >> f2 ; //extraction operator
    cout << f1 << ", " << f2 << endl;
}

///////////////////////////////
typedef unsigned char  uint8;
struct Student{
    string id;
    string name;
    string email;
    uint8 height; //in cm
};

struct Table{
    float height, width, length;
    uint8 color[3]; //RGB
};
struct Point3D{
    float x, y, z;
};



void struct_demo_1(){
    cout << "sizeof Table: " << sizeof(Table) << endl;
    cout << "sizeof Point3D: " << sizeof(Point3D) << endl;
}

/*
 * Two methods:
 * (1)
 */
void struct_demo_2(){
    Table t;
    t.height = 80; //cm
    t.length = 120; 
    t.width = 45; 
    t.color[0] = 255;
    t.color[1] = 120;
    t.color[2] = 200;
    
    cout << "height: " << t.height << endl;
}

/*
 * Two methods:
 * (2)
 */
void struct_demo_3(){
    Table *t = new Table();
    t->height = 80; //cm
    t->length = 120; 
    t->width = 45; 
    t->color[0] = 255;
    t->color[1] = 120;
    t->color[2] = 200;
    
    cout << "height: " << t->height << endl;
    
    delete t; //
}

void struct_demo_4(){
    Point3D p = {1.5f, 4.5f, 5.0f};
    cout << p.x << ", " << p.y << "," << p.z << endl;
    
}

void struct_demo_5(){
    Point3D p[]={
        {1.5f, 4.5f, 5.0f}, 
        {10.5f, 40.5f, 50.0f},
        {5.5f, 7.5f, 9.0f},
        {15.5f, 17.5f, 19.0f}
    };
    cout << p[0].x << ", " << p[0].y << "," << p[0].z << endl;
    
}
#endif /* LECTURE2B_H */

