/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: LTSACH
 *
 * Created on 12 September 2020, 17:11
 */

#ifndef AVL_H
#define AVL_H
#include "tree/BST.h"
#include "list/DLinkedList.h"
#include "stacknqueue/Queue.h"

#define XNode typename BST<K,V>::Node


template<class K, class V>
class AVL : public BST<K,V>{
public:
    void add(K key, V value=0){
        bool taller;
        this->pRoot = add(this->pRoot, new XNode(typename BST<K,V>::Entry(key, value)), taller);
        this->count += 1;
    }
    V remove(K key){
        V retValue = 0; //O: NULL
        bool success = false;
        bool shorter = false;
        this->pRoot = remove(this->pRoot, key, shorter, success, retValue);
        if(success) this->count -= 1;
        return retValue;
    }
    void println(){
        cout << "Tree height: " << this->height() << endl;
        cout << "Tree nodes:"  << endl;
        cout << this->toString(true) << endl;
    }
    DLinkedList<string> bfactor(){
        DLinkedList<string> list;
        Queue<XNode*> queue;
        queue.push(this->pRoot);
        while(!queue.empty()){
            XNode* pNode = queue.pop();
            if(pNode->bfactor == nEMPTY) list.add("EMPTY");
            else if(pNode->bfactor == nLH) list.add("LH");
            else if(pNode->bfactor == nEH) list.add("EH");
            else list.add("RH");
            
            if(pNode->bfactor == nEMPTY){
                delete pNode; //because alloc in [1] or [2]
                continue;
            } 
            if((pNode->pLeft == 0) && (pNode->pRight == 0) ) continue;
            
            if(pNode->pLeft != 0) queue.push(pNode->pLeft);
            else queue.push(new XNode()); //[1]
            if(pNode->pRight != 0) queue.push(pNode->pRight);
            else queue.push(new XNode()); //[2]
        }
        return list;
    }
private:
    /*
     Current tree:
                    45
                   /  \
                 33    72
                      /  \
                     55  84

    Adding 75:
                    45    : RH of RH
                   /  \
                 33    72
                      /  \
                     55  84
                        /
                       75    
     
    rotateLeft(at 45):
                    72
                   /  \
                 45    84
                / \    /
              33  55  75        
    
     */
    XNode* rotateLeft(XNode* root){
        XNode* newRoot = root->pRight;
        root->pRight = newRoot->pLeft;
        newRoot->pLeft = root;
        return newRoot;
    }
    
    /*
    Current tree:
                45
               /  \
             33    72
            /  \
          24    40
    
    Adding 15:
                45    : LH of LH => Rotate right
               /  \
             33    72
            /  \
          24    40
         /
       15     
    rotateRight(at 45):
             33
            /  \
          24    45
         /     /  \
       15     40   72
     *     
     */
    XNode* rotateRight(XNode* root){
        XNode* newRoot = root->pLeft;
        root->pLeft = newRoot->pRight;
        newRoot->pRight = root;
        return newRoot;
    }
    
    /*
     leftBalance:
     WHEN: 1/ a tree isLH, and
           2/ then add an item to the left sub-tree
           3/ result: the left sub-tree growing taller => leftBalance
     *********************************************************************
     * Notation: 
     *      >> node: (name:height)
     *      >> height: internal nodes depends on leaf nodes
     *********************************************************************
     * CASE [1]: LH-of-LH => one rotation
     *      >> Before adding: (X:H); tree's height: H+2
     *      >> After adding:  (X:H+1): tree's height: H+3 => need rotation
     ---------------------------------------------------------------------
                  root=>  (R:H+3)
                           /   \
                          /     \
          leftTree=> (LT:H+2)  (Z:H)
                       /  \
                      /    \
                   (X:H+1) (Y:H)
     
    => rotateRight(root:T)
              leftTree=>  (LT:H+2)   =>[EH]
                           /   \
                          /     \
                      (X:H+1) (R:H+1) =>[EH]
                               /  \   
                              /    \
                           (Y:H)  (Z:H)    
    
     RESULTS of CASE [1]
     * root (R)     : EH
     * leftTree (LT): EH
     * taller = false
     
     * CASE [2]:
     *      >> Before adding: (Y:H); tree's height: H+3
     *      >> After adding:  (Y:H+1); tree's height: H+4 => need rotation
     ---------------------------------------------------------------------
             root=>  (R:H+4)
                       /  \
                      /    \
   leftTree=>    (LT:H+3) (T:H+1)
                    /  \
                   /    \
                (X:H+1) (RT:H+2) <=rightTree(LH)
                       /  \
                      /    \
                   (Y:H+1)  (Z:H)
    
     * Two rotations:
    => 1. rotateLeft(leftTree:LT):
        *** note: height of X, Y, Z are not changed, height of LT, RT, and R depends on height of X, Y, Z
    
             root=>  (R:H+4)
                       /  \
                      /    \
      rightTree=> (RT:H+3) (T:H+1)
                    /  \
                   /    \
  leftTree=>  (LT:H+2) (Z:H)
                 /  \
                /    \
            (X:H+1) (Y:H+1)
    
    => 2. rotateRight(root:R):  
           rightTree=>    (RT:H+3) =>[EH]
                           /     \
                          /       \
               [EH]<= (LT:H+2)   (R:H+2) =>[RH]
                       /   \       / \
                      /     \     /   \
                  (X:H+1)(Y:H+1)(Z:H)(T:H+1)
     
    RESULTS of CASE [2]:
     * leftTree (LT)    : EH
     * root (R)         : RH
     * rightTree        : EH 
     * taller = false 
    
     * CASE [3]: ONLY HAPPENNED with H=0
     *      >> Before adding: (LT:1); tree's height: 2
     *      >> After adding:  (LT:2), (RT:1); tree's height: 3
     ---------------------------------------------------------------------
    
              root=>  (R:H+3)
                       /  \
                      /    \
       leftTree=> (LT:H+2) (T:H)
                    /  \
                   /    \
                (X:H) (RT:H+1) <= rightTree(EH)
                       /  \
                      /    \
                   (Y:H)   (Z:H)

    => 1. rotateLeft(leftTree:LT):
    
             root=>  (R:H+3)
                       /  \
                      /    \
     rightTree=>  (RT:H+2) (T:H)
                    /  \
                   /    \
   leftTree=> (LT:H+1) (Z:H)
                 /  \
                /    \
            (X:H)   (Y:H)
    
    => 2.rotateRight(root:R):  
               rightTree=> (RT:H+2) =>[EH]
                           /     \
                          /       \
               [EH]<= (LT:H+1)   (R:H+1) =>[EH]
                       /   \       / \
                      /     \     /   \
                  (X: H)  (Y:H) (Z:H) (T:H)
     
    RESULTS of CASE [3]:
     * leftTree (LT)    : EH
     * Root (R)         : EH
     * rightTree        : EH  
     * taller = false
      
     * CASE [4]:
     *      >> Before adding: (Z:H); tree's height: H+3
     *      >> After adding:  (Z:H+1); tree's height: H+4 => need rotation
     ---------------------------------------------------------------------
              root=>  (R:H+4)
                       /  \
                      /    \
       leftTree=> (LT:H+3)(T:H+1)
                    /  \
                   /    \
                (X:H+1) (RT:H+2) <= rightTree(RH)
                       /  \
                      /    \
                   (Y:H)   (Z:H+1)

    => 1. rotateLeft(leftTree:LT):
    
              root=>  (R:H+4)
                       /  \
                      /    \
      rightTree=> (RT:H+3) (T:H+1)
                    /  \
                   /    \
    leftTree=> (LT:H+2) (Z:H+1)
                 /  \
                /    \
            (X:H+1) (Y:H)
    
    => 2.rotateRight(root:R):  
               rightTree=> (RT:H+3) =>[EH]
                           /     \
                          /       \
               [LH]<= (LT:H+2)   (R:H+2) =>[EH]
                       /   \       / \
                      /     \     /   \
                (X:H+1)   (Y:H)(Z:H+1)(T:H+1)
     
    RESULTS of CASE [4]:
     * leftTree (LT)    : LH
     * Root (R)         : EH
     * rightTree        : EH  
     * taller           : false
     */
    
    XNode* leftBalance(XNode* root, bool& taller){
        XNode* leftTree = root->pLeft;
        XNode* newRoot = root;
        if(leftTree->isLH() ){ //CASE [1] (see AVLTest.h)
            newRoot = rotateRight(root);
            root->markEH();
            leftTree->markEH();
            taller = false;
        }
        else{
            XNode* rightTree = leftTree->pRight;
            if(rightTree->isLH() ){ //CASE [2]
                root->markRH();
                leftTree->markEH();
            }
            else if(rightTree->isEH() ){//CASE [3]
                root->markEH();
                leftTree->markEH();
            }
            else{ //CASE [4]
                root->markEH();
                leftTree->markLH();
            }
            rightTree->markEH();
            root->pLeft = rotateLeft(leftTree);
            newRoot = rotateRight(root);
            taller = false;
        }
        return newRoot;
    }
    
    /*
     rightBalance:
     WHEN: 1/ a tree isRH, and
           2/ then add an item to the right sub-tree
           3/ result: the right sub-tree growing taller => rightBalance
     *********************************************************************
     * Notation: 
     *      >> node: (name:height)
     *      >> height: internal nodes depends on leaf nodes
     *********************************************************************
     * CASE [1]: RH-of-RH => one rotation
     *      >> Before adding: (Z:H); tree's height: H+2
     *      >> After adding:  (Z:H+1): tree's height: H+3 => need rotation
     ---------------------------------------------------------------------
                          (R:H+3)
                           /   \
                          /     \
                       (X:H)  (RT:H+2)
                               /  \
                              /    \
                           (Y:H)   (Z:H+1)
     => rotateLeft(R)
                            (RT:H+2)
                             /   \
                            /     \
                        (R:H+1)   (Z:H+1)
                         /  \
                        /    \
                     (X:H)  (Y:H)
     RESULTS of CASE [1]:
     * root (R)         : EH
     * rightTree (RT)   : EH  
     * taller = false
     
     * CASE [2]: LH-of-RH => two rotations
     *      >> Before adding: (Z:H); tree's height: H+2
     *      >> After adding:  (Z:H+1): tree's height: H+3 => need rotation
     ---------------------------------------------------------------------
                                (R:H+4)      
                                 /   \
                                /     \
                            (X:H+1) (RT:H+3)
                                     /   \
                                    /     \
                                (LT:H+2) (T:H+1)
                                  /  \
                                 /    \
                              (Y:H) (Z:H+1)
    => 1. rotateRight(LT):
                                (R:H+4)      
                                 /   \
                                /     \
                            (X:H+1)   (LT:H+3)    
                                       /  \
                                      /    \ 
                                   (Y:H)  (RT:H+2)
                                           / \
                                          /   \
                                    (Z:H+1)  (T:H+1)
    
     => 2. rotateLeft(R):  
                                    (LT:H+3) =>[EH]
                                      /  \
                                     /    \
                         [LH]<= (R:H+2)  (RT:H+2) => [EH]
                                  / \       / \
                                 /   \     /   \
                            (X:H+1)(Y:H)(Z:H+1)(T:H+1)
     RESULTS of CASE [2]:
     * root (R)         : LH
     * leftTree(LT)     : EH
     * rightTree (RT)   : EH  
     * taller = false
     
     * CASE [3]: LH-of-RH => two rotations, ONLY HAPPENNED with H=0
     *      >> Before adding: (Z:H); tree's height: H+2
     *      >> After adding:  (Z:H): tree's height: H+3 => need rotation
     --------------------------------------------------------------------- 
                                (R:H+3)      
                                 /   \
                                /     \
                            (X:H)  (RT:H+2)
                                     /   \
                                    /     \
                                (LT:H+1) (T:H)
                                  /  \
                                 /    \
                              (Y:H)  (Z:H)
     
    => 1. rotateRight(RT):
                                (R:H+3)      
                                 /   \
                                /     \
                            (X:H)  (LT:H+2)      
                                    /  \
                                   /    \
                               (Y:H)    (RT:H+1)
                                         / \
                                        /   \
                                     (Z:H) (T:H)
     
    => 2. rotateLeft(R)
                                  (LT:H+2) => [EH]
                                   /   \
                                  /     \
                     [EH] <= (R:H+1)   (RT:H+1)  => [EH]
                               /  \       /  \
                              /    \     /    \
                           (X:H)  (Y:H) (Z:H) (T:H)
     
    RESULTS of CASE [3]:
     * root (R)         : EH
     * leftTree(LT)     : EH
     * rightTree (RT)   : EH  
     * taller = false 
     
    * CASE [4]: LH-of-RH => two rotations
     *      >> Before adding: (Z:H); tree's height: H+2
     *      >> After adding:  (Z:H): tree's height: H+3 => need rotation
     ---------------------------------------------------------------------  
                                (R:H+4)      
                                 /   \
                                /     \
                            (X:H+1) (RT:H+3)
                                     /   \
                                    /     \
                                (LT:H+2) (T:H+1)
                                  /  \
                                 /    \
                             (Y:H+1) (Z:H)     
     
    => rotateRight(RT):
                                (R:H+4)      
                                 /   \
                                /     \
                            (X:H+1)   (LT:H+3)    
                                       /  \
                                      /    \ 
                                 (Y:H+1)  (RT:H+2)
                                           / \
                                          /   \
                                       (Z:H)  (T:H+1)
        
    => rotateLeft(R):
                                    (LT:H+3) =>[EH]
                                      /  \
                                     /    \
                         [EH]<= (R:H+2)  (RT:H+2) => [RH]
                                  / \       / \
                                 /   \     /   \
                           (X:H+1)(Y:H+1)(Z:H)(T:H+1)     
     
     RESULTS of CASE [3]:
     * root (R)         : EH
     * leftTree(LT)     : EH
     * rightTree (RT)   : RH  
     * taller = false 
     */
    XNode* rightBalance(XNode* root, bool& taller){
        XNode* rightTree = root->pRight;
        XNode* newRoot = root;
        if(rightTree->isRH()){ //CASE [1]
            newRoot = rotateLeft(root);
            root->markEH();
            rightTree->markEH();
            taller = false;
        }
        else{
            XNode* leftTree = rightTree->pLeft;
            if(leftTree->isRH() ){ //CASE [2]
                root->markLH();
                rightTree->markEH();
            }
            else if(leftTree->isEH()){ //CASE [3]
                rightTree->markEH();
                root->markEH();
            }
            else{ //CASE [4] - LH
                root->markEH();
                rightTree->markRH();
            }
            leftTree->markEH();
            root->pRight = rotateRight(rightTree);
            newRoot = rotateLeft(root);
            taller = false;
        }
        return newRoot;
    }
    
    XNode* add(XNode* root, XNode* newNode, bool& taller){
        if(root == 0){
            taller = true;
            return newNode;
        }
        
        XNode* newRoot = root;
        if(newNode->data.key < root->data.key){
            root->pLeft = add(root->pLeft, newNode, taller);
            if(taller){
                if(root->isLH() ) newRoot = leftBalance(root, taller);
                else if(root->isEH() ) root->markLH(); 
                else{
                    root->markEH();
                    taller = false;
                }
            }//if(taller)
        }
        else{
            //newNode->data.key >= root->data.key
            root->pRight = add(root->pRight, newNode, taller);
            if(taller){
                if(root->isLH() ){
                    root->markEH();
                    taller = false;
                }
                else if(root->isEH()) root->markRH();
                else  newRoot = rightBalance(root, taller);
            }//if(taller)
        }//if
        return newRoot;
    }//method:add
    
    /**
     * deleteLeftBalance: will be called when remove a node on the right subtree
     * @param root
     * @param shorter
     * @return 
     */
    XNode* deleteLeftBalance(XNode* root, bool& shorter){
        XNode* newRoot = root;
        
        if(root->isRH() ){ //CASE [1]
            root->markEH();
        }
        else if(root->isEH() ){ //CASE [2]
            root->markLH();
            shorter = false;
        }
        else{
            //root: LH + delete on right + after delete: tree is shorter
            //similar to: lefBalance
            XNode* leftTree = root->pLeft;
            if(leftTree->isRH() ){
                XNode* rightTree = leftTree->pRight;
                if(rightTree->isRH() ){ //CASE [3]
                    leftTree->markLH();
                    root->markEH();
                }
                else if(rightTree->isEH()){ //CASE [4]
                    root->markRH();
                    leftTree->markEH();
                }
                else{ //CASE [5]
                    root->markRH();
                    leftTree->markEH();
                }
                rightTree->markEH();
                root->pLeft = rotateLeft(leftTree);
                newRoot = rotateRight(root);
            }
            else{
                if(!leftTree->isEH() ){
                    root->markEH();
                    leftTree->markEH();
                }
                else{
                    root->markLH();
                    leftTree->markRH();
                    shorter = false;
                }
                newRoot = rotateRight(root);
            }//if(leftTree->isRH() )
        }//if(root->isRH() )
        return newRoot;
    }
    
    /**
     * deleteRightBalance: will be called when remove nodes on the left subtree
     * @param root
     * @param shorter
     * @return 
     */
    XNode* deleteRightBalance(XNode* root, bool& shorter){
        XNode* newRoot = root;
        if(root->isLH()){
            root->markEH();
        }
        else if(root->isEH()){
            root->markRH();
            shorter = false;
        }
        else{
            XNode* rightTree = root->pRight;
            if(rightTree->isLH()){
                XNode* leftTree = rightTree->pLeft;
                if(leftTree->isLH()){
                    rightTree->markRH();
                    root->markEH();
                }
                else if(leftTree->isEH()){
                    root->markLH();
                    rightTree->markEH();
                }
                else{
                    root->markLH();
                    rightTree->markEH();
                }
                leftTree->markEH();
                root->pRight = rotateRight(rightTree);
                newRoot = rotateLeft(root);
            }
            else{
                if(!rightTree->isEH()){
                    root->markEH();
                    rightTree->markEH();
                }
                else{
                    root->markRH();
                    rightTree->markLH();
                    shorter = false;
                }
                newRoot = rotateLeft(root);
            }
        }//if(root->isLH())
        return newRoot;
    }
    /**
     * 
     * @param root
     * @param key
     * @param shorter
     * @param success
     * @param retValue
     * @return 
     */
    XNode* remove(XNode* root, K key, bool& shorter, bool success, V& retValue){
        if(root == 0){
            shorter = false;
            success = false;
            return 0;
        }
        
        XNode* newRoot = root;
        if(key < root->data.key){
            root->pLeft = remove(root->pLeft, key, shorter, success, retValue);
            if(shorter) newRoot = deleteRightBalance(root, shorter);
        }
        else if(key > root->data.key){
            root->pRight = remove(root->pRight, key, shorter, success, retValue);
            if(shorter) newRoot = deleteLeftBalance(root, shorter);
        }
        else{
            //found key:
            XNode* deleteNode = root;
            if(deleteNode->pRight == 0){
                newRoot = root->pLeft;
                success = true;
                shorter = true;
                delete deleteNode;
                return newRoot;
            }
            else if(deleteNode->pLeft == 0){
                newRoot = root->pRight;
                success = true;
                shorter = true;
                delete deleteNode;
                return newRoot;
            }
            else{
                //has left and right
                V backup = root->data.value; //backup returned value (pRoot->data.value)
            
                XNode* largestOnLeft = root->pLeft;
                while(largestOnLeft->pRight != 0) largestOnLeft = largestOnLeft->pRight;
                
                root->data = largestOnLeft->data;
                root->pLeft = remove(root->pLeft, largestOnLeft->data.key, shorter, success, retValue);
                if(shorter){
                    newRoot = deleteRightBalance(root, shorter);
                }
                
                retValue = backup;
            }// end: found key
        }//if(key < root->data.key)
        return newRoot;
    }
};


#endif /* AVL_H */

