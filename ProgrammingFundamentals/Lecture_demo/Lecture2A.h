/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture2A.h
 * Author: ltsach
 *
 * Created on January 15, 2025, 12:56 PM
 */

#ifndef LECTURE2A_H
#define LECTURE2A_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

void array_demo_1(){
    int a[5];
    cout << "a:    " << a << endl;
    cout << "&a[0]: " << &a[0] << endl;
    cout << "&a[1]: " << &a[1] << endl;
    cout << "&a[2]: " << &a[2] << endl;
    cout << "&a[3]: " << &a[3] << endl;
    cout << "&a[4]: " << &a[4] << endl;
    //cout << "&a[5]: " << &a[5] << endl; //DO NOT USE THIS
    
    cout << endl;
    cout << "a[0]: " << a[0] << endl;
    cout << "a[1]: " << a[1] << endl;
    
    cout << endl;
    a[0] = 99;
    cout << "a[0]: " << a[0] << endl;
    
    a[0] += 1;
    cout << "a[0]: " << a[0] << endl;
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

void array_demo_4(){
    const int size = 5;
    int a[size] = {10, 20, 40};
    
    cout << "a[1] = " << a[1] << endl;
    cout << "a[1] = " << *(a + 1) << endl;
    
    /*
     a[k] = *(a + k)
     */
    
}

void array_demo_5(){
    vector<int> v = {10, 15, 35, 50};
    for(auto item : v){
        cout << item << endl;
    }
    
    cout << "size: " << v.size() << endl;
    cout << "item 1: " << v[1] << endl;
}

void string_demo_1(){
    string name;
    string city = "Ho Chi Minh City";
    
    cout << "name: " << name << endl; //empty string
    cout << "city: " << city << endl;
}

void string_demo_2(){
    string name;
    string city = "Ho Chi Minh City";
    
    cout << "name: " << name << endl; //empty string
    cout << "city: " << city << endl;

    cout << "sizeof(name) " << sizeof(name) << endl;  
    cout << "sizeof(city) " << sizeof(city) << endl;  
}

void string_demo_3(){
    string city = "Ho Chi Minh City";
    cout << "length: " << city.size() << endl;
    //accessing to elements:
    //(1)
    for(int idx=0; idx < city.size(); idx++){
        cout << idx << ":" << city[idx] << endl;
    }
    cout << endl;
    
    //(2): foreach item ...
    for(auto e: city){
        cout << e << endl;
    }
    cout << endl;
    
}

void string_demo_4(){
    string s1 = "HCMUT";
    string s2 = "CSE";
    
    string full = s2 + "@" + s1;
    cout << full << endl;
    s2 += "@" + s1;
    cout << s2 << endl;
    
    s2.clear();
    cout << s2 << endl;
}

void string_demo_5(){
    string s = "This is string: find character in string from the end";
    cout << s << endl;
    cout << "POS:" << s.find("string") << endl;
    cout << "POS:" << s.rfind("string") << endl;
    cout << s.substr(s.find("string"));
}

void string_demo_6(){
               //01234567
    string ss = "ABCDEFGH";
    cout << ss << endl;
    cout << ss.substr(1, 3) << endl; //BCD
}
void string_demo_7(){
    string s1 = "A";
    string s2 = "A";
    cout << "s1.compare(s2): " << s1.compare(s2) << endl;
    
}

void string_demo_8(){
    string s1 = "a";
    string s2 = "A";
    cout << "s1.compare(s2): " << s1.compare(s2) << endl;
    
}
void string_demo_9(){
    string s1 = "A";
    string s2 = "Ab";
    cout << "s1.compare(s2): " << s1.compare(s2) << endl;
    
}

//number to string
void string_demo_10(){
    string s = to_string(1233); 
    cout << "to_string(135)" << to_string(135) << endl;
    cout << "to_string(13.5)" << to_string(13.5) << endl;
}

// string to number
void string_demo_11(){
    string s = "123.55";
    stringstream os(s);
    float f;
    
    os >> f; //extraction operator >>
    cout << "number: " << f << endl;
}
void string_demo_12(){
    stringstream os;
    os << 25.5 << " A STRING " << 64;
    
    string s = os.str();
    cout << s << endl;
}

struct Student{
    string id;
    string name;
    string email;
};

struct Point3D{
    float x, y, z;
};
struct Table{
    float width, height, length;
    unsigned char color[3]; //RGB
};

struct Some{
    char c; //1
    int d; //4
    long long data; //8
};
void struct_demo_1(){
    Student a, b;
    a.id = "1232";
    a.name = "An";
    a.email = "an@hcmut";
    
    cout << a.id << "," << a.name << endl;
}

void struct_demo_2(){
    Student* ptr = new Student();
    ptr->id = "1232";
    ptr->name = "An";
    ptr->email = "an@hcmut";
    
    cout << ptr->id << "," << ptr->name << endl;
    
    delete ptr;
}
void struct_demo_3(){
    Student a = {"123", "AN", "an@hcmut"};
    cout << a.id << "," << a.name << endl;
}

void struct_demo_4(){
    Student list[10];
    
    list[0].id = "123"; list[0].name = "AN"; 
    cout << list[0].id << "," << list[0].name<< endl;
}

void struct_demo_5(){
    Student list[10] = {
        {"123", "AN", "an@hcmut"},
        {"345", "BINH", "binh@hcmut"}
    };
    
    cout << list[0].id << "," << list[0].name<< endl;
}
    
#endif /* LECTURE2A_H */

