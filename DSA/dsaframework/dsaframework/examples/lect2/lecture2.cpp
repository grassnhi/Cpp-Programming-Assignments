#include <iostream>
#include <iomanip>

using namespace std;

//Interation technique
int sum_iteration(int* ptr, int size){
    int _sum = 0;
    for(int idx=0; idx < size; idx++) _sum += ptr[idx];
    return _sum;
}

//Recursion technique
/*
 [2, 6, 1, 8, 4] ; size: 5
 
 ptr
 ptr + 1
 ptr + 2
 * 
 * [^2, 6, 1, 8, 4],   size = 5 <<<<<<<<<<<<<< passed from main
 * [2, ^6, 1, 8, 4],   size = 4
 * [2, 6, ^1, 8, 4],   size = 3
 * ..
 * [2, 6, 1, 8, 4]^ (outside)
 
 
 */
int sum_recursion(int* ptr, int size){
    if(size == 1) return *ptr; //base case OR stopping case
    
    return *ptr + sum_recursion(ptr + 1, size -1);
}

//Recursive data structures:
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left=NULL, Node* right=NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

/*
            (50)
           /   \
         (40)  (60)
 
 */

int sum_nodes(Node* root){
    if(root == NULL) return 0;
    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}
int main(int argc, char** argv){
    Node *root = new Node(50, new Node(40), new Node(60));
    cout << sum_nodes(root) << endl;  //EXPECTATION: 150
    
    return 0;
}