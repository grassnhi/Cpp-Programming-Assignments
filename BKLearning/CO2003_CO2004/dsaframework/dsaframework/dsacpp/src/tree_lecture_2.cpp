#include <iostream>
#include <iomanip>
#include <sstream>
#include "tree/BST.h"
#include "tree/AVL.h"
#include "list/DLinkedList.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

using namespace std;

/*
 BST:
 * search?????
 *  bc: BST support the searching process of items fast!
 */

/*
      root->  0
               \
                1
                 \
                  2
                   \
                    3
                     \
                      4
                       \
                        5
 
 */

//time complexity: O(n^2); why? 1 + 2 + 3 + 4 + -- + n = (n-1)n/2
void demo_1(){
    BST<int, int*> bst;
    
    int size = 1e6;
    for(int key=0; key < size; key++) bst.add(key);
    cout << "height: " << bst.height() << endl;
}
void demo_2(){
    AVL<int, int*> tree;
    
    int size = 1e6;
    for(int key=0; key < size; key++) tree.add(key);
    cout << "height: " << tree.height() << endl;
}


struct TNode{
    int data;
    TNode* left, *right;
    TNode(int data, TNode* left=0, TNode* right=0){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


static int count = 0;

int height(TNode *root){
    if(root == NULL) return 0;
    int LH = height(root->left);
    int RH = height(root->right);
    return max(LH, RH) + 1;
}

int sum(TNode* root){
    count++;
    if(root== NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}
/*
    1. NULL TREE => height: 0
    2. height: 2
        50
          \ 
           60
  
    3. height:3
        50
       /  \
      30   70
     /  \
    10   40
 
root->  (100)
       /     \
    (left) (right)
 */


/**
 * Tree: is a recursive data structure
 * 
 * 
 * @return 
 */
TNode* tree1(){
    return NULL;
}

TNode* tree2(){
    TNode* root = new TNode(50, NULL, new TNode(60));
    return root;
}
TNode* tree3(){
    TNode* root= new TNode(50, 
            new TNode(30,
                new TNode(10), new TNode(40)),
            new TNode(70));
    return root;
}
int main(int arc, char** argv){
    demo_2();
    
    return 0;
}
