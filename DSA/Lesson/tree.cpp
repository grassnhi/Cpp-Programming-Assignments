#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void create_tree(){
    Node* root1 = NULL;
    Node* root2 = new Node(50);
    Node* root3 = new Node(50, new Node(10));
    Node* root4 = new Node(50, new Node(10), new Node(70));
    Node* root5 = new Node(50, new Node(10), new Node(70, new Node(65)));
    Node* root5_v2 = new Node(50);
    Node* sub1 = new Node(10);
    Node* sub2 = new Node(70, new Node(65));
    root5_v2->left = sub1;
    root5_v2->right = sub2;
}
