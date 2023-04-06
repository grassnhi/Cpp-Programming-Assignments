#include <iostream>
#include <queue>

using namespace std;


template<class T>
class BST
{
public:
    class Node
    {
    private:
        T data;
        Node* left;
        Node* right;
        friend class BST<T>;
    public:
        Node(){
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(T data, Node* left = nullptr, Node* right = nullptr){
            this->data = data;
            this->left = left;
            this->right = right;
        }
            
        ~Node();
    };
    Node* root;

public:

    BST(){
        this->root = nullptr;
    }
    ~BST(){}

    

    void insertRercursive(T* arr, int size){
        for (int i = 0; i < size; i++)
            this->root = createTreeR(this->root, arr[i]);
    }

    Node* createTreeR(Node* root, int data) {
        if (!root) {
            return new Node(data);
        }

        if (data < root->data)
            root->left = createTreeR(root->left, data);
        else 
            root->right = createTreeR(root->right, data);
        return root;
    }

    Node* createTreeL(T* arr, int size){
        if(size == 0){
            return nullptr;
        }else{
            root = new Node(arr[0]);

            queue<Node*> q;
            q.push(root);
            
            int i = 1;
            while (i < size && !q.empty())
            {
                Node* curr = q.front();
                q.pop();

                curr->left = new Node(arr[i]);
                q.push(curr->left);
                i++;

                if(i < size){
                    curr->right = new Node(arr[i]);
                    q. push(curr->right);
                    i++;
                }
            }
            return root;
        }
    }

    void insertLoop(T* arr, int size){
        root = createTreeL(arr, size);
    }

    void deleteMaxL(T value, int opt){

    }

    void deleteMinR(T value, int opt){

    }

    bool find(T value){
        while (root != 0){
            if(value == root->data){
                return true;
            }else if(value < root->data){
                root = root->left;
            }else{
                root = root->right;
            } 
        }  
        return false; 
    }

    T maxNode(){
        if(!root){
            return -1;
        }

        int value = root->data;
        int leftMax = maxNode(root->left);
        int rightMax = maxNode(root->right);
    
        return max(value, max(leftMax, rightMax));
    }

    T minNode(){
        if (!root) {
            return -1;
        }

        int value = root->data;
        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);
    
        return min(value, min(leftMin, rightMin));
    }

    bool checkBST(Node* root){
        if (!root){
            return true;
        }           
        if (root->left != nullptr && maxValue(root->left) > root->data){
            return false;
        }
        if (root->right != nullptr && minValue(root->right) < root->data){
            return false;
        }
        if (!checkBST(root->left) || !checkBST(root->right)){
            return false;
        }   
        return true;
    }

    void preOrder(Node* root){
        if(root == nullptr){
            return;
        }else{
            cout << root->data;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main(){
    int arr[] = {15, 5, 20, 20, 10, 18};
    BST<int>* tree2 = new BST<int>();
    tree2->insertRercursive(arr, sizeof(arr)/sizeof(int));
    tree2->preOrder(tree2->root);
    cout << endl << tree2->find(20) << "-" << tree2->find(8) << endl;
    
    return 0;
}