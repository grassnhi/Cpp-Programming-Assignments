#include <iostream>
#include <iomanip>
#include <sstream>
#include "tree/BST.h"
#include "tree/AVL.h"
#include "list/DLinkedList.h"
#include "geom/Point3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

using namespace std;


////////////////////////////////////////////////////////////////
// (1) UNDERSTANDING + HOW TO USE
////////////////////////////////////////////////////////////////

void tree_quiz_1(){
    int ptr[] = {50, 20, 80, 40, 60, 45};
    BST<int, int*> tree;
    for(int key: ptr) tree.add(key);
    tree.println();
}

void tree_quiz_2(){
    //OK
    int size = 10;
    Point3D* ptr = Point3D::genPoints(10);
    BST<float, Point3D*> tree;
    for(int idx=0; idx < size; idx++) tree.add(ptr[idx].radius(), new Point3D(ptr[idx]));
    delete []ptr;
    tree.println();
    
    
    /*
    int size = 10;
    Point3D* ptr = Point3D::genPoints(10);
    BST<float, Point3D*> tree;
    for(int idx=0; idx < size; idx++) tree.add(ptr[idx].radius(), &ptr[idx]);
    tree.println();
    */
    
    //NOPE
    /*
    int size = 10;
    Point3D* ptr = Point3D::genPoints(10);
    BST<float, Point3D*> tree;
    for(int idx=0; idx < size; idx++) tree.add(ptr[idx].radius(), ptr[idx]);
    delete []ptr;
    tree.println();
     */
    
}
void tree_quiz_3(){
    int ptr[] = {80, 10, 70, 15, 65, 20, 60, 40};
    BST<int, int*> tree;
    for(int key: ptr) tree.add(key);
    tree.println();
    cout << tree.height() << endl;
}
void tree_quiz_4(){
    int ptr[] = {80, 10, 70, 15, 65, 20, 60, 40};
    AVL<int, int*> tree;
    for(int key: ptr) tree.add(key);
    tree.println();
    cout << tree.height() << endl;
}

void tree_quiz_5(){
    BST<int, int*> tree;
    for(int key=0; key < 100; key += 2) tree.add(key);
    tree.println();
    cout << tree.height() << endl;
}

void tree_quiz_6(){
    AVL<int, int*> tree;
    for(int key=0; key < 100; key += 2) tree.add(key);
    tree.println();
    cout << tree.height() << endl;
}

void tree_quiz_7(){
    int ptr[] = {50, 20, 80, 40, 60, 45};
    IBST<int, int*> *tree = new BST<int, int*>();
    for(int key: ptr) tree->add(key);
    dynamic_cast<BST<int, int*>*>(tree)->println();
    ((BST<int, int*>*) tree)->println();
    cout << tree->toString() << endl;
    
    delete tree;
}

string node2strv(int& k, int*& v){
    stringstream os;
    os << *v;
    return os.str().c_str();
}
string node2strk(int& k, int*& v){
    stringstream os;
    os << k;
    return os.str().c_str();
}
string value2str(int*& v){
    stringstream os;
    os << *v;
    return os.str().c_str();
}
void tree_quiz_8(){
    int ptr[] = {50, 20, 80, 40, 60, 45};
    BST<int, int*> tree;
    for(int key: ptr) tree.add(key, new int(2*key));
    tree.println(node2strv);
    tree.println(node2strk);
}

void tree_quiz_9(){
    int ptr[] = {50, 20, 80, 40, 60, 45};
    BST<int, int*> tree;
    for(int key: ptr) tree.add(key, new int(2*key));
    tree.println(node2strv);
    DLinkedList<int*> bfs = tree.bfs(); bfs.println(&value2str);
    DLinkedList<int*> dfs = tree.dfs(); dfs.println(&value2str);
    DLinkedList<int*> lnr = tree.lnr(); lnr.println(&value2str);
    DLinkedList<int*> nlr = tree.nlr(); nlr.println(&value2str);
    DLinkedList<int*> lrn = tree.lrn(); lrn.println(&value2str);
    DLinkedList<int> bfsKey = tree.bfsKey(); bfsKey.println();
    
}
void tree_quiz_10(){
    int ptr[] = {50, 20, 80, 40, 60, 45};
    AVL<int, int*> tree;
    for(int key: ptr) tree.add(key, new int(2*key));
    tree.println(node2strv);
    DLinkedList<int*> bfs = tree.bfs(); bfs.println(&value2str);
    DLinkedList<int*> dfs = tree.dfs(); dfs.println(&value2str);
    DLinkedList<int*> lnr = tree.lnr(); lnr.println(&value2str);
    DLinkedList<int*> nlr = tree.nlr(); nlr.println(&value2str);
    DLinkedList<int*> lrn = tree.lrn(); lrn.println(&value2str);
    DLinkedList<int> bfsKey = tree.bfsKey(); bfsKey.println();
    
}

void tree_quiz_11(){
    int ptr[] = {80, 25, 10, 50, 70, 40};
    AVL<int, int*> tree;
    for(int key: ptr) tree.add(key);
    tree.println();
    tree.remove(50);
    tree.println();
    DLinkedList<int> list = tree.bfsKey();
    list.println();
}

void tree_search(){
    int ptr[] = {80, 25, 10, 50, 70, 40};
    AVL<int, int*> tree;
    for(int key: ptr) tree.add(key, new int(2*key));
    tree.println();
    bool found;
    int *v = tree.search(10, found);
    cout << "value " << *v << ":" << found << endl;
}

////////////////////////////////////////////////////////////////
// (2) HOW TO USE
////////////////////////////////////////////////////////////////

template <class K, class V>
struct TNode{
    K key;
    V value;
    TNode<K,V> *left, *right;
    TNode(K key, V value=NULL, TNode<K,V> *left = NULL, TNode<K,V> *right=NULL){
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};
//IMPORTANT NOTE: V MUST BE a pointer type, e.g., Point3D* instead of Point3D

template <class K, class V>
TNode<K,V>* simple_tree_0(){
    TNode<int, int*> *b = new TNode<int,int*>(10);
    TNode<int, int*> *c = new TNode<int,int*>(50);
    TNode<int, int*> *a = new TNode<int,int*>(40);
    a->left = b; a->right = c;
    return a;
}
    
template <class K, class V>
TNode<K,V>* simple_tree_1(){
    TNode<int, int*> *b = new TNode<int,int*>(10);
    TNode<int, int*> *c = new TNode<int,int*>(50);
    TNode<int, int*> *a = new TNode<int,int*>(40, NULL, b, c);
    return a;
}

TNode<int, int*>* simple_tree_2(){
    return new TNode<int,int*>(40, NULL, 
            new TNode<int, int*>(10),
            new TNode<int, int*>(50));
}

TNode<int, int*>* simple_tree_3(){
    return new TNode<int,int*>(40, NULL, 
            new TNode<int, int*>(10, NULL,
            new TNode<int, int*>(50)));
}

//OK
TNode<float, Vector3D*>* tree_of_vectors_1(){
    Vector3D vectors[] = {
        Vector3D(1,2,3),
        Vector3D(2,3,4),
        Vector3D(3,4,5)
    };
    TNode<float, Vector3D*> *a = new TNode<float,Vector3D*>(vectors[0].getX(), new Vector3D(vectors[0]));
    TNode<float, Vector3D*> *b = new TNode<float,Vector3D*>(vectors[1].getX(), new Vector3D(vectors[1]));
    TNode<float, Vector3D*> *c = new TNode<float,Vector3D*>(vectors[2].getX(), new Vector3D(vectors[2]));
    b->left = a; b->right = c;
    return b;
}
//NOT OK
TNode<float, Vector3D*>* tree_of_vectors_2(){
    Vector3D vectors[] = {
        Vector3D(1,2,3),
        Vector3D(2,3,4),
        Vector3D(3,4,5)
    };
    TNode<float, Vector3D*> *a = new TNode<float,Vector3D*>(vectors[0].getX(), &vectors[0]);
    TNode<float, Vector3D*> *b = new TNode<float,Vector3D*>(vectors[1].getX(), &vectors[1]);
    TNode<float, Vector3D*> *c = new TNode<float,Vector3D*>(vectors[2].getX(), &vectors[2]);
    b->left = a; b->right = c;
    return b;
}

//OK
TNode<float, Vector3D*>* tree_of_vectors_3(){
    Vector3D vectors[] = {
        Vector3D(1,2,3),
        Vector3D(2,3,4),
        Vector3D(3,4,5)
    };
    TNode<float, Vector3D*> *root = new TNode<float,Vector3D*>(
            vectors[1].getX(), 
            new Vector3D(vectors[1]),
            new TNode<float,Vector3D*>(vectors[0].getX(), new Vector3D(vectors[0])),
            new TNode<float,Vector3D*>(vectors[2].getX(), new Vector3D(vectors[2]))
    );
    return root;
}


template <class K, class V>
void delete_tree_1(TNode<K,V> *root){
    delete root;
}

template <class K, class V>
void delete_tree_2(TNode<K,V> *root){
    if(root == NULL) return;
    delete_tree_2(root->left);
    delete_tree_2(root->right);
    if (root->value != NULL) delete root->value;
}

template <class K, class V>
void delete_tree_3(TNode<K,V> *root){
    if(root == NULL) return;
    delete_tree_2(root->left);
    delete_tree_2(root->right);
}


float count_1(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    return 1 + count_1(root->left) + count_1(root->right);
}
float count_2(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    Stack<TNode<float, Vector3D*>*> fringe;
    fringe.push(root);
    int count = 0;
    while(!fringe.empty()){
        TNode<float, Vector3D*>* node = fringe.pop();
        count += 1;
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return count;
}
float count_3(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    Queue<TNode<float, Vector3D*>*> fringe;
    fringe.push(root);
    int count = 0;
    while(!fringe.empty()){
        TNode<float, Vector3D*>* node = fringe.pop();
        count += 1;
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return count;
}

float longest(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    TNode<float, Vector3D*>* cursor =root;
    while(cursor->right != NULL) cursor = cursor->right;
    return cursor->value->length();
}
float shortest(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    TNode<float, Vector3D*>* cursor =root;
    while(cursor->left != NULL) cursor = cursor->left;
    return cursor->value->length();
}

float length_average_1(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    Stack<TNode<float, Vector3D*>*> fringe;
    fringe.push(root);
    int count = 0;
    float total = 0;
    while(!fringe.empty()){
        TNode<float, Vector3D*>* node = fringe.pop();
        total += node->value->length(); count++;
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return total/count;
}
float length_average_2(TNode<float, Vector3D*> *root){
    if(root == NULL) return 0;
    
    Queue<TNode<float, Vector3D*>*> fringe;
    fringe.push(root);
    int count = 0;
    float total = 0;
    while(!fringe.empty()){
        TNode<float, Vector3D*>* node = fringe.pop();
        total += node->value->length(); count++;
        if(node->left != NULL) fringe.push(node->left);
        if(node->right != NULL) fringe.push(node->right);
    }
    return total/count;
}

int main(int arc, char** argv){
    tree_quiz_1();
}