#include <iostream>
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
        int result;
        string name;
        int NUM;
        BalanceValue balance;
        friend class AVLTree;
        Node* left;
        Node* right;
    public:
        Node(){
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int ID, int result, string name, int NUM = 1, Node* left = nullptr, Node* right = nullptr){
            this->ID = ID;
            this->result = result;
            this->name = name;
            this->NUM = NUM;
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
        cout << node->ID << "-" << node->result << "-" << node->NUM << endl;
        printInorder(node->right);
    }

    void levelPrint(Node* node, int level){
        if(node == nullptr){
            return;
        }
        if(level == 0){
            cout << node->ID << "-" << node->result << "-" << node->NUM << endl;
        }else if(level > 0){
            levelPrint(node->left, level - 1);
            levelPrint(node->right, level - 1);
        }
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

    Node* insert(Node* node, int ID, int result, string name){
        if(node == nullptr){
            return new Node(ID, result, name);
        }
        if(result < node->result){
            node->left = insert(node->left, ID, result, name);
        }else if(result >= node->result){
            node->right = insert(node->right, ID, result, name);
        }

        int balance = getBalance(node);
        if(balance > 1 && result < node->left->result){
            return rightRotate(node);
        }
        if(balance < -1 && result >= node->right->result){
            return leftRotate(node);
        }
        if(balance > 1 && result >= node->left->result){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && result < node->right->result){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* remove(Node* node, int ID){
        if(node == nullptr){
            return node;
        }
        if (node->ID != ID) {
			node->left = remove(node->left, ID);
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
                node->result = tmp->result;
                node->ID = tmp->ID;
                node->NUM = tmp->NUM;
                node->name = tmp->name;
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

    int findID(Node* node, int result){
        if(node == nullptr){
            return -1;
        }else if(node->result == result){
            return node->ID;
        }else if(node->result > result){
            return findID(node->left, result);
        }else{
            return findID(node->right, result);
        }
    }

    bool search(Node* node, string name){
        if(node == nullptr){
            return false;
        }
        if(node->name != name){
            this->search(node->left, name);
            this->search(node->right, name);
        }else{
            return true;
        }
        return false;
    }

    void updateOrders(Node* node, string name){
        if(node == nullptr){
            return;
        }else if(node->name == name){
            node->NUM++;
        }else if(node->name > name){
            this->findID(node->left, name);
        }else{
            this->findID(node->right, name);
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

    int findID(int result){
        return this->findID(this->root, result);
    }

    void insert(const int ID, const int result, string name){
        this->root = insert(this->root, ID, result, name);
        this->count++;
    }

    void remove(const int ID){
        this->root = remove(this->root, ID);
        this->count--;
    }

    bool search(string name){
        return this->search(this->root, name);
    }

    void updateOrders(string name){
        this->updateOrders(this->root, name);
    }

    void printInorder(){
        this->printInorder(this->root);
    }

    void levelPrint(){
        int height = this->getHeight(this->root);
        for(int i = 0; i < height; i++){
            levelPrint(this->root, i);
        }
    }

    void clear(){
        clear(this->root);
        this->root = nullptr;
        this->count = 0;
    }
};
