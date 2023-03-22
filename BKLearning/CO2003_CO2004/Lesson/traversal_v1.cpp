#ifndef BST_H
#define BST_H
#include <string>
#include <sstream>

#include "tree/IBST.h"
#include "tree/ITreeWalker.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

struct TNode
{
    int key;
    TNode* left, *right;
    TNode(int key, TNode* left, TNode* right){
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

TNode* create_tree(){
    TNode* left = new TNode(30, new TNode(25), new TNode(40, NULL, new TNode(45)));
    TNode* right = new TNode(70, new TNode(65), new TNode(85));
    return new TNode(50, left, right);
}
/*            50
     30                  70
25       40          65      85
             45
*/


void NLR(TNode<int>* root){  // pre-order
    if(root == NULL)   return;
    cout << root->key << ",";
    NLR(root->left);
    NLR(root->right);
}

void LNR(TNode<int>* root){  // in-order
    if(root == NULL)   return;
    LNR(root->left);
    cout << root->key << ",";
    LNR(root->right);
}

void LRN(TNode<int>* root){  // post-order
    if(root == NULL)   return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << ",";
}

void DFT(TNode<int>* root){
    if(root == NULL)    return;
    Stack<TNode<int>*> container;
    container.push(root);
    while (!container.empty())
    {
        TNode<int>* node = container.pop();
        cout << node->key << ",";
        if(node->right != NULL)     container.push(node->right);
        if(node->left != NULL)      container.push(node->left);
    }
}

void BFT(TNode<int>* root){
    if(root == NULL)    return;
    Queue<TNode<int>*> container;
    container.push(root);
    while (!container.empty())
    {
        TNode<int>* node = container.pop();
        cout << node->key << ",";
        if(node->right != NULL)     container.push(node->right);
        if(node->left != NULL)      container.push(node->left);
    }
}

void Traversal(TNode<int>* root, IDeck<TNode<int>*>& container){
    if(root == NULL)    return;
    container.push(root);
    while (!container.empty())
    {
        TNode<int>* node = container.pop();
        cout << node->key << ",";
        if(node->right != NULL)     container.push(node->right);
        if(node->left != NULL)      container.push(node->left);
    }
}

int smallest(TNode<int>* root){
    if(root == NULL)    return -1; // best way to throw exception

    TNode<int>* cursor = root;
    while(cursor->left != NULL){
        cursor = cursor->left;
    }
    return cursor->key;
}

TNode<int>* insert(TNode<int>* root, int key){
    if(root == NULL)    return new TNode<int>(key);
    TNode<int>* parent, *pWalk;

    pWalk = root;
    while (pWalk != NULL)
    {
        parent = pWalk;
        if(key < pWalk->key)    pWalk = pWalk->left;
        else                    pWalk = pWalk->right;
    }

    if(key < parent->key)   parent->left = new TNode<int>(key);
    else                    parent->right = new TNode<int>(key);
    
    return root;
}

void demo_1(){
    TNode<int>* root = create_tree();
    cout << "NLR: "; NLR(root); cout << endl;
    cout << "LNR: "; LNR(root); cout << endl;
    cout << "LRN: "; LRN(root); cout << endl;
    cout << "DFT: "; DFT(root); cout << endl;
    cout << "BFT: "; BFT(root); cout << endl;

    Stack<TNode<int>*> stack;
    Queue<TNode<int>*> queue;
    PriorityQueue<TNode<int>*> pqueue;
    cout << "DFT: "; Traversal(root, stack); cout << endl;
    cout << "BFT: "; Traversal(root, queue); cout << endl;
    cout << "USC: "; Traversal(root, pqueue); cout << endl;
}

void demo_2(){
    BST<int, int*> bst;
    for(int v = 1; v < 100; v += 2){
        bst.add(v);
    }
    cout << bst.height() << endl;

    AVL<int, int*> avl;
    for(int v = 1; v < 100; v += 2){
        avl.add(v);
    }
    cout << avl.height() << endl;
}

void demo_3(){
    TNode<int>* root = create_tree();
    cout << "SMALLEST: " << smallest(root) << endl;
}

void demo_4(){
    TNode<int>* root = create_tree();
    BFT(root); cout << endl;

    root = insert(root, 95);
    BFT(root); cout << endl;

    root = insert(root, 87);
    BFT(root); cout << endl;

    root = insert(root, 27);
    BFT(root); cout << endl;
}

int main(){
    demo_4();
    return 0;
}