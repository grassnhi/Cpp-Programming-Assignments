#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "hash/XHashMap.h"

int hash_code_1(int& key, int size){
    return key % size;
}

int hash_code_2(int key, int size){
    return key % size;
}

int hash_code_3(int& key, int size){
    return key % size + 1;
}
int hash_code_4(int key, int size){
    return key % size + 1;
}

void quiz_1(){
    XHashMap<int, int> map(&hash_code_1);
    
}
int main(int arc, char** argv){
    
}
