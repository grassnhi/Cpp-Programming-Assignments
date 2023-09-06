#include <queue>
#include <cmath>
#include <iostream>
#include <cassert>
#include <sstream>

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
        class Node {
            private:
                T data;
                Node *pLeft, *pRight;
                BalanceValue balance;
                friend class AVLTree<T>;

            public:
                Node(T value) : data(value), pLeft(nullptr), pRight(nullptr), balance(EH) {}
                ~Node() {}
            };
    private:
        Node* root;
    protected:
        int getHeightRec(Node* node){
            if(node == nullptr){
                return 0;
            }
            int lh = this->getHeightRec(node->pLeft);
            int rh = this->getHeightRec(node->pRight);
            return max(lh, rh) + 1;
        }

        int getBalance(Node* node){
            if(node == nullptr){
                return 0;
            }
            return getHeightRec(node->pLeft) - getHeightRec(node->pRight); 
        }

    public:
        AVLTree(){
            this->root = nullptr;
        }

        ~AVLTree(){
            clear();
        }

        int getHeight(){
            return this->getHeightRec(this->root);
        }

        void printTreeStructure(){
            int height = this->getHeight();
            if(this->root == nullptr){
                cout << "Null AVL Tree!" << endl;
                return;
            }
            queue<Node*> q;
            q.push(root);
            Node* temp;
            int count = 0, level = 0;
            int maxNode = 1, space = pow(2, height);
            printNSpace(space / 2);
            while (!q.empty())
            {
                temp = q.front();
                q.pop();
                if(temp == nullptr){
                    cout << " ";
                    q.push(nullptr);
                    q.push(nullptr);
                }else{
                    cout << temp->data;
                    q.push(temp->pLeft);
                    q.push(temp->pRight);
                }
                printNSpace(space);
                count++;
                if(count == maxNode){
                    cout << endl;
                    count = 0;
                    maxNode *= 2;
                    level++;
                    space /= 2;
                }
                if(level == height){
                    return;
                }
            }
            
        }

        Node* rightRotate(Node* node){
            Node* newNode = node->pLeft;
            node->pLeft = newNode->pRight;
            newNode->pRight = node;
            return newNode;
        }

        Node* leftRotate(Node* node){
            Node* newNode = node->pRight;
            node->pRight = newNode->pLeft;
            newNode->pLeft = node;
            return newNode;
        }
        
        Node* insert(Node* node, T value){
            if(node == nullptr){
                return new Node(value);
            }

            if(value < node->data){
                node->pLeft = insert(node->pLeft, value);
            }else if(value >= node->data){
                node->pRight = insert(node->pRight, value);
            }

            int balance = getBalance(node);
            if(balance > 1 && value < node->pLeft->data){
                return rightRotate(node);
            }// left left
            if(balance < -1 && value >= node->pRight->data){
                return leftRotate(node);
            } // right right
            if(balance > 1 && value >= node->pLeft->data){
                node->pLeft = leftRotate(node->pLeft);
                return rightRotate(node);
            } // left right
            if(balance < -1 && value < node->pRight->data){
                node->pRight = rightRotate(node->pRight);
                return leftRotate(node);
            }
            return node;
        }

        void insert(const T& value){
            this->root = insert(this->root, value);
        }

        Node* maxValueNode(Node* node){
            Node* maxNode = node;
            while (maxNode->pRight != nullptr)
            {
                maxNode = maxNode->pRight;
            }
            return maxNode;
        }

        Node* deleteNode(Node* node, T value) {
            if (node == nullptr) {
                return node;
            }
            if (value < node->data) {
                node->pLeft = deleteNode(node->pLeft, value);
            } else if (value > node->data) {
                node->pRight = deleteNode(node->pRight, value);
            } else {
                if (node->pLeft == nullptr && node->pRight == nullptr) {
                    delete node;
                    return nullptr;
                } else if (node->pLeft == nullptr) {
                    Node* temp = node->pRight;
                    *node = *temp; // copy content
                    delete temp;
                } else if (node->pRight == nullptr) {
                    Node* temp = node->pLeft;
                    *node = *temp; // copy content
                    delete temp;
                } else {
                    Node* temp = maxValueNode(node->pLeft);
                    node->data = temp->data;
                    node->pLeft = deleteNode(node->pLeft, temp->data);
                }
            }
            if (node == nullptr) {
                return node;
            }
            int balance = getBalance(node);
            if (balance > 1 && getBalance(node->pLeft) < 0) {
                node->pLeft = leftRotate(node->pLeft);
                return rightRotate(node);
            } // left right
            if (balance > 1 && getBalance(node->pLeft) >= 0) {
                return rightRotate(node);
            } // left left
            if (balance < -1 && getBalance(node->pRight) > 0) {
                node->pRight = rightRotate(node->pRight);
                return leftRotate(node);
            } // right left
            if (balance < -1 && getBalance(node->pRight) <= 0) {
                return leftRotate(node);
            } // right right
            return node;
        }


        void remove(const T& value){
            this->root = deleteNode(this->root, value);
        }

        void printInorder(Node* node){
            if(node == nullptr){
                return;
            }
            printInorder(node->pLeft);
            cout << node->data << " ";
            printInorder(node->pRight);
        }

        void printInorder(){
            this->printInorder(this->root);
        }

        bool findNode(Node* node, T value){
            if(node == nullptr){
                return false;
            }else if(node->data == value){
                return true;
            }else if(node->data > value){
                return findNode(node->pLeft, value);
            }else{
                return findNode(node->pRight, value);
            }
        }

        bool search(T value){
            return this->findNode(this->root, value);
        }

        void clear(Node* node){
            if(node == nullptr){
                return;
            }
            clear(node->pLeft);
            clear(node->pRight);
            delete node;
        }

        void clear(){
            clear(this->root);
            this->root = nullptr;
        }
};

int main(){
    AVLTree<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);

    assert(avlTree.search(5) == true);
    assert(avlTree.search(3) == true);
    assert(avlTree.search(7) == true);

    avlTree.printInorder();

    avlTree.remove(3);
    assert(avlTree.search(3) == false);
    avlTree.printInorder();

    avlTree.clear();
    assert(avlTree.search(5) == false);
    assert(avlTree.search(3) == false);
}