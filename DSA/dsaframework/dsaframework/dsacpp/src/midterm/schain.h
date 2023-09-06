/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   schain.h
 * Author: ltsach
 *
 * Created on July 15, 2021, 5:21 PM
 */

#ifndef SCHAIN_H
#define SCHAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


template<class T>
struct SNode{
    T data;
    SNode<T>* next;
    SNode(T data, SNode<T>* next=NULL){
        this->data = data;
        this->next = next;
    }
};

SNode<int>* create_schain(int* ptr, int size){
    if(size == 0) return NULL;
    SNode<int> *head = NULL;
    for(int idx=size-1; idx >=0; idx--){
        head = new SNode<int>(ptr[idx], head);
    }
    return head;
}



#endif /* SCHAIN_H */

