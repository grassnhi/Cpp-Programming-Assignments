#include<iostream>
#include <cassert>

using namespace std;

class AVLTree
{
public:
    class Node
    {
    public:
        enum BalanceValue
        {
            LH = -1,
            EH = 0,
            RH = 1
        };
    private:
        int ID;
        int name;
        BalanceValue balance;
        friend class AVLTree;
        Node* left;
        Node* right;
    public:
        Node(){
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int ID, int name, Node* left = nullptr, Node* right = nullptr){
            this->ID = ID;
            this->name = name;
            this->left = left;
            this->right = right;
        }
    };
    
private:
    int count;
    Node* root;
protected:
    int getHeight(Node* node){
        if(node == nullptr){
            return 0;
        }
        int lh = this->getHeight(node->left);
        int rh = this->getHeight(node->right);
        return max(lh, rh) + 1;
    }

    int getBalance(Node* node){
        if(node == nullptr){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void printInorder(Node* node){
        if(node == nullptr){
            return;
        }
        printInorder(node->left);
        cout << node->ID << "-" << node->name << endl;
        printInorder(node->right);
    }

    Node* rightRotate(Node* node){
        Node* newNode = node->left;
        node->left = newNode->right;
        newNode->right = node;
        return newNode;
    }

    Node* leftRotate(Node* node){
        Node* newNode = node->right;
        node->right = newNode->left;
        newNode->left = node;
        return newNode;
    }

    Node* leftmostRight(Node* node){ 
        Node* curr = node;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }


    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }
        if(node->left){
            clear(node->left);
        }
        if(node->right){
            clear(node->right);
        }
        delete node;
    }

    Node* insert(Node* node, int ID, int name){
        if(node == nullptr){
            return new Node(ID, name);
        }
        if(name < node->name){
            node->left = insert(node->left, ID, name);
        }else if(name >= node->name){
            node->right = insert(node->right, ID, name);
        }

        int balance = getBalance(node);
        if(balance > 1 && name < node->left->name){
            return rightRotate(node);
        }
        if(balance < -1 && name >= node->right->name){
            return leftRotate(node);
        }
        if(balance > 1 && name >= node->left->name){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && name < node->right->name){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* remove(Node* node, int ID){
        if(node == nullptr){
            return node;
        }
        if(ID < node->ID){
            node->left = remove(node->left, ID);
        }else if(ID > node->ID){
            node->right = remove(node->right, ID);
        }else if(ID == node->ID){
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                return nullptr;
            }else if(node->right == nullptr){
                Node* tmp = node->left;
                *node = *tmp;
                delete tmp;
            }else if(node->left == nullptr){
                Node* tmp = node->right;
                *node = *tmp;
                delete tmp;
            }else{
                Node* tmp = leftmostRight(node->right);  
                node->name = tmp->name;
                node->ID = tmp->ID;
                node->right = remove(node->right, tmp->ID); 
            }
        }
        if(node == nullptr){
            return node;
        }
        int balance = getBalance(node);
        if(balance > 1 && getBalance(node->left) >= 0){
            return rightRotate(node);
        }
        if(balance < -1 && getBalance(node->right) <= 0){
            return leftRotate(node);
        }
        if(balance > 1 && getBalance(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    int findID(Node* node, int name){
        if(node == nullptr){
            return -1;
        }else if(node->name == name){
            return node->ID;
        }else if(node->name > name){
            return findID(node->left, name);
        }else{
            return findID(node->right, name);
        }
    }

    int getName(Node* node, int ID){
        if(node == nullptr){
            return -1;
        }else if(node->ID == ID){
            return node->name;
        }else if(node->ID > ID){
            return getName(node->left, ID);
        }else{
            return getName(node->right, ID);
        }
    }
public:
    AVLTree(){
        this->count = 0;
        this->root = nullptr;
    }

    ~AVLTree(){
        clear();
    }

    int getHeight(){
        return this->getHeight(this->root);
    }

    int getCount(){
        return this->count;
    }

    int findID(int name){
        return this->findID(this->root, name);
    }

    bool existID(int ID){
        if(this->getName() = -1){
            return false;
        }
        return true;
    }

    int getName(int ID){
        return this->getName(this->root, ID);
    }
    void insert(const int ID, const int name){
        this->root = insert(this->root, ID, name);
        this->count++;
    }

    void remove(const int ID){
        this->root = remove(this->root, ID);
        this->count--;
    }

    void printInorder(){
        this->printInorder(this->root);
    }

    void clear(){
        clear(this->root);
        this->root = nullptr;
        this->count = 0;
    }
};

int main(){
    AVLTree avlTree;
    avlTree.insert(10, 333);
    avlTree.insert(5, 555);
    avlTree.insert(7, 999);
    avlTree.insert(9, 555);
    avlTree.insert(15, 999);

    avlTree.printInorder();

    avlTree.remove(10);
    avlTree.printInorder();
    cout << avlTree.findID(999) << " " << avlTree.findID(99);
    avlTree.clear();


    return 0;
}