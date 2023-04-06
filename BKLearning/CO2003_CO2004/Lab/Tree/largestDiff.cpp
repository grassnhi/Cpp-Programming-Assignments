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

int largestDiff(BTNode* root);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the largest absolute difference between any node and its descendants.

More information: A node is also the descendant of itself.

Example:

Given a binary tree in the following:

Largest Diff

The largest absolute difference is between node 0 and node 7, therefore, return 7.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2,3,3};
int value[] = {0,4,2,1,7,6,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << largestDiff(root) << "\n";
7
int arr[] = {-1,0};
int value[] = {1,0};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << largestDiff(root) << "\n";
1
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

int largestDiff(BTNode* root) {
    if (!root) {
        return 0;
    }

    int max_diff = 0;
    stack<pair<BTNode*, pair<int, int>>> s; // stores pairs of (node, pair<min_value, max_value>)
    s.push(make_pair(root, make_pair(root->val, root->val)));

    while (!s.empty()) {
        auto p = s.top();
        s.pop();

        BTNode* node = p.first;
        int node_min = p.second.first;
        int node_max = p.second.second;

        if (node_min > node_max) {
            swap(node_min, node_max);
        }

        max_diff = max(max_diff, abs(node->val - node_min));
        max_diff = max(max_diff, abs(node->val - node_max));

        if (node->left) {
            s.push(make_pair(node->left, make_pair(min(node->val, node_min), max(node->val, node_max))));
        }
        if (node->right) {
            s.push(make_pair(node->right, make_pair(min(node->val, node_min), max(node->val, node_max))));
        }
    }

    return max_diff;
}

int main(){
    int arr[] = {-1,0,0,2,2,3,3};
    int value[] = {0,4,2,1,7,6,3};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << largestDiff(root) << "\n";
}