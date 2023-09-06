#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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
        // You have to delete all Nodes in BinaryTree. 
        removeAllNodes(root);
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
        int l = (int)posFromRoot.length();
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

    void removeAllNodes(Node* currentNode){
        if(!currentNode) return;
        
        removeAllNodes(currentNode->pLeft);
        removeAllNodes(currentNode->pRight);
        delete currentNode;
    }

    int getDiameter(){
        return computeDiameter(this->root);
    }

    int computeDiameter(Node* currentNode){
        if(!currentNode) return 0;
        
        int currentDiameter = getHeight(currentNode->pLeft) + getHeight(currentNode->pRight) + 1;
        int leftDiameter = computeDiameter(currentNode->pLeft);
        int rightDiameter = computeDiameter(currentNode->pRight);
        
        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }

    int getHeight(Node* currentNode){
        if(!currentNode) return 0;
        
        return 1 + max(getHeight(currentNode->pLeft), getHeight(currentNode->pRight));
    }

    void BFS()
    {
        if(!this->root) return;

        queue<Node*> q;
        q.push(this->root);

        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            cout << current->value << " ";

            if(current->pLeft) q.push(current->pLeft);
            if(current->pRight) q.push(current->pRight);
        }
    }

    void countTwoChildrenNodeHelper(Node* node, int& count){
        if (!node)
            return;
        countTwoChildrenNodeHelper(node->pLeft, count);
        countTwoChildrenNodeHelper(node->pRight, count);

        if (node->pLeft && node->pRight)
            count++;
    }

    int countTwoChildrenNode(){
        int count = 0;
        countTwoChildrenNodeHelper(this->root, count);
        return count;
    }

    int getHeightHelper(Node* node){
        if (!node)
            return 0;
        int leftHeight = getHeightHelper(node->pLeft);
        int rightHeight = getHeightHelper(node->pRight);
        return 1 + max(leftHeight, rightHeight);
    }

    int getHeight(){
        return getHeightHelper(root);
    }

    string preOrderHelper(Node* node){
        if (!node)
            return "";
        ostringstream oss;
        oss << node->value << " ";
        oss << preOrderHelper(node->pLeft);
        oss << preOrderHelper(node->pRight);
        return oss.str();
    }

    string preOrder(){
        return preOrderHelper(root);
    }

    string inOrderHelper(Node* node){
        if (!node)
            return "";
        ostringstream oss;
        oss << inOrderHelper(node->pLeft);
        oss << node->value << " ";
        oss << inOrderHelper(node->pRight);
        return oss.str();
    }

    string inOrder(){
        return inOrderHelper(root);
    }

    string postOrderHelper(Node* node){
        if (!node)
            return "";
        ostringstream oss;
        oss << postOrderHelper(node->pLeft);
        oss << postOrderHelper(node->pRight);
        oss << node->value << " ";
        return oss.str();
    }

    string postOrder(){
        return postOrderHelper(root);
    }

    int sumOfLeafsHelper(typename BinaryTree<K, V>::Node* node) {
        if (!node)
            return 0;

        if (!node->pLeft && !node->pRight)
            return node->value;

        int sum = 0;
        sum += sumOfLeafsHelper(node->pLeft);
        sum += sumOfLeafsHelper(node->pRight);
        return sum;
    }

    int sumOfLeafs() {
        return sumOfLeafsHelper(root);
    }

};