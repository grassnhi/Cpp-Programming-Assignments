#include<iostream>
#include <queue>

using namespace std;

template <class T>
class BinaryTree
{  
public:
    class Node{
        private:
            T data;
            Node* pLeft;
            Node* pRight;
            friend class BinaryTree<T>;
        public:
            Node(){
                this->data = 0;
                this->pLeft = nullptr;
                this->pRight = nullptr;
            }

            Node(T data, Node* pLeft = nullptr, Node* pRight = nullptr){
                this->data = data;
                this->pLeft = pLeft;
                this->pRight = pRight;
            }
    };

    Node* root;

public:
    BinaryTree(){
        this->root = root;
    }

    ~BinaryTree(){
        delete root;
    }

    void insert(T* arr, int size) {
        if (size == 0) return;
        
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root); 
        
        int i = 1;
        while (!q.empty() && i < size) { 
            Node* curr = q.front(); 
            q.pop();
            if (i < size) { 
                curr->pLeft = new Node(arr[i]);
                q.push(curr->pLeft);
                i++;
            }
            if (i < size) { 
                curr->pRight = new Node(arr[i]);
                q.push(curr->pRight);
                i++;
            }
        }
        this->root = root; 
    }

    void inOrder(Node* root){
        if(root == nullptr){
            return;
        }else{
            inOrder(root->pLeft);
            cout << root->data;
            inOrder(root->pRight);
        }
    }

    void mirror(Node* root){
        Node* cursor = root;
        if(cursor == nullptr){
            return;
        }
        
        mirror(cursor->pLeft);
        mirror(cursor->pRight);

        T tmp = cursor->pLeft->data;
        cursor->pLeft->data = cursor->pRight->data;
        cursor->pRight->data = tmp;
    }

    T sumLevel(Node* root, T L){
        T sum = 0;

    }

    void printR2L(){

    }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};

    BinaryTree<int>* bTree = new BinaryTree<int>();
    bTree->insert(arr, 6);
    bTree->inOrder(bTree->root);

    bTree->mirror(bTree->root);
    bTree->inOrder(bTree->root);
    
    return 0;
}