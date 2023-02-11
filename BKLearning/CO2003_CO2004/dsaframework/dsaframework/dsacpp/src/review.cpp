#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


template <class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next = NULL){
        this->data = data;
        this->next = next;
    }
};

template <class T>
struct TNode{
    T data;
    TNode<T>* left, *right;
    TNode(T data, TNode<T>* left = NULL, TNode<T>* right = NULL){
      this->data = data;
      this->left = left;
      this->right = right;
      
    }
};

/*
        40
       /  \
      30   60
     /  \    \
    10   35   70
   /
  5
 /
1
 
 */

TNode<int>* create_tree(){
    TNode<int>* p5 = new TNode<int>(5, 
                            new TNode<int>(1));
    TNode<int>* p10 = new TNode<int>(10, p5);
    TNode<int>* p30 = new TNode<int>(30, p10, new TNode<int>(35));
    TNode<int>* p60 = new TNode<int>(60, NULL, new TNode<int>(70));
    TNode<int>* root = new TNode<int>(40, p30, p60);
    return root;
}

/*
 create achain: 
 head->(90)->(30)->(40)
 */
Node<int>* create_simple(){
    Node<int> *head = new Node<int>(90, new Node<int>(30, new Node<int>(40, NULL)));
    return head;
}

/*
 Example: head->(90)->(30)->(40)
 return: [90, 30, 40]
 return: []  if head is null
 */
string to_string(Node<int> * const head){
    if(head == NULL) return "[]";
    //FROM HERE: head is not null
    stringstream os;
    Node<int> *ptr = head;
    while(ptr != NULL){
        os << ptr->data << ", ";
        ptr = ptr->next;
    }
    string itemstr = os.str();
    itemstr = itemstr.substr(0, itemstr.rfind(",")); //rfind " reverse finding
    return "[" + itemstr + "]";
}
void println_chain(Node<int> * const head){
    cout << to_string(head) << endl;
}

//Homework: recursive impl.
void delete_schain(Node<int> * head){
    Node<int> * backup;
    while(head != NULL){
        backup = head->next;
        delete head;
        head = backup;
    }
}
int main(int argc, char **argv){
    Node<int>* head = create_simple();
    println_chain(head);
    delete_schain(head);
    
    return 0;
}