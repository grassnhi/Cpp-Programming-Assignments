#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template<class T>
struct TNode{
    T data;
    TNode<T> *left, *right;
    TNode(T data, TNode<T>* left = NULL, TNode<T>* right = NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include <math.h>
#include "list/DLinkedList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

/*
input: 10, 50, 40
After two rotations:
        40
      /   \
    10     50
So, the tree created as in create_tree_demo:
*/
TNode<int>* create_tree_demo(){
    TNode<int>* root = new TNode<int>(40);
    TNode<int>* a = new TNode<int>(10);
    TNode<int>* b = new TNode<int>(50);
    root->left = a; root->right = b;
    return root;
}
/*
create_tree:
  * create a tree from your data
*/
TNode<int>* create_tree(){
    TNode<int>* root = new TNode<int>(40);
    TNode<int>* a = new TNode<int>(10);
    TNode<int>* b = new TNode<int>(50);
    root->left = a; root->right = b;
    return root;
}

template<class T>
void delete_tree(TNode<T>*& root){
    if(root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
}

template<class T>
int height(TNode<T>* const root){
    if(root == NULL) return 0;
    int LH = height(root->left);
    int RH = height(root->right);
    return max(LH, RH) + 1;
}


template<class T>
DLinkedList<T> bfs(TNode<T>* const root){
    DLinkedList<T> result;
    if(root == NULL) return result;

    Queue<TNode<T>*> fringe;
    fringe.push(root);
    while(!fringe.empty()){
        TNode<T>* node = fringe.pop();
        result.add(node->data);
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return result;
}
template<class T>
DLinkedList<T> dfs(TNode<T>* const root){
    DLinkedList<T> result;
    if(root == NULL) return result;

    Stack<TNode<T>*> fringe;
    fringe.push(root);
    while(!fringe.empty()){
        TNode<T>* node = fringe.pop();
        result.add(node->data);
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return result;
}


int main(int argc, char** argv){
    TNode<int>* root = create_tree();
    cout << root->data << endl;
    
    DLinkedList<int> bfslist = bfs(root);
    DLinkedList<int> dfslist = dfs(root);
    bfslist.println();
    dfslist.println();
    
    return 0;
}