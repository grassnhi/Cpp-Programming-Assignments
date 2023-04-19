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

int secondDeepest(BTNode* root);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the depth of the second deepest leaf/leaves of the tree (if there is no leaf satisfying, return -1).

More information:

- The root has a depth of 0.

- In a binary tree, the second deepest leaf's/leaves' depth is smaller than the deepest leaf/leaves's depth and higher than the others' depth.

Example:

Given a binary tree in the following:

SecondDeepest

The second deepest leaf is node 2, the depth of node 2 is 1; therefore, the function returns 1.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2,3,4};
int value[] = {1,2,3,4,5,6,7};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << secondDeepest(root);
1
int arr[] = {-1,0,1,2,3,4,5,6,7,8};
int value[] = {1,2,3,4,5,6,7,8,9,10};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << secondDeepest(root);
-1

*/

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

int secondDeepest(BTNode* root) {
    if (!root) {
        return -1; // empty tree
    }
    
    queue<pair<BTNode*, int>> q; // pair of node and depth
    q.push({root, 0});
    int deepest = -1, secondDeepest = -1;
    
    while (!q.empty()) {
        BTNode* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (!node->left && !node->right) {
            if (depth > deepest) {
                secondDeepest = deepest;
                deepest = depth;
            } else if (depth > secondDeepest && depth < deepest) {
                secondDeepest = depth;
            }
        }
        
        if (node->left) {
            q.push({node->left, depth + 1});
        }
        
        if (node->right) {
            q.push({node->right, depth + 1});
        }
    }
    
    return secondDeepest;
}