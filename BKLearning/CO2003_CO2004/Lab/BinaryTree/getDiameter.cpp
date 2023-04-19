/*
Given a Binary tree, the task is to calculate the diameter of the tree. The diameter of the tree is the maximum distance between two node on the tree.

For example:

Example of Diameter of BT

Your task is to complete the diameter function. You can write one ore more function to help you complete this task.

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

    //Helping functions
    int getDiameter(){
        //TODO
    }
};

For example:

Test	Result
BinaryTree<int, int> binaryTree;
binaryTree.addNode("",1, 4);
binaryTree.addNode("L",2, 6);
binaryTree.addNode("R",3, 9);
binaryTree.addNode("LL",4, 10);
cout << binaryTree.getDiameter();
4


*/

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
        //TODO
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

};

int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",1, 4);
    binaryTree.addNode("L",2, 6);
    binaryTree.addNode("R",3, 9);
    binaryTree.addNode("LL",4, 10);
    cout << binaryTree.getDiameter();
}