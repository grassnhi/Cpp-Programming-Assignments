/*
Class BTNode is used to store a node in binary tree, described on the following:

                
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};              
                
            
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.

Request: Implement function:

int distinctParities(BTNode* root);
Where root is the root node of given binary tree (this tree has between 0 and 100000 elements). This function returns the number of P-nodes the binary tree has.

More information: A node is called as P-node if it satisfies these following rules:

- It has exactly 2 children.

- The sum of a subtree of this node is even, while the sum of the other subtree of this node is odd.

Example:

Given a binary tree in the following:

distinctParities

The number of P-nodes of this binary tree is 2, they are nodes 1 and 3.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2};
int value[] = {1,5,3,4,7};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << distinctParities(root);
2
int arr[] = {-1,0,0,1,2,2,3,3,7,1};
int value[] = {13,11,22,19,2,23,26,16,22,23};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << distinctParities(root);
1
*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 

        static BTNode* createTree(int arr[], int size, int value[]) {
            // Create an empty array of nodes to hold each node in the tree
            BTNode* nodes[size];
            
            // Iterate over the array of node values and create a new node for each value
            for (int i = 0; i < size; i++) {
                nodes[i] = new BTNode(value[i]);
            }
            
            // Iterate over the array of parent indices and assign each node as the child of its parent
            for (int i = 0; i < size; i++) {
                if (arr[i] == -1) {
                    // This is the root node
                    continue;
                }
                
                if (nodes[arr[i]]->left == NULL) {
                    nodes[arr[i]]->left = nodes[i];
                } else {
                    nodes[arr[i]]->right = nodes[i];
                }
            }
            
            // Return the root node of the tree
            return nodes[0];
        }

        void printTree() {
            if (this == NULL) {
                return;
            }
            
            this->left->printTree();
            cout << this->val << " ";
            this->right->printTree();
        }
};   

int sumSubtree(BTNode* root){
    if(root == nullptr){
        return 0;
    }
    return root->val + sumSubtree(root->left) + sumSubtree(root->right);
}

int distinctParities(BTNode* root) {
    if(root == nullptr){
        return 0;
    }
    int count = 0;
    if(root->left && root->right){
        int leftSum = sumSubtree(root->left);
        int rightSum = sumSubtree(root->right);
        if((leftSum % 2 == 0 && rightSum % 2 != 0) ||
            (leftSum % 2 != 0 && rightSum % 2 == 0)){
                count++;
        }
    }
    count += distinctParities(root->left);
    count += distinctParities(root->right);
    return count;
}

int main(){
    int arr[] = {-1,0,0,2,2,3,3,5};
    int value[] = {1,5,4,7,12,4,8,2};
    int arr_size = sizeof(arr)/sizeof(int);
    BTNode* root = BTNode::createTree(arr, arr_size, value);
    root->printTree();
    cout << distinctParities(root);
}