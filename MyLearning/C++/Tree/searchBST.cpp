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
        while (!queue.empty()) {p = queue.dequeue();visit(p);if (p->left != 0)queue.enqueue(p->left);if (p->right != 0)queue.enqueue(p->right);}} }
