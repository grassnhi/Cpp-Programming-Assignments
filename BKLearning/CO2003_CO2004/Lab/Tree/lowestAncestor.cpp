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

int lowestAncestor(BTNode* root, int a, int b);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the lowest ancestor node's val of node a and node b in this binary tree (assume a and b always exist in the given binary tree).

More information:

- A node is called as the lowest ancestor node of node a and node b if node a and node b are its descendants.

- A node is also the descendant of itself.

- On the given binary tree, each node's val is distinguish from the others' val

Example:

Given a binary tree in the following:

LowestAncestor

- The lowest ancestor of node 4 and node 5 is node 2.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2,3,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 5);
2
int arr[] = {-1,0,1,1,0,4,4,2,5,6};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 9);
4

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

int lowestAncestor(BTNode* root, int a, int b) {
    if (!root) {
        return -1; // invalid input
    }
    if (root->val == a || root->val == b) {
        return root->val; // found one of the nodes at the current node
    }
    int left = lowestAncestor(root->left, a, b); // look for nodes in the left subtree
    int right = lowestAncestor(root->right, a, b); // look for nodes in the right subtree
    if (left != -1 && right != -1) {
        return root->val; // nodes found in different subtrees, so root is the lowest ancestor
    } else if (left != -1) {
        return left; // nodes found in the left subtree
    } else {
        return right; // nodes found in the right subtree
    }
}
