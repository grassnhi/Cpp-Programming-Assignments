#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename E> 
class HuffNode { 
public: 
    virtual ~HuffNode() {} // Base destructor 
    virtual int weight() = 0; // Return frequency 
    virtual bool isLeaf() = 0; // Determine type 
}; 

template <typename E> // Leaf node subclass 
class LeafNode : public HuffNode<E> { 
private: 
    E it; // Value 
    int wgt; // Weight 

public: 
    LeafNode(const E& val, int freq) // Constructor 
    { 
        it = val; 
        wgt = freq; 
    } 
    
    int weight() { 
        return wgt; 
    } 
    
    E val() { 
        return it; 
    } 
    
    bool isLeaf() { 
        return true; 
    } 
}; 

template <typename E> // Internal node subclass 
class IntlNode : public HuffNode<E> { 
private: 
    HuffNode<E>* lc; // Left child 
    HuffNode<E>* rc; // Right child 
    int wgt;// Subtree weight 

public: 
    IntlNode(HuffNode<E>* l, HuffNode<E>* r) { 
        wgt = l->weight() + r->weight(); 
        lc = l; rc = r; 
    } 
    
    int weight() { 
        return wgt; 
    } 
    
    bool isLeaf() { 
        return false; 
    } 
    
    HuffNode<E>* left() const { 
        return lc;
    } 
    
    void setLeft(HuffNode<E>* b) { 
        lc = (HuffNode<E>*)b; 
    } 
    
    HuffNode<E>* right() const { 
        return rc; 
    } 
    
    void setRight(HuffNode<E>* b) { 
        rc = (HuffNode<E>*)b; 
    } 
};

// HuffTree is a template of two parameters: the element 
// type being coded and a comparator for two such elements. 
template <typename E> 
class HuffTree { 
private: 
    HuffNode<E>* Root; // Tree root 

public: 
    HuffTree(E& val, int freq) // Leaf constructor 
    { 
        Root = new LeafNode<E>(val, freq); 
    } // Internal node constructor 
    
    HuffTree(HuffTree<E>* l, HuffTree<E>* r) { 
        Root = new IntlNode<E>(l->root(), r->root()); 
    }
    
    ~HuffTree() {} // Destructor 
    
    HuffNode<E>* root() { 
        return Root; 
    } // Get root 
    
    int weight() { 
        return Root->weight(); 
    } // Root weight 
};

// Build a Huffman tree from a collection of frequencies 
template <typename E> 
HuffTree<E>* buildHuff(HuffTree<E>** TreeArray, int count) { 
    heap<HuffTree<E>*, minTreeComp>* forest = new heap<HuffTree<E>*, minTreeComp>(TreeArray, count, count); 
    HuffTree<E> *temp1, *temp2, *temp3 = NULL; 
    while (forest->size() > 1) { 
        temp1 = forest->removefirst(); // Pull first two trees 
        temp2 = forest->removefirst(); // off the list 
        temp3 = new HuffTree<E>(temp1, temp2); 
        forest->insert(temp3); // Put the new tree back on list 
        delete temp1; // Must delete the remnants
        delete temp2; // of the trees we created 
    } 
    return temp3; 
}

int main() {
    // Test buildHuff function with character frequencies
    int charFreq[5] = { 10, 5, 20, 12, 7 };
    HuffTree<char>* charTrees[5];
    for (int i = 0; i < 5; i++) {
        char c = 'a' + i;
        charTrees[i] = new HuffTree<char>(c, charFreq[i]);
    }
    HuffTree<char>* huffChar = buildHuff(charTrees, 5);
    cout << "Root weight of huffChar: " << huffChar->weight() << endl; // Expected output: 54

    // Test buildHuff function with integer frequencies
    int intFreq[4] = { 20, 15, 10, 5 };
    HuffTree<int>* intTrees[4];
    for (int i = 0; i < 4; i++) {
        intTrees[i] = new HuffTree<int>(i+1, intFreq[i]);
    }
    HuffTree<int>* huffInt = buildHuff(intTrees, 4);
    cout << "Root weight of huffInt: " << huffInt->weight() << endl; // Expected output: 50

    // Test basic functionality of HuffTree and its subclasses
    LeafNode<char> leafChar('k', 3);
    IntlNode<char> intlChar(&leafChar, &leafChar);
    cout << "Leaf weight: " << leafChar.weight() << endl; // Expected output: 3
    cout << "Internal weight: " << intlChar.weight() << endl; // Expected output: 6

    return 0;
}