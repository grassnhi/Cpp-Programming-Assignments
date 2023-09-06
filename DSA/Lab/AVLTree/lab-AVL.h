#include<bits/stdc++.h>
using namespace std;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    Node *leftRotation(Node *&root)
    {
        Node *newRoot = root->pRight;
        root->pRight = newRoot->pLeft;
        newRoot->pLeft = root;
        return newRoot;
    }

    Node *rightRotation(Node *&root)
    {
        Node *newRoot = root->pLeft;
        root->pLeft = newRoot->pRight;
        newRoot->pRight = root;
        return newRoot;
    }
    int getBalance(Node *root)
    {
        if (root == nullptr)
            return 0;
        return this->getHeightRec(root->pRight) - this->getHeightRec(root->pLeft);
    }
    Node* reBalance(Node *&root)
    {
        if (root == nullptr)
            return root;
        if (abs(getBalance(root)) <= 1)
            return root;
        Node *newRoot = root;
        if (getBalance(root) < -1)
        {
            Node *leftTree = root->pLeft;
            if (getBalance(leftTree) > 0) // RH of LH
            {
                root->pLeft = leftRotation(root->pLeft);
                newRoot = rightRotation(root);
            }
            else
                newRoot = rightRotation(root);
        }
        else if (getBalance(root) > 1)
        {
            Node *rightTree = root->pRight;
            if (getBalance(rightTree) < 0) //LH of RH
            {
                root->pRight = rightRotation(root->pRight);
                newRoot = leftRotation(root);
            }
            else
                newRoot = leftRotation(root);
        }
        return newRoot;
    }
    Node *add(Node *&root, Node *&newNode)
    {
        if (root == nullptr)
            return newNode;
        if (newNode->data < root->data)
            root->pLeft = add(root->pLeft, newNode);
        else
            root->pRight = add(root->pRight, newNode);
        return reBalance(root);
    }
    void insert(const T &value)
    {
        //TODO
        Node *newNode = new Node(value);
        this->root = add(this->root, newNode);
    }

    Node *deleteNode(Node *&root, T value)
    {
        if (root == nullptr)
            return nullptr;
        Node *newRoot = root;
        if (value < root->data)
            root->pLeft = deleteNode(root->pLeft, value);
        else if (value > root->data)
            root->pRight = deleteNode(root->pRight, value);
        else
        {
            if (root->pLeft == nullptr || root->pRight == nullptr)
            {
                newRoot = (root->pLeft == 0) ? root->pRight : root->pLeft;
                delete root;
            }
            else
            {
                Node *maxLeft = root->pLeft;
                while (maxLeft->pRight != nullptr)
                    maxLeft = maxLeft->pRight;
                swap(root->data, maxLeft->data);
                root->pLeft = deleteNode(root->pLeft, value);
            }
        }
        return reBalance(newRoot);  
    }
    void remove(const T &value){
    //TODO
        this->root = deleteNode(this->root, value);
    }

    void inOrder(Node *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->pLeft);
        cout << root->data << " ";
        inOrder(root->pRight);
    }
    void printInorder(){
        //TODO
        return inOrder(this->root);
    }
    bool search(Node *root, T value)
    {
        if (root == nullptr)
            return false;
        if (root->data == value)
            return true;
        if (value > root->data)
            return search(root->pRight, value);
        else
            return search(root->pLeft, value);
    }
    bool search(const T &value){
        //TODO
        return search(this->root, value);
    }
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(nullptr), pRight(nullptr), balance(EH) {}
        ~Node() {}
    };
};

