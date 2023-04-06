/*
Given class BinaryTree, you need to finish methods getHeight(), preOrder(), inOrder(), postOrder().

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN 
        
    // STUDENT ANSWER END
};


For example:

Test	Result
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
2
4 6 9
6 4 9
6 9 4

*/

int getHeightHelper(Node* node)
{
    if (!node)
        return 0;
    int leftHeight = getHeightHelper(node->pLeft);
    int rightHeight = getHeightHelper(node->pRight);
    return 1 + max(leftHeight, rightHeight);
}

int getHeight()
{
    return getHeightHelper(root);
}

string preOrderHelper(Node* node)
{
    if (!node)
        return "";
    ostringstream oss;
    oss << node->value << " ";
    oss << preOrderHelper(node->pLeft);
    oss << preOrderHelper(node->pRight);
    return oss.str();
}

string preOrder()
{
    return preOrderHelper(root);
}

string inOrderHelper(Node* node)
{
    if (!node)
        return "";
    ostringstream oss;
    oss << inOrderHelper(node->pLeft);
    oss << node->value << " ";
    oss << inOrderHelper(node->pRight);
    return oss.str();
}

string inOrder()
{
    return inOrderHelper(root);
}

string postOrderHelper(Node* node)
{
    if (!node)
        return "";
    ostringstream oss;
    oss << postOrderHelper(node->pLeft);
    oss << postOrderHelper(node->pRight);
    oss << node->value << " ";
    return oss.str();
}

string postOrder()
{
    return postOrderHelper(root);
}

int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}