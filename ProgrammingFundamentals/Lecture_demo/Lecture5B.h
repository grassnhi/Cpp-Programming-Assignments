/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture5B.h
 * Author: ltsach
 *
 * Created on February 19, 2025, 2:50 PM
 */

#ifndef LECTURE5B_H
#define LECTURE5B_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream> //stringstream
using namespace std;

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
    
    /*
    cout << "array:     " << array << endl; 
    cout << "&array[0]: " << &array[0] << endl; 
    cout << "&array[1]: " << &array[1] << endl; 
    */
    cout << "sumel: " << sumel(array, count) << endl;
    cout << "sumel: " << sumel_recur_v1(array, count) << endl;
    cout << "sumel: " << sumel_recur_v2(array, count) << endl;
}


struct Table{
    float width, height, lenght; //cm
    string color; //example: "200, 200, 255"
};

struct Student{
    string id, name;
    int height; // cm
};


struct Node{
    int value;
    Node* next;
};

Node* create_chain_1(){
    Node *node = new Node();
    node->value = 10;
    node->next = nullptr;
}

Node* create_chain_2(){
    Node *node = new Node();
    node->value = 15;
    node->next = nullptr;
    
    Node* head = new Node();
    head->value = 10;
    head->next = node;
    return head;
}

Node* create_chain_3(){
    Node *node = new Node();
    node->value = 20;
    node->next = nullptr;
    
    Node* node1 = new Node();
    node1->value = 15;
    node1->next = node;
    
    Node* head = new Node();
    head->value = 10;
    head->next = node1;
    
    return head;
}

Node* create_chain_4(int* ptr, int size){
    
}

void remove_chain(Node* head){
    
}

void demo_chain(){
    int array[] = {10, 15, 20, 45, 50, 60};
    int count = sizeof(array)/sizeof(int);
    Node* head = create_chain_4(array, count);
    
}
#endif /* LECTURE5B_H */

