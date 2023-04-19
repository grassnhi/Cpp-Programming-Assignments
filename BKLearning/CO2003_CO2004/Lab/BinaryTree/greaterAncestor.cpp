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

int greatAncestor(BTNode* root);
Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the number of great ancestor nodes this binary tree has.

More information: A node of the binary tree is called as great ancestor node if its value is greater than or equal to the values of all of its descendants. Each leaf node is also a great ancestor node.

Example:

Given a binary tree in the following:

GreatAncestor

All of great ancestors nodes this binary tree has are 6, 3, 6, 4, therefore, return 4.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2};
int value[] = {6,3,2,6,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(arr[0]), value);
cout << greatAncestor(root);
4
int arr[] = {-1,0,0,2,3,3,4,5,6,4};
int value[] = {596,796,2168,148,1444,651,2279,1749,233,2008};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(arr[0]), value);
cout << greatAncestor(root);
5

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

int maxInSubtree(BTNode* node) {
    if (node == NULL) {
        return -1;
    }
    int leftMax = maxInSubtree(node->left);
    int rightMax = maxInSubtree(node->right);
    return max(node->val, max(leftMax, rightMax));
}

int greatAncestor(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    int maxInLeft = maxInSubtree(root->left);
    int maxInRight = maxInSubtree(root->right);
    int count = 0;
    if (root->val >= max(maxInLeft, maxInRight)) {
        count++;
    }
    count += greatAncestor(root->left) + greatAncestor(root->right);
    return count;
}

int main(){
    int arr[] = {-1,0,0,2,2};
    int value[] = {6,3,2,6,4};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(arr[0]), value);
    cout << greatAncestor(root);
}