/*
 * Lecture 6
 * Lecture 7 (12/07/2022)
 * Lecture 8 (23/07/2022)
 * 
 
 */
#include <iostream>
#include <iomanip>
#include "tree/BST.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "list/DLinkedList.h"
#include <sstream>
#include "hash/XHashMap.h"
#include "util/FuncLib.h"
#include "hash/XHashMapDemo.h"

using namespace std;
 

string valuestr(int*& item){
    stringstream os;
    os << *item;
    return os.str();
}
void demo_bst(){
    BST<int, int*> tree;
    int keys[] = {50, 20, 80, 15, 60, 90, 7, 12};
    for(int idx=0; idx <8; idx++)
        tree.add(keys[idx], new int(keys[idx]*2));
   
    //Before processing
    DLinkedList<int*> list3 = tree.ascendingList();
    list3.println(valuestr);
    
    //Processing here, now:
    DLinkedList<int*> list2 = tree.bfs();
    DLinkedList<int*>::Iterator it;
    for(it = list2.begin(); it != list2.end(); it++){
        int* value = *it;
        *value = *value + 1;
    }
    
    //After processing
    DLinkedList<int*> list = tree.ascendingList();
    list.println(valuestr);
    
    
}


struct Node{
    int data;
    Node *left, *right;
    Node(int data=0, Node* left=NULL, Node* right=NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

/*
             75
           /    \
          60     80
         /  \      \
        55  65      90
 
 */
Node* create_tree(){
    Node* left = new Node(60, new Node(55), new Node(65));
    Node* right = new Node(80, NULL, new Node(90));
    Node* root = new Node(75, left, right);
    return root;
}

void lnr(Node* root){
    if (root == NULL) return;
    lnr(root->left);
    cout << root->data << ","; //process
    lnr(root->right);
    
}

void delete_tree(Node* root){
    if(root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void dft(Node* root){
    if(root == NULL) return;
    
    Stack<Node*> container;
    container.push(root);
    while(!container.empty()){
        Node* node = container.pop();
        cout << node->data << ", "; //process, explore
        if(node->right != NULL) container.push(node->right);
        if(node->left != NULL) container.push(node->left);
    }
    cout << endl;
}
void bft(Node* root){
    if(root == NULL) return;
    
    Queue<Node*> container;
    container.push(root);
    while(!container.empty()){
        Node* node = container.pop();
        cout << node->data << ", "; //process, explore
        if(node->left != NULL) container.push(node->left);
        if(node->right != NULL) container.push(node->right);
    }
    cout << endl;
}

struct ENode{
    /*
     * YOUR CODE HERE: to define class ENode
     */
};

float eval(ENode* root){
    /*
     * YOUR CODE HERE: to evaluate the expression stored in "root"
     */
    
    return 0; //default; replaced by your statement
}

void demo(){
    Node* root = create_tree();
    cout << "Traversal by DFT: " << endl;
    dft(root);
    
    cout << "Traversal by BFT: " << endl;
    bft(root);
    delete_tree(root);
}

int hashcode(string& key, int size){
    int sum =0;
    for(int idx=0; idx < key.length(); idx++)
        sum += key[idx];
    return sum%size;
}
string country[] = {"Vietnam", "Thailand", "Japan"};//only samples
string capital[] = {"Hainoi", "Bangkok", "Tokyo"}; //only samples

XHashMap<string, string> createDS(){
    /*
     * Put your code here to create a data structure to support the task,
     *  with countries and corresponding captials are given in arrays: country and capital
     */
    XHashMap<string, string> map(hashcode);
    for(int i=0; i < 3; i++) map.put(country[i], capital[i]);
    return map;
}
string get_capital(string country, XHashMap<string, string> &map){
    /*
     * Put your code here to find the capital of the input country
     *  and return the capital 
     */
    return map.get(country);
}


void hashDemo(){
    XHashMap<string, string> map = createDS();
    map.println(); 
    string cap = get_capital("Vietnam", map);
    cout << "Vietnam => " << cap << endl;
}

int main(int argc, char** argv){
    countryDemo();
    
    return 0;
}