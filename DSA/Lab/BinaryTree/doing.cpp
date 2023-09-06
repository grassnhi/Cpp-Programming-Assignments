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

int getHeight(BTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int longestPathSum(BTNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (leftHeight > rightHeight) {
        return root->val + longestPathSum(root->left);
    } else if (leftHeight < rightHeight) {
        return root->val + longestPathSum(root->right);
    } else {
        int leftSum = longestPathSum(root->left);
        int rightSum = longestPathSum(root->right);
        return root->val + max(leftSum, rightSum);
    }
}

int main(){
    int arr[] = {-1,0,0,2,2,3,3,5};
    int value[] = {1,5,4,7,12,4,8,2};
    int arr_size = sizeof(arr)/sizeof(int);
    BTNode* root = BTNode::createTree(arr, sizeof(arr)/sizeof(int), value);
    
    cout << longestPathSum(root); // 18
}