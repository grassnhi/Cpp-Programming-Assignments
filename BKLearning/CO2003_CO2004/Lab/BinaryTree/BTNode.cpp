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

int sumDigitPath(BTNode* root) {
    if (!root) {
        return 0;
    }
    int mod = 27022001;
    int ans = 0;
    stack<pair<BTNode*, int>> stk; // stack to store pairs of nodes and their path numbers
    stk.push(make_pair(root, root->val));
    while (!stk.empty()) {
        BTNode* node = stk.top().first;
        int num = stk.top().second;
        stk.pop();
        if (!node->left && !node->right) { // leaf node, add path number to the answer
            ans = (ans + num) % mod;
            continue;
        }
        if (node->left) {
            stk.push(make_pair(node->left, (num * 10 + node->left->val) % mod));
        }
        if (node->right) {
            stk.push(make_pair(node->right, (num * 10 + node->right->val) % mod));
        }
    }
    return ans;
}

int main(){
    int arr[] = {-1,0,0,2,2};
    int value[] = {1,5,3,4,7};
    int arr_size = sizeof(arr)/sizeof(int);
    BTNode* root = BTNode::createTree(arr, arr_size, value);
    root->printTree();
}