/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Lecture5A.h
 * Author: ltsach
 *
 * Created on February 19, 2025, 12:54 PM
 */

#ifndef LECTURE5A_H
#define LECTURE5A_H
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
    cout << "&count:    " << &count << endl;
    */
    
    cout << "sumel: " << sumel(array, count) << endl;
    cout << "sumel: " << sumel_recur_v1(array, count) << endl;
    cout << "sumel: " << sumel_recur_v2(array, count) << endl;
}


struct Table{
    float width, height, length;
};

struct Projector{
    string make;
    string model;
    string color; //ex: "200, 200, 200"
    float width, height, length;
};
struct Student{
    string id, name;
    int height; //ex: 175 (cm)
    
};

struct Node{
    int value;
    Node *left, *right;
};


Node* create_tree_1(){
    Node* root = new Node();
    root->value = 20;
    root->left = root->right = nullptr;
    return root;
}

Node* create_tree_2(){
    Node* sub1 = new Node();
    sub1->value = 10;
    sub1->left = sub1->right = nullptr;
    
    Node* sub2 = new Node();
    sub2->value = 30;
    sub2->left = sub2->right = nullptr;
    
    Node* root = new Node();
    root->value = 20;
    root->left = sub1;
    root->right = sub2;
    return root;
}
Node* create_tree_3(){
    Node* sub1 = new Node();
    sub1->value = 7;
    sub1->left = sub1->right = nullptr;
    
    Node* sub2 = new Node();
    sub2->value = 3;
    sub2->left = sub2->right = nullptr;
    
    Node* sub3 = new Node();
    sub3->value = 15;
    sub3->left = sub1;
    sub3->right = sub2;
    
    Node* sub4 = new Node();
    sub4->value = 5;
    sub4->left = sub4->right = nullptr;
    
    
    Node* root = new Node();
    root->value = 10;
    root->left = sub3;
    root->right = sub4;
    
    return root;
    
}

Node create_node(int value,
        Node* left=nullptr, 
        Node* right=nullptr){
    Node* node = Node();
    node->value = value;
    node->left = left;
    node->right = right;
    
}
Node* create_tree_3v2(){
    Node *sub1 = create_node(7);
    Node *sub2 = create_node(3);
    Node *sub3 = create_node(15, sub1, sub2);
    Node *sub4 = create_node(5);
    Node *root = create_node(10, sub3, sub4);
    return root;
}

#endif /* LECTURE5A_H */

