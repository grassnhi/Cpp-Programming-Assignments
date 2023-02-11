/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTree.h
 * Author: LTSACH
 *
 * Created on 12 September 2020, 20:47
 */

#ifndef AVLTREE_H
#define AVLTREE_H



template< class Key, class Data>
void defaultProcessing(Key key, Data data){
	std::cout << "\t";
	std::cout << "[" << key << "," << data << "]";
}

template< class Key, class Data>
void printKey(int order, Key& key){
	std::cout << "[" << order << " : " << key <<  "]  ";
}


//////////////////////////////////////////////////////////////////
/////////////// CAVLTree
//////////////////////////////////////////////////////////////////
template< class Key, class Data>
class CAVLNode;

template<class Key>
class CTemporalMedianFilter;

template< class Key, class Data>
class CAVLTree
{
public:
	

public:
	CAVLTree(void);
	~CAVLTree(void);

public:
	bool insert(Key key, Data data);
	bool del(Key key);
	void traversal(void (*process)(Key& key, Data& data));
	void printKey();
	CAVLNode<Key, Data>* getNode(Key key);
	CAVLNode<Key, Data>* getNodeLargestSmallerThan(Key key);
	CAVLNode<Key, Data>* getSmallestGreaterThan(Key key);
	CAVLNode<Key, Data>* getNodeLargestSmallerThan(CAVLNode<Key, Data>* pNode);
	CAVLNode<Key, Data>* getSmallestGreaterThan(CAVLNode<Key, Data>* pNode);


protected:
	bool _iterDel(Key key);
	void delLeafNode(CAVLNode<Key, Data>* pDelNode);
	void delAndReplace(CAVLNode<Key, Data>* pDelNode, CAVLNode<Key, Data>* pNew);
	void updateForDeletion(CAVLNode<Key, Data>* pNode,  bool shorterOnLeft);

	void _insert(CAVLNode<Key, Data>*& pSubroot, Key key, Data data, bool& taller);
	void _iterInsert(Key key, Data data);
	void updateForInsertion(CAVLNode<Key, Data>* pNode);


	CAVLNode<Key, Data>* leftBalance(CAVLNode<Key, Data>* pSubroot, bool& taller);
	CAVLNode<Key, Data>* rightBalance(CAVLNode<Key, Data>* pSubroot, bool& taller);

	CAVLNode<Key, Data>* delLeftBalance(CAVLNode<Key, Data>* pSubroot, bool& shorter);
	CAVLNode<Key, Data>* delRightBalance(CAVLNode<Key, Data>* pSubroot, bool& shorter);

	CAVLNode<Key, Data>* rotateLeft(CAVLNode<Key, Data>* pSubroot);
	CAVLNode<Key, Data>* rotateRight(CAVLNode<Key, Data>* pSubroot);
	void _traversal(CAVLNode<Key, Data>* pRoot, void (*process)(Key& key, Data& data));
	void _printKey(CAVLNode<Key, Data>* pRoot, int& seq);

protected:
	CAVLNode<Key, Data>* m_pRoot;
};


template< class Key, class Data>
class CAVLNode
{
	friend class CAVLTree<Key, Data>;
	friend class CTemporalMedianFilter<Key>;
public:
	enum BALANCE_FACTOR {
		EQUAL_HEIGHT = 0,
		LEFT_HIGHER,
		RIGHT_HIGHER
	};

public:
	CAVLNode(void);
	CAVLNode(Key key, Data data);
	CAVLNode(CAVLNode* pParent, Key key, Data data);
	CAVLNode(Key key, Data data, CAVLNode* pLeft, CAVLNode* pRight);
	~CAVLNode(void);

public:
	Key getKey();
	void setKey(Key key);

	Data getData();
	void setData(Data data);

	CAVLNode* getLeft();
	CAVLNode* getRight();
	void setLeft(CAVLNode* pLeft);
	void setRight(CAVLNode* pRight);
	void insertDuplicate();
	int decRefCount();
	int incRefCount();
	int getRefCount();
	void setRefCount(int refCount);

protected:
	Key			m_key;
	Data		m_data;
	CAVLNode*	m_pLeft;
	CAVLNode*	m_pRight;
	CAVLNode*	m_pParent;
	BALANCE_FACTOR m_balanceFactor;
	int			m_refCount;
};


///////////////////////////////////////////////////////////////////////
template< class Key, class Data>
CAVLNode<Key, Data>::CAVLNode(void)
{
	m_pLeft = NULL;
	m_pRight = NULL;
	m_pParent = NULL;
	m_balanceFactor = EQUAL_HEIGHT;
	m_refCount = 1;
}

template< class Key, class Data>
CAVLNode<Key, Data>::CAVLNode(Key key, Data data)
{
	m_key = key;
	m_data = data;
	m_pLeft = NULL;
	m_pRight = NULL;
	m_pParent = NULL;
	m_balanceFactor = EQUAL_HEIGHT;
	m_refCount = 1;
}

template< class Key, class Data>
CAVLNode<Key, Data>::CAVLNode(CAVLNode* pParent, Key key, Data data){
	m_key = key;
	m_data = data;
	m_pParent = pParent;
	m_pLeft = NULL;
	m_pRight = NULL;
	m_balanceFactor = EQUAL_HEIGHT;
	m_refCount = 1;
}

template< class Key, class Data>
CAVLNode<Key, Data>::CAVLNode(Key key, Data data, CAVLNode* pLeft, CAVLNode* pRight){
	m_key = key;
	m_data = data;
	m_pLeft = pLeft;
	m_pRight = pRight;
	m_pParent = NULL;
	m_balanceFactor = EQUAL_HEIGHT;
	m_refCount = 1;
}


template< class Key, class Data>
CAVLNode<Key, Data>::~CAVLNode(void)
{
	//De-malloc data & key?
}

template< class Key, class Data>
Key CAVLNode<Key, Data>::getKey(){
	return m_key;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::setKey(Key key){
	m_key = key;
}

template< class Key, class Data>
Data CAVLNode<Key, Data>::getData(){
	return m_data;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::setData(Data data){
	m_data = data;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLNode<Key, Data>::getLeft(){
	return m_pLeft;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLNode<Key, Data>::getRight(){
	return m_pRight;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::setLeft(CAVLNode<Key, Data>* pLeft){
	m_pLeft = pLeft;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::setRight(CAVLNode<Key, Data>* pRight){
	m_pRight = pRight;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::insertDuplicate(){
}

template< class Key, class Data>
int CAVLNode<Key, Data>::decRefCount(){
	m_refCount--;
	return m_refCount;
}

template< class Key, class Data>
int CAVLNode<Key, Data>::incRefCount(){
	m_refCount++;
	return m_refCount;
}

template< class Key, class Data>
int CAVLNode<Key, Data>::getRefCount(){
	return m_refCount;
}

template< class Key, class Data>
void CAVLNode<Key, Data>::setRefCount(int refCount){
	m_refCount = refCount;
}
//================================================================
//CAVLTree:
////////////////////////////////////////////////////////////////////////
template< class Key, class Data>
bool CAVLTree<Key, Data>::insert(Key key, Data data){
	//bool taller;
	//_insert(m_pRoot, key, data, taller);
	//return true;
	_iterInsert(key, data);
	return true;
}

template< class Key, class Data>
bool CAVLTree<Key, Data>::del(Key key){
	return _iterDel(key);
}




template< class Key, class Data>
CAVLTree<Key, Data>::CAVLTree(void)
{
	m_pRoot = NULL;
}

template< class Key, class Data>
CAVLTree<Key, Data>::~CAVLTree(void)
{
	//Delete nodes
	if(m_pRoot != NULL) delete m_pRoot;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::getNode(Key key){
	CAVLNode<Key, Data>* pNode;

	pNode = m_pRoot;
	while(pNode != NULL){
		if(key < pNode->m_key)
			pNode = pNode->m_pLeft;
		else if(key > pNode->m_key)
			pNode = pNode->m_pRight;
		else
			break;
	}
	return pNode;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::getNodeLargestSmallerThan(Key key){
	CAVLNode<Key, Data>* pNode;

	pNode = getNode(key);
	if(pNode == NULL) return pNode;
	
	if(pNode->m_pLeft == NULL){
		//Smaller node is ancestor
		pNode = pNode->m_pParent;
		while(pNode != NULL){
			if(pNode->m_key >= key)
				pNode =  pNode->m_pParent; //go up
			else
				break; //the first smaller is found
		}
		return pNode;
	}
	else{
		//Smaller on the sub lefttree
		pNode = pNode->m_pLeft;
		if(pNode == NULL) return pNode;
		while(pNode->m_pRight != NULL){
			pNode = pNode->m_pRight;
		}
		return pNode;
	}
	
}
template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::getNodeLargestSmallerThan(CAVLNode<Key, Data>* pNode){
	if(pNode == NULL) return pNode;
	Key key = pNode->m_key;


	if(pNode->m_pLeft == NULL){
		//Smaller node is ancestor
		pNode = pNode->m_pParent;
		while(pNode != NULL){
			if(pNode->m_key >= key)
				pNode =  pNode->m_pParent; //go up
			else
				break; //the first smaller is found
		}
		return pNode;
	}
	else{
		//Smaller on the sub lefttree
		pNode = pNode->m_pLeft;
		if(pNode == NULL) return pNode;
		while(pNode->m_pRight != NULL){
			pNode = pNode->m_pRight;
		}
		return pNode;
	}
	
}
template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::getSmallestGreaterThan(Key key){
	CAVLNode<Key, Data>* pNode;

	pNode = getNode(key);
	if(pNode == NULL) return pNode;

	if(pNode->m_pRight == NULL){
		//Smaller node is ancestor
		pNode = pNode->m_pParent;
		while(pNode != NULL){
			if(pNode->m_key <= key)
				pNode =  pNode->m_pParent; //go up
			else
				break; //the first smaller is found
		}
		return pNode;
	}
	else{
		//NOT NULL
		pNode = pNode->m_pRight;
		if(pNode == NULL) return pNode;
		while(pNode->m_pLeft != NULL){
			pNode = pNode->m_pLeft;
		}
	}
	return pNode;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::getSmallestGreaterThan(CAVLNode<Key, Data>* pNode){
	if(pNode == NULL) return pNode;
	Key key = pNode->m_key;

	if(pNode->m_pRight == NULL){
		//Smaller node is ancestor
		pNode = pNode->m_pParent;
		while(pNode != NULL){
			if(pNode->m_key <= key)
				pNode =  pNode->m_pParent; //go up
			else
				break; //the first smaller is found
		}
		return pNode;
	}
	else{
		//NOT NULL
		pNode = pNode->m_pRight;
		if(pNode == NULL) return pNode;
		while(pNode->m_pLeft != NULL){
			pNode = pNode->m_pLeft;
		}
	}
	return pNode;
}


template< class Key, class Data>
bool CAVLTree<Key, Data>::_iterDel(Key key){
	//1. Find node to delete
	//2. Delete
	//3. Rebalance if necessary

	if(m_pRoot == NULL){
		return false;
	}

	CAVLNode<Key, Data>* pDelNode;

	pDelNode = m_pRoot;
	while(pDelNode != NULL){
		if(key < pDelNode->m_key)
			pDelNode = pDelNode->m_pLeft;
		else if(key > pDelNode->m_key)
			pDelNode = pDelNode->m_pRight;
		else{
			//found
			break;
		}
	}//while

	if(pDelNode == NULL)
		return false;
	if(pDelNode->decRefCount() > 0){
		return true;
	}

	//found node: pDelNode NOT  NULL
	if((pDelNode->m_pLeft == NULL) && (pDelNode->m_pRight == NULL)){
		delLeafNode(pDelNode);
	}
	else if((pDelNode->m_pLeft != NULL) && (pDelNode->m_pRight == NULL)){
		delAndReplace(pDelNode, pDelNode->m_pLeft);
	}
	else if((pDelNode->m_pLeft == NULL) && (pDelNode->m_pRight != NULL)){
		delAndReplace(pDelNode, pDelNode->m_pRight);
	}
	else{
		//Both of the left and the right NOT NULL
		CAVLNode<Key, Data>* pLeafNode;
		pLeafNode = pDelNode->m_pLeft;
		while(pLeafNode->m_pRight != NULL){
			pLeafNode = pLeafNode->m_pRight;
		}
		//COPY DATA
		pDelNode->m_key = pLeafNode->m_key;
		pDelNode->m_data = pLeafNode->m_data;
		pDelNode->m_refCount = pLeafNode->m_refCount;
		//DEL

		if(pLeafNode->m_pLeft == NULL)
			delLeafNode(pLeafNode);
		else{
			delAndReplace(pLeafNode, pLeafNode->m_pLeft);
		}
	}
	return true;
}

template< class Key, class Data>
void CAVLTree<Key, Data>::delLeafNode(CAVLNode<Key, Data>* pDelNode){ //checked
	CAVLNode<Key, Data>* pParent;
	pParent = pDelNode->m_pParent;
	if(pParent == NULL){
		//pDelNode is m_pRoot
		delete m_pRoot;
		m_pRoot = NULL;
	}
	else{
		if(pDelNode->m_key <= pParent->m_key){
			pParent->m_pLeft = NULL;
			delete pDelNode;
			updateForDeletion(pParent, true);
		}
		else{
			pParent->m_pRight = NULL;
			delete pDelNode;
			updateForDeletion(pParent, false);
		}
	}//if(pParent
}

template< class Key, class Data>
void CAVLTree<Key, Data>::delAndReplace(CAVLNode<Key, Data>* pDelNode,  CAVLNode<Key, Data>* pNew){

	CAVLNode<Key, Data>* pParent;

	pParent = pDelNode->m_pParent;
	pNew->m_pParent = pParent; //link to parent
	if(pParent == NULL){
		//pDelNode is m_pRoot
		delete m_pRoot;
		m_pRoot = pNew;
		m_pRoot->m_pParent = NULL;
	}
	else{
		if(pDelNode->m_key <= pParent->m_key){ //maybe equal: when copy data from the left's rightmost 
			pParent->m_pLeft = pNew;
			delete pDelNode;
			updateForDeletion(pParent, true);
		}
		else{
			pParent->m_pRight = pNew;
			delete pDelNode;
			updateForDeletion(pParent, false);
		}
	}//if(pParent
}

template< class Key, class Data>
void CAVLTree<Key, Data>::updateForDeletion(CAVLNode<Key, Data>* pNode, bool shorterOnLeft){
	CAVLNode<Key, Data>* pParent;
	bool shorter;

	shorter = true;
	while(shorter && (pNode!=NULL)){
		if(shorterOnLeft){
			switch(pNode->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pNode->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
					shorter = false;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					pNode->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					//go up
					pParent = pNode->m_pParent;
					if(pParent != NULL){
						if(pNode->m_key < pParent->m_key) shorterOnLeft = true;
						else shorterOnLeft = false;
					}
					pNode = pParent;

					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					//rebalance
					pParent = pNode->m_pParent;
					if(pParent == NULL){
						//pNode is m_pRoot
						m_pRoot = delRightBalance(pNode, shorter);
						m_pRoot->m_pParent = NULL;
						pNode = NULL; //stop
					}
					else{
						if(pNode->m_key < pParent->m_key){
							pParent->m_pLeft = delRightBalance(pNode, shorter); //link to child
							pParent->m_pLeft->m_pParent = pParent; //link to father
							pNode = pParent; //go up
							shorterOnLeft = true;
						}
						else{
							pParent->m_pRight = delRightBalance(pNode, shorter); //link to child
							pParent->m_pRight->m_pParent = pParent; //link to father
							pNode = pParent; //go up
							shorterOnLeft = false;
						}
					}
					break;
			}//switch
		}
		else{
			//onRight
			switch(pNode->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pNode->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
					shorter = false;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					//rebalance
					pParent = pNode->m_pParent;
					if(pParent == NULL){
						//pNode is m_pRoot
						m_pRoot = delLeftBalance(pNode, shorter);
						m_pRoot->m_pParent = NULL;
						pNode = NULL; //stop
					}
					else{
						if(pNode->m_key < pParent->m_key){
							pParent->m_pLeft = delLeftBalance(pNode, shorter); //link to child
							pParent->m_pLeft->m_pParent = pParent; //link to father
							pNode = pParent; //go up
							shorterOnLeft = true;
						}
						else{
							pParent->m_pRight = delLeftBalance(pNode, shorter); //link to child
							pParent->m_pRight->m_pParent = pParent; //link to father
							pNode = pParent; //go up
							shorterOnLeft = false;
						}
					}

					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					pNode->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					//go up
					pParent = pNode->m_pParent;
					if(pParent != NULL){
						if(pNode->m_key < pParent->m_key) shorterOnLeft = true;
						else shorterOnLeft = false;
					}
					pNode = pParent;
					
					break;
			}//switch
		}
	}
}


template< class Key, class Data>
void CAVLTree<Key, Data>::updateForInsertion(CAVLNode<Key, Data>* pNode){
	CAVLNode<Key, Data>* pParent;

	pParent = pNode->m_pParent;
	bool taller = true; //subtree grows in height
	
	while(taller && (pParent != NULL)){
		if(pNode->m_key < pParent->m_key){
			//Insertion of the left of pParent
			switch(pParent->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pParent->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
					//taller is still true
					//go up on the tree
					pNode = pParent;
					pParent = pParent->m_pParent;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					//pParent is a LEFT HIGHER
					if(pParent == m_pRoot)
						m_pRoot = pParent = leftBalance(pParent, taller);
					else{					
						//update tree's links
						CAVLNode<Key, Data>* pGrandParent;
						pGrandParent = pParent->m_pParent;

						pParent = leftBalance(pParent, taller);
						pParent->m_pParent = pGrandParent;

						if(pParent->m_key < pGrandParent->m_key)
							pGrandParent->m_pLeft = pParent;
						else
							pGrandParent->m_pRight = pParent;						
					}
					
					//taller decided after balancing
					//go up on the tree
					pNode = pParent;
					pParent = pParent->m_pParent;
					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					//pParent is a RIGHT HIGHER
					pParent->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					taller = false;
			}//switch
		}
		else{
			//Insertion of the right of pParent
			switch(pParent->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pParent->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
					//taller is still true
					//go up on the tree
					pNode = pParent;
					pParent = pParent->m_pParent;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					//pParent is a LEFT HIGHER
					pParent->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					taller = false;
					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					//pParent is a RIGHT HIGHER
					if(pParent == m_pRoot)
						m_pRoot = pParent = rightBalance(pParent, taller);
					else{
						//update tree's links
						CAVLNode<Key, Data>* pGrandParent;
						pGrandParent = pParent->m_pParent;

						pParent = rightBalance(pParent, taller);
						pParent->m_pParent = pGrandParent;

						if(pParent->m_key < pGrandParent->m_key)
							pGrandParent->m_pLeft = pParent;
						else
							pGrandParent->m_pRight = pParent;	
					}

					//taller decided after balancing
					//go up on the tree
					pNode = pParent;
					pParent = pParent->m_pParent;
			}//switch
		}	
	}//while

}

template< class Key, class Data>
void CAVLTree<Key, Data>::_iterInsert(Key key, Data data){
	//Steps:
	//1. Find the location where to insert
	//2. Insert
	//3. Rebalance if needed


	if(m_pRoot == NULL){
		m_pRoot = new CAVLNode<Key, Data>(NULL, key, data);
		return;
	}
	//m_pRoot not NULL
	CAVLNode<Key, Data>* pParent;
	CAVLNode<Key, Data>* pChild;

	//1. Find the location where to insert
	pParent = NULL;
	pChild = m_pRoot;
	while(pChild != NULL){
		if(key < pChild->m_key){
			//insert into the left subtree
			pParent = pChild;
			pChild = pChild->m_pLeft;
		}
		else if(key > pChild->m_key){
			//insert into the right subtree
			pParent = pChild;
			pChild = pChild->m_pRight;
		}
		else{
			//key found
			pChild->incRefCount();
			break;
		}
	}//while


	
	if(pChild == NULL){
		//2. Insert
		pChild =  new CAVLNode<Key, Data>(pParent, key, data);
		if(pChild->m_key < pParent->m_key)
			pParent->m_pLeft = pChild;
		else
			pParent->m_pRight = pChild;
		//3. Rebalance if necessary
		updateForInsertion(pChild);
	}

}
template< class Key, class Data>
CAVLNode<Key, Data>*  CAVLTree<Key, Data>::delLeftBalance(CAVLNode<Key, Data>* pSubroot, bool& shorter){
	CAVLNode<Key, Data>* pLeftTree;
	CAVLNode<Key, Data>* pRightTree;

	switch(pSubroot->m_balanceFactor){
		case CAVLNode<Key, Data>::LEFT_HIGHER:
			pLeftTree = pSubroot->m_pLeft;
			if(pLeftTree->m_balanceFactor == CAVLNode<Key, Data>::RIGHT_HIGHER){
				//Double rotation: checked
				pRightTree = pLeftTree->m_pRight;
				switch(pRightTree->m_balanceFactor){
					case CAVLNode<Key, Data>::LEFT_HIGHER:
						pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
						break;
					case CAVLNode<Key, Data>::EQUAL_HEIGHT:
						pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
					case CAVLNode<Key, Data>::RIGHT_HIGHER:
						pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
				}//switch(pLeftTree->m_balanceFactor){
				pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
				pSubroot->m_pLeft = rotateLeft(pLeftTree);
				pSubroot = rotateRight(pSubroot);
			}
			else{
				//Single rotation
				switch(pLeftTree->m_balanceFactor){
					case CAVLNode<Key, Data>::RIGHT_HIGHER:
						//not a case
						break;
					case CAVLNode<Key, Data>::LEFT_HIGHER: //checked
						pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
					
					case CAVLNode<Key, Data>::EQUAL_HEIGHT: //checked
						pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
						shorter = false;
						break;
				}//switch(pLeftTree->m_balanceFactor){

				pSubroot = rotateRight(pSubroot);
			}//else
			break;
		case CAVLNode<Key, Data>::EQUAL_HEIGHT:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
			shorter = false;
			break;
		case CAVLNode<Key, Data>::RIGHT_HIGHER:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			//shorter not changed
			break;
	}//switch pSubroot->m_balanceFactor

	return pSubroot;
}

template< class Key, class Data>
CAVLNode<Key, Data>*  CAVLTree<Key, Data>::delRightBalance(CAVLNode<Key, Data>* pSubroot, bool& shorter){
	CAVLNode<Key, Data>* pLeftTree;
	CAVLNode<Key, Data>* pRightTree;

	switch(pSubroot->m_balanceFactor){
		case CAVLNode<Key, Data>::LEFT_HIGHER:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			//shorter not changed
			break;
		case CAVLNode<Key, Data>::EQUAL_HEIGHT:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
			shorter = false;
			break;
		case CAVLNode<Key, Data>::RIGHT_HIGHER:
			pRightTree = pSubroot->m_pRight;
			if(pRightTree->m_balanceFactor == CAVLNode<Key, Data>::LEFT_HIGHER){ //checked
				//Left of Right: Double rotation
				pLeftTree = pRightTree->m_pLeft;
				switch(pLeftTree->m_balanceFactor){
					case CAVLNode<Key, Data>::LEFT_HIGHER:
						pRightTree->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
					case CAVLNode<Key, Data>::EQUAL_HEIGHT:
						pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
					case CAVLNode<Key, Data>::RIGHT_HIGHER:
						pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
						break;
				}//switch(pLeftTree->m_balanceFactor){
				pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
				pSubroot->m_pRight = rotateRight(pRightTree);
				pSubroot = rotateLeft(pSubroot);
			}
			else{
				//Right of Right: Single ratation
				switch(pRightTree->m_balanceFactor){
					case CAVLNode<Key, Data>::LEFT_HIGHER:
						//not a case
						break;
					case CAVLNode<Key, Data>::RIGHT_HIGHER: //checked
						pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
						break;
					case CAVLNode<Key, Data>::EQUAL_HEIGHT: //checked
						pRightTree->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
						pSubroot->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
						shorter = false;
						break;
				}//switch(pRightTree->m_balanceFactor){

				pSubroot = rotateLeft(pSubroot);
			}//else

			break;
	}//switch pSubroot->m_balanceFactor

	return pSubroot;
}


template< class Key, class Data>
CAVLNode<Key, Data>*  CAVLTree<Key, Data>::leftBalance(CAVLNode<Key, Data>* pSubroot, bool& taller){
	CAVLNode<Key, Data>* pLeftTree;
	CAVLNode<Key, Data>* pRightTree;

	pLeftTree = pSubroot->m_pLeft;
	switch(pLeftTree->m_balanceFactor){
		case CAVLNode<Key, Data>::LEFT_HIGHER:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			pSubroot = rotateRight(pSubroot);
			taller = false;
			break;
		case CAVLNode<Key, Data>::RIGHT_HIGHER:
			pRightTree = pLeftTree->m_pRight;
			switch(pRightTree->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
					pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					pLeftTree->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
					break;
			}//switch  pRightTree
			pRightTree->m_balanceFactor =  CAVLNode<Key, Data>::EQUAL_HEIGHT;
			//Rotate left
			pSubroot->m_pLeft = rotateLeft(pLeftTree);
			//Rotate right
			pSubroot = rotateRight(pSubroot);
			taller = false;
			break;
		case CAVLNode<Key, Data>::EQUAL_HEIGHT:
			//Impossible case
			break;
	}//switch pLeftTree->m_balanceFactor
	return pSubroot;
}



template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::rightBalance(CAVLNode<Key, Data>* pSubroot, bool& taller){
	CAVLNode<Key, Data>* pLeftTree;
	CAVLNode<Key, Data>* pRightTree;

	pRightTree = pSubroot->m_pRight;
	switch(pRightTree->m_balanceFactor){
		case CAVLNode<Key, Data>::LEFT_HIGHER:
			pLeftTree = pRightTree->m_pLeft;
			switch(pLeftTree->m_balanceFactor){
				case CAVLNode<Key, Data>::EQUAL_HEIGHT:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					break;
				case CAVLNode<Key, Data>::LEFT_HIGHER:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					pRightTree->m_balanceFactor = CAVLNode<Key, Data>::RIGHT_HIGHER;
					break;
				case CAVLNode<Key, Data>::RIGHT_HIGHER:
					pSubroot->m_balanceFactor = CAVLNode<Key, Data>::LEFT_HIGHER;
					pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
					break;
			}//switch  pRightTree
			pLeftTree->m_balanceFactor =  CAVLNode<Key, Data>::EQUAL_HEIGHT;
			//Rotate right
			pSubroot->m_pRight = rotateRight(pRightTree);
			//Rotate left
			pSubroot = rotateLeft(pSubroot);
			taller = false;
			
			break;
		case CAVLNode<Key, Data>::RIGHT_HIGHER:
			pSubroot->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			pRightTree->m_balanceFactor = CAVLNode<Key, Data>::EQUAL_HEIGHT;
			pSubroot = rotateLeft(pSubroot);
			taller = false;
			break;
		case CAVLNode<Key, Data>::EQUAL_HEIGHT:
			//Impossible case
			break;
	}//switch pLeftTree->m_balanceFactor
	return pSubroot;
}


template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::rotateLeft(CAVLNode<Key, Data>* pSubroot){
	CAVLNode<Key, Data>* pSubTree;
	CAVLNode<Key, Data>* pParent;
	CAVLNode<Key, Data>* pRightTree;

	pParent = pSubroot->m_pParent;
	pRightTree = pSubroot->m_pRight;
	pSubTree = pRightTree->m_pLeft;
	//Change parents
	pRightTree->m_pParent = pParent;
	pSubroot->m_pParent = pRightTree;
	if(pSubTree != NULL) pSubTree->m_pParent = pSubroot;

	//Update children's links
	pSubroot->m_pRight = pRightTree->m_pLeft;
	pRightTree->m_pLeft = pSubroot;
	//Return
	return pRightTree;
}

template< class Key, class Data>
CAVLNode<Key, Data>* CAVLTree<Key, Data>::rotateRight(CAVLNode<Key, Data>* pSubroot){
	CAVLNode<Key, Data>* pSubTree;
	CAVLNode<Key, Data>* pParent;
	CAVLNode<Key, Data>* pLeftTree;


	pParent = pSubroot->m_pParent;
	pLeftTree = pSubroot->m_pLeft;
	pSubTree = pLeftTree->m_pRight;
	//Change parents
	pLeftTree->m_pParent = pParent;
	pSubroot->m_pParent = pLeftTree;
	if(pSubTree != NULL) pSubTree->m_pParent = pSubroot;

	//Update children's links
	pSubroot->m_pLeft = pLeftTree->m_pRight;
	pLeftTree->m_pRight = pSubroot;
	//return
	return pLeftTree;
}


template< class Key, class Data>
void CAVLTree<Key, Data>::traversal(void (*process)(Key& key, Data& data)){
	_traversal(m_pRoot, (*process));
}

template< class Key, class Data>
void CAVLTree<Key, Data>::printKey(){
	int seq = 0;
	_printKey(m_pRoot, seq);
}

template< class Key, class Data>
void CAVLTree<Key, Data>::_traversal(CAVLNode<Key, Data>* pRoot, void (*process)(Key& key, Data& data)){
	if(pRoot == NULL) return;
	_traversal(pRoot->m_pLeft, (*process));
	(*process)(pRoot->m_key, pRoot->m_data);
	_traversal(pRoot->m_pRight, (*process));
}
template< class Key, class Data>
void CAVLTree<Key, Data>::_printKey(CAVLNode<Key, Data>* pRoot, int& seq){
	if(pRoot == NULL) return;
	_printKey(pRoot->m_pLeft, seq);
	std::cout << "\n[" << ++seq << " : " << pRoot->m_key <<  "]  ";
	_printKey(pRoot->m_pRight, seq);
}



#endif /* AVLTREE_H */

