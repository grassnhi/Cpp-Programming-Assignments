#include <queue> 
#include <stack> 

using namespace std; 

#ifndef BINARY_SEARCH_TREE 
#define BINARY_SEARCH_TREE 

template<class T> 
class Stack : public stack<T> { } // as in Figure 4.21 

template<class T> 
class Queue : public queue<T> { 
    public:T dequeue() {
        T tmp = front();
        queue<T>::pop();
        return tmp;
    }
    
    void enqueue(const T& el) {
        push(el);
    } 
}; 

template<class T> class BSTNode { 
    public:BSTNode() { 
        left = right = 0; 
    }
    
    BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
        el = e; 
        left = l; 
        right = r; 
    }
    
    T el;
    BSTNode<T> *left, *right; 
};

template<class T> class BST { 
    public:BST() { 
        root = 0; 
    }
    
    ~BST() { 
        clear();
    }
    
    void clear() {
        clear(root); 
        root = 0;
    }
    
    bool isEmpty() const { 
        return root == 0; 
    }
    
    void preorder() { 
        preorder(root);    // Figure 6.11
    }
    
    void inorder() { 
        inorder(root);  // Figure 6.11
    }
    
    void postorder() { 
        postorder(root);   // Figure 6.11
    }
    
    T* search(const T& el) const { 
        return search(root,el); // Figure 6.9
    }
    
    void breadthFirst(); // Figure 6.10
    
    void iterativePreorder(); // Figure 6.15
    
    void iterativeInorder(); // Figure 6.17
    
    void iterativePostorder(); // Figure 6.16
    
    void MorrisInorder(); // Figure 6.20
    
    void insert(const T&); // Figure 6.23
    
    void deleteByMerging(BSTNode<T>*&); // Figure 6.29
    
    void findAndDeleteByMerging(const T&); // Figure 6.29
    
    void deleteByCopying(BSTNode<T>*&); // Figure 6.32
    
    void balance(T*,int,int); // Section 6.7

protected:
    BSTNode<T>* root; 

    void clear(BSTNode<T>*);
    
    T* search(BSTNode<T>*, const T&) const; // Figure 6.9
    
    void preorder(BSTNode<T>*); // Figure 6.11
    
    void inorder(BSTNode<T>*); // Figure 6.11
    
    void postorder(BSTNode<T>*); // Figure 6.11
    
    virtual void visit(BSTNode<T>* p) { 
        cout << p->el << ' '; 
    }
}; 

template<class T> 
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
    while (p != 0)
        if (el == p->el)
            return &p->el;
        else if (el < p->el)
            p = p->left;
        else p = p->right;
        
    return 0; 
}

template<class T> 
void BST<T>::breadthFirst() {    
    Queue<BSTNode<T>*> queue;
    BSTNode<T> *p = root;
    if (p != 0) {
        queue.enqueue(p);
        while (!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if (p->left != 0)
                queue.enqueue(p->left);
            if (p->right != 0)
                queue.enqueue(p->right);
        }
    } 
}

template<class T> 
void BST<T>::inorder(BSTNode<T> *p) {
    if (p != 0) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    } 
} 

template<class T> 
void BST<T>::preorder(BSTNode<T> *p) {
    if (p != 0) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    } 
} 

template<class T> 
void BST<T>::postorder(BSTNode<T>* p) {
    if (p != 0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    } 
}

template<class T> 
void BST<T>::iterativePreorder() {    
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    if (p != 0) {
        travStack.push(p);
        while (!travStack.empty()) {
            p = travStack.pop();
            visit(p);
            if (p->right != 0)
                travStack.push(p->right);
            if (p->left != 0)   // left child pushed after right
                travStack.push(p->left); // to be on the top of 
        }                       // the stack;
    } 
}

template<class T> 
void BST<T>::iterativePostorder() {    
    Stack<BSTNode<T>*> travStack;
    BSTNode<T>* p = root, *q = root;
    while (p != 0) {
        for ( ; p->left != 0; p = p->left)
            travStack.push(p);
        while (p->right == 0 || p->right == q) {
            visit(p);q = p;
            if (travStack.empty())
                return;
            p = travStack.pop();
        }     
        travStack.push(p);
        p = p->right;
    }
}

template<class T> 
void BST<T>::iterativeInorder() {    
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    while (p != 0) {
        while (p != 0) {         // stack the right child (if any)
            if (p->right)        // and the node itself when going
                travStack.push(p->right); // to the left;
            travStack.push(p);
            p = p->left;
        }
        p = travStack.pop();     // pop a node with no left child
        while (!travStack.empty() && p->right == 0) { // visit it 
            visit(p);            // and all nodes with no right 
            p = travStack.pop(); // child;
        }
        visit(p);                // visit also the first node with
        if (!travStack.empty())   // a right child (if any);
            p = travStack.pop();
        else p = 0;
    } 
}

template<class T> 
void BST<T>::MorrisInorder() {   
    BSTNode<T> *p = root, *tmp;
    while (p != 0)
        if (p->left == 0) {
            visit(p);
            p = p->right;
        }
        else {
            tmp = p->left;
            while (tmp->right != 0 && // go to the rightmost node 
                tmp->right != p)   // of the left subtree ort
                mp = tmp->right;    // to the temporary parent 
            if (tmp->right == 0) {    // of p; if 'true' 
                tmp->right = p;      // rightmost node was 
                p = p->left;         // reached, make it a 
            }                         // temporary parent of the 
            else {                    // current root, else // a temporary parent has 
                visit(p);            // been found; visit node p 
                tmp->right = 0;      // and then cut the right// pointer of the current
                p = p->right;        // parent, whereby it 
            }                         // ceases to be a parent;
        } 
}

template<class T> 
void BST<T>::insert(const T& el) {   
    BSTNode<T> *p = root, *prev = 0;
    while (p != 0) {  // find a place for inserting new node;
        prev = p;
        if (el < p->el)
            p = p->left;
        else p = p->right;
    }
    
    if (root == 0)    // tree is empty;
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left   = new BSTNode<T>(el);
    else prev->right  = new BSTNode<T>(el); 
}

template<class T> 
void BST<T>::deleteByMerging(BSTNode<T>*& node) {   
    BSTNode<T> *tmp = node;
    if (node != 0) {
        if (!node->right)            // node has no right child: its left
            node = node->left;      // child (if any) is attached to its  // parent;
        else if (node->left == 0)    // node has no left child: its 
            rightnode = node->right;     // child is attached to its parent;
        else {                       // be ready for merging subtrees;
            tmp = node->left;      // 1. move left
        while (tmp->right != 0)// 2. and then right as far as  // possible;
            tmp = tmp->right;
            tmp->right =           // 3. establish the link between 
                node->right;        //    the rightmost node of the left
                                //    subtree and the right subtree;
            tmp = node;            // 4.
            node = node->left;     // 5.
        }
        delete tmp;                 // 6.
    } 
}

template<class T> 
void BST<T>::findAndDeleteByMerging(const T& el) {    
    BSTNode<T> *node = root, *prev = 0;
    while (node != 0) {
        if (node->el == el)
            break;
        prev = node;
        if (el < node->el)
            node = node->left;
        else 
            node = node->right;
    }
    if (node != 0 && node->el == el)
        if (node == root)
            deleteByMerging(root);
        else if (prev->left == node)
            deleteByMerging(prev->left);
        else 
            deleteByMerging(prev->right);
    else if (root != 0)
        cout << "element" << el << "is not in the tree\n";
    else 
        cout << "the tree is empty\n"; 
}

template<class T> 
void BST<T>::deleteByCopying(BSTNode<T>*& node) {    
    BSTNode<T> *previous, *tmp = node;
    if (node->right == 0)               // node has no right child;
        node = node->left;
    else if (node->left == 0)           // node has no left child;
        node = node->right;
    else {
        tmp = node->left;              // node has both children;
        previous = node;               // 1.
        while (tmp->right != 0) {      // 2.
            previous = tmp;
            tmp = tmp->right;
        }
        node->el = tmp->el;          // 3.
        if (previous == node)
            previous ->left  = tmp->left;
        else 
            previous ->right = tmp->left;  // 4.
    }
    delete tmp;                              // 5. 
}

template<class T>
void BST<T>::balance(T data[], int first, int last) {
    if (first <= last) {
        int middle = (first + last)/2;
        insert(data[middle]);
        balance (data,first,middle-1);
        balance (data,middle+1,last);
    }
}


#endif