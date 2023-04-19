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

int maximizeProduct(BTNode* root);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the largest P which can be gotten after deleting an edge of this tree.

More information: Split the binary tree into two subtrees by deleting an edge of it. Take the sum of each subtree, P is the product of these sums.

Example:

Given a binary tree in the following:

MaximizeProduct

Cut the edge between nodes 3 and 5, the P we have is (1+2+3+4)*5=50 - it is the largest P.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2};
int value[] = {1,2,3,4,5};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(arr[0]), value);
cout << maximizeProduct(root);
50
int arr[] = {-1,0,0,1,2,1,4,4,3,3};
int value[] = {4,4,5,5,5,4,0,1,3,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(arr[0]), value);
cout << maximizeProduct(root);
285

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

int sum(BTNode* node) {
    if (node == NULL) return 0;
    return node->val + sum(node->left) + sum(node->right);
}

void dfs(BTNode* node, int& ans, int totalSum) {
    if (node == NULL) return;
    int subtreeSum = sum(node);
    ans = max(ans, (totalSum - subtreeSum) * subtreeSum);
    dfs(node->left, ans, totalSum);
    dfs(node->right, ans, totalSum);
}

int maximizeProduct(BTNode* root) {
    int totalSum = sum(root);
    int ans = 0;
    dfs(root, ans, totalSum);
    return ans;
}
