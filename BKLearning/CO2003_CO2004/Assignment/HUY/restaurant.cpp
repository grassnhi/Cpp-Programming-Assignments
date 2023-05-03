#include "main.h"

class nodeList {
public:
	int ID;
	nodeList* next;
	nodeList(int ID) {
		this->ID = ID;
		next = NULL;
	}
};
class List {
private:
	nodeList* head;
	nodeList* tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	~List() {
		while (head != NULL) {
			nodeList* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void push(int ID) {
		if (head == NULL) {
			head = tail = new nodeList(ID);
		}
		else {
			deleteNode(ID);
			if (head == NULL)head = tail = new nodeList(ID);
			else {
				tail->next = new nodeList(ID);
				tail = tail->next;
			}
		}
	}
	int latest() {
		return head->ID;
	}
	void deleteNode(int ID) {
		nodeList* temp = head;
		while (temp != NULL && temp->ID == ID) {
			nodeList* needDelete = temp;
			if (temp == tail) tail = tail->next;
			head = head->next;
			temp = temp->next;
			delete needDelete;
		}
		while (temp != NULL && temp->next != NULL) {
			if (temp->next->ID == ID) {
				nodeList* needDelete = temp->next;
				if (needDelete == tail) {
					tail = temp;
				}
				temp->next = temp->next->next;
				delete needDelete;
			}
			temp = temp->next;
		}
	}
};
class heapNode {
public:
	int ID;
	string name;
	int result;
	int priority;
	int order;
	heapNode(int  ID, string name, int result, int priority) {
		this->ID = ID;
		this->name = name;
		this->result = result;
		this->priority = priority;
		this->order = 1;
	}
};
class resHeap {
private:
	vector<heapNode*> vc;
	int size;
public:
	resHeap() {
		vc = vector<heapNode*>(MAXSIZE);
		for (int i = 0; i < MAXSIZE; i++) {
			vc[i] = NULL;
		}
		size = 0;
	}
	~resHeap() {
		for (int i = 0; i < size; i++) {
			heapNode* temp = vc[i];
			vc[i] = NULL;
			delete temp;
		}
	}
	void push(int ID, string name, int result) {
		int maxPriority = 0;
		for (int i = 0; i < size; i++) {
			if (vc[i]->priority >= maxPriority) maxPriority = vc[i]->priority + 1;
		}
		heapNode* item = new heapNode(ID, name, result, maxPriority);
		vc[size] = item;
		size++;
		reHeapUp(size - 1);
	}
	void swap(int a, int b) {
		heapNode* c = vc[a];
		vc[a] = vc[b];
		vc[b] = c;
	}
	void reHeapUp(int position) {
		if (position == 0)return;
		int parent = (position - 1) / 2;
		if (compare(position, parent)) {
			swap(position, parent);
			reHeapUp(parent);
		}
		return;
	}
	bool compare(int position, int n) {
		if (vc[position]->order < vc[n]->order) {
			return true;
		}
		else if (vc[position]->order == vc[n]->order) {
			if (vc[position]->priority < vc[n]->priority) return true;
		}
		return false;
	}
	heapNode* pop() {
		heapNode* item = vc[0];
		vc[0] = vc[size - 1];
		vc[size - 1] = NULL;
		size--;
		reHeapDown(0);
		return item;
	}
	void reHeapDown(int position) {
		int leftChild = position * 2 + 1;
		int rightChild = position * 2 + 2;
		if (leftChild <= size - 1) {
			int smallChild = leftChild;
			if (rightChild <= size - 1) {
				if (compare(rightChild, leftChild)) smallChild = rightChild;
			}
			if (compare(smallChild, position)) {
				swap(smallChild, position);
				reHeapDown(smallChild);
			}
		}
	}
	bool check(string name) {
		for (int i = 0; i < size; i++) {
			if (vc[i]->name == name) return true;
		}
		return false;
	}
	void add(string name) {
		for (int i = 0; i < size; i++) {
			if (vc[i]->name == name) {
				vc[i]->order++;
				swap(i, size - 1);
				size--;
				reHeapDown(i);
				if (i < size) reHeapUp(i);
				size++;
				reHeapUp(size - 1);
				break;
			}
		}
	}
	int earliest() {
		int min = 0;
		for (int i = 0; i < size; i++) {
			if (vc[i]->priority < vc[min]->priority) min = i;
		}
		return vc[min]->ID;
	}
	void deleteListID(vector<int>& listID) {
		int n = listID.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (vc[foundIndex(listID[j])]->priority > vc[foundIndex(listID[j + 1])]->priority) {
					int temp = listID[j];
					listID[j] = listID[j + 1];
					listID[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			deleteNode(listID[i]);
		}
	}
	int foundIndex(int ID) {
		for (int i = 0; i < size; i++) {
			if (vc[i]->ID == ID) return i;
		}
		return -1;
	}
	void deleteNode(int ID) {
		int foundIdx = -1;
		for (int i = 0; i < size; i++) {
			if (vc[i]->ID == ID) {
				foundIdx = i;
				break;
			}
		}
		if (foundIdx == -1) return;
		heapNode* temp = vc[foundIdx];
		vc[foundIdx] = vc[size - 1];
		vc[size - 1] = NULL;
		delete temp;
		size--;
		reHeapDown(foundIdx);
		if (foundIdx < size) reHeapUp(foundIdx);
	}
	int sizeofresHeap() {
		return size;
	}
	int found(string name) {
		for (int i = 0; i < size; i++) {
			if (vc[i]->name == name) return vc[i]->ID;
		}
		return -1;
	}
	int foundNum(string name) {
		for (int i = 0; i < size; i++) {
			if (vc[i]->name == name) return vc[i]->order;
		}
		return -1;
	}
	void print() {
		print(0);
	}
	void print(int i) {
		if (i >= size) return;
		cout << vc[i]->ID << "-" << vc[i]->order << "\n";
		print(2 * i + 1);
		print(2 * i + 2);
	}
};
class AVLNode {
public:
	int ID;
	string name;
	int result;
	AVLNode* left;
	AVLNode* right;
	AVLNode(int ID, string name, int result) {
		this->ID = ID;
		this->name = name;
		this->result = result;
		left = NULL;
		right = NULL;
	}
};
class AVLTree {
private:
	AVLNode* root;
	int size;
public:
	AVLTree() {
		root = NULL;
		size = 0;
	}
	~AVLTree() {
		deleteforAVLTree(root);
	}
	void deleteforAVLTree(AVLNode* root) {
		if (root == NULL) return;
		deleteforAVLTree(root->left);
		deleteforAVLTree(root->right);
		delete root;
	}
	int height(AVLNode* root) {
		if (root == NULL) return 0;
		int lh = height(root->left);
		int rh = height(root->right);
		return (lh > rh ? lh : rh) + 1;
	}
	int getBalance(AVLNode* root) {
		if (root == NULL) return 0;
		return height(root->left) - height(root->right);
	}
	AVLNode* rightRotate(AVLNode* y)
	{
		AVLNode* x = y->left;
		AVLNode* T2 = x->right;
		x->right = y;
		y->left = T2;
		return x;
	}
	AVLNode* leftRotate(AVLNode* x)
	{
		AVLNode* y = x->right;
		AVLNode* T2 = y->left;
		y->left = x;
		x->right = T2;
		return y;
	}
	void insert(int ID, string name, int result) {
		if (size >= MAXSIZE / 2) return;
		root = insert(root, ID, name, result);
		size++;
	}
	AVLNode* insert(AVLNode* root, int ID, string name, int result) {
		if (root == NULL) return new AVLNode(ID, name, result);
		if (result < root->result) {
			root->left = insert(root->left, ID, name, result);
		}
		else if (result >= root->result) {
			root->right = insert(root->right, ID, name, result);
		}
		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0) {
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) <= 0) {
			return leftRotate(root);
		}
		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}
	void remove(int ID) {
		bool check = false;
		root = remove(root, ID, check);
		if (check == true) size--;
	}
	AVLNode* remove(AVLNode* root, int ID, bool& check) {
		if (root == NULL) return root;
		if (root->ID != ID) {
			root->left = remove(root->left, ID, check);
			root->right = remove(root->right, ID, check);
		}
		else {
			check = true;
			if (root->left == NULL || root->right == NULL) {
				AVLNode* temp = root;
				root = (root->left != NULL ? root->left : root->right);
				delete temp;
			}
			else {
				AVLNode* temp = root->right;
				while (temp->left != NULL) temp = temp->left;
				root->name = temp->name;
				root->ID = temp->ID;
				root->result = temp->result;
				root->right = remove(root->right, temp->ID, check);
			}
		}
		if (root == NULL) return root;
		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0) {
			return rightRotate(root);
		}
		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) <= 0) {
			return leftRotate(root);
		}
		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}
	bool search(string name) {
		bool check = false;
		search(root, name, check);
		return check;
	}
	void search(AVLNode* root, string name, bool& check) {
		if (root == NULL) return;
		if (root->name != name) {
			search(root->left, name, check);
			search(root->right, name, check);
		}
		else {
			check = true;
			return;
		}
	}
	void print(resHeap* rheap) {
		int h = height(root);
		for (int i = 1; i <= h; i++) {
			printGivenLevel(root, i, rheap);
		}
	}
	void printGivenLevel(AVLNode* root, int level, resHeap* rheap) {
		if (root == NULL) return;
		if (level == 1) {
			cout << root->ID << "-" << root->result << "-" << rheap->foundNum(root->name) << "\n";
		}
		else if (level > 1) {
			printGivenLevel(root->left, level - 1, rheap);
			printGivenLevel(root->right, level - 1, rheap);
		}
	}
	int sizeofAVL() {
		return size;
	}
	void deleteAll(resHeap* rheap, List* listres, vector<bool>& boolofID) {
		vector<int> listID;
		deleteAll(root, listID, listres, boolofID);
		rheap->deleteListID(listID);
		root = NULL;
		size = 0;
	}
	void deleteAll(AVLNode* root, vector<int>& listID, List* listres, vector<bool>& boolofID) {
		if (root == NULL) return;
		listID.push_back(root->ID);
		listres->deleteNode(root->ID);
		boolofID[root->ID] = false;
		deleteAll(root->left, listID, listres, boolofID);
		deleteAll(root->right, listID, listres, boolofID);
		delete root;
	}
};
class HashNode {
public:
	int ID;
	string name;
	int result;
	HashNode(int ID, string name, int result) {
		this->ID = ID;
		this->name = name;
		this->result = result;
	}
};
class HashTable {
private:
	HashNode** arr;
	int size;
public:
	HashTable() {
		arr = new HashNode * [MAXSIZE / 2];
		size = 0;
		for (int i = 0; i < MAXSIZE / 2; i++) {
			arr[i] = NULL;
		}
	}
	~HashTable() {
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i] != NULL) {
				HashNode* temp = arr[i];
				arr[i] = NULL;
				delete temp;
			}
		}
		delete[] arr;
	}
	int sizeofHash() {
		return size;
	}
	void insert(int ID, string name, int result) {
		if (size >= MAXSIZE / 2)return;
		int d = result % (MAXSIZE / 2);
		int count = 0;
		while (count != MAXSIZE / 2) {
			if (arr[d] == NULL) {
				arr[d] = new HashNode(ID, name, result);
				size++;
				break;
			}
			else {
				d++;
				d = d % (MAXSIZE / 2);
				count++;
			}
		}
	}
	void deleteNode(int ID) {
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i] != NULL && arr[i]->ID == ID) {
				HashNode* temp = arr[i];
				arr[i] = NULL;
				size--;
				delete temp;
				break;
			}
		}
	}
	bool search(string name) {
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i]->name == name) return true;
		}
		return false;
	}
	void print(resHeap* rheap) {
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i] != NULL) {
				cout << arr[i]->ID << "-" << arr[i]->result << "-" << rheap->foundNum(arr[i]->name) << "\n";
			}
		}
	}
	void printforCheck() {
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i] != NULL) {
				cout << arr[i]->ID << "-";
			}
		}
	}
	void deleteAll(resHeap* rheap, List* listres, vector<bool>& boolofID) {
		vector<int> listID;
		for (int i = 0; i < MAXSIZE / 2; i++) {
			if (arr[i] != NULL) {
				HashNode* temp = arr[i];
				arr[i] = NULL;
				listID.push_back(temp->ID);
				listres->deleteNode(temp->ID);
				boolofID[temp->ID] = false;
				delete temp;
			}
		}
		rheap->deleteListID(listID);
		size = 0;
	}
};
class HuffNode {
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
	virtual char val() = 0;
	virtual int priority() = 0;
	virtual HuffNode* left() = 0;
	virtual HuffNode* right() = 0;
};
class LeafNode : public HuffNode {
private:
	char it;
	int wgt;
	int prior;
public:
	LeafNode(char val, int freq) {
		it = val;
		wgt = freq;
		prior = 1;
	}
	int weight() { return wgt; }
	char val() { return it; }
	int priority() { return prior; }
	bool isLeaf() { return true; }
	HuffNode* left() { return NULL; }
	HuffNode* right() { return NULL; }
};
class IntlNode : public HuffNode {
private:
	HuffNode* lc;
	HuffNode* rc;
	int wgt;
	int prior;
public:
	IntlNode(HuffNode* l, HuffNode* r, int prior) {
		wgt = l->weight() + r->weight();
		lc = l;
		rc = r;
		this->prior = prior;
	}
	int weight() { return wgt; }
	int priority() { return prior; }
	bool isLeaf() { return false; }
	HuffNode* left() { return lc; }
	void setLeft(HuffNode* b) {
		lc = (HuffNode*)b;
	}
	HuffNode* right() { return rc; }
	void setRight(HuffNode* b) {
		rc = (HuffNode*)b;
	}
	char val() { return ' '; }
};
class HuffTree {
private:
	HuffNode* Root;
public:
	HuffTree(char val, int freq) {
		Root = new LeafNode(val, freq);
	}
	HuffTree(HuffTree* l, HuffTree* r, int prior) {
		Root = new IntlNode(l->root(), r->root(), prior);
	}
	~HuffTree() {}
	HuffNode* root() { return Root; }
	int weight() { return Root->weight(); }
};
class minHeap {
private:
	vector<HuffTree*> vc;
	int n;
public:
	minHeap(vector<HuffTree*> arr, int size) {
		vc = vector<HuffTree*>(size);
		n = 0;
		for (int i = 0; i < size; i++) {
			push(arr[i]);
		}
	}
	void push(HuffTree* item) {
		vc[n] = item;
		n++;
		reHeapUp(n - 1);
	}
	void swap(int a, int b) {
		HuffTree* c = vc[a];
		vc[a] = vc[b];
		vc[b] = c;
	}
	void reHeapUp(int position) {
		if (position == 0)return;
		int parent = (position - 1) / 2;
		if (compare(position, parent)) {
			swap(position, parent);
			reHeapUp(parent);
		}
		return;
	}
	bool compare(int position, int n) {
		if (vc[position]->root()->weight() < vc[n]->root()->weight()) {
			return true;
		}
		else if (vc[position]->root()->weight() == vc[n]->root()->weight()) {
			if (vc[position]->root()->isLeaf() == true && vc[n]->root()->isLeaf() == false) {
				return true;
			}
			else if (vc[position]->root()->isLeaf() == true && vc[n]->root()->isLeaf() == true) {
				if (int(vc[position]->root()->val()) < int(vc[n]->root()->val())) {
					return true;
				}
			}
			else if (vc[position]->root()->isLeaf() == false && vc[n]->root()->isLeaf() == false) {
				if (vc[position]->root()->priority() < vc[n]->root()->priority()) {
					return true;
				}
			}
		}
		return false;
	}
	HuffTree* pop() {
		HuffTree* item = vc[0];
		vc[0] = vc[n - 1];
		n--;
		reHeapDown(0);
		return item;
	}
	void reHeapDown(int position) {
		int leftChild = position * 2 + 1;
		int rightChild = position * 2 + 2;
		if (leftChild <= n - 1) {
			int smallChild = leftChild;
			if (rightChild <= n - 1) {
				if (compare(rightChild, leftChild)) smallChild = rightChild;
			}
			if (compare(smallChild, position)) {
				swap(smallChild, position);
				reHeapDown(smallChild);
			}
		}
	}
	int size() {
		return n;
	}
};
HuffTree* buildHuff(vector<HuffTree*> TreeArray, int count) {
	minHeap* forest = new minHeap(TreeArray, count);
	HuffTree* temp1, * temp2, * temp3 = NULL;
	int c = 1;
	if (forest->size() == 1) {
		return forest->pop();
	}
	while (forest->size() > 1) {
		temp1 = forest->pop();
		temp2 = forest->pop();
		c++;
		temp3 = new HuffTree(temp1, temp2, c);
		forest->push(temp3);
		delete temp1; 
		delete temp2; 
	}
	delete forest;
	return temp3;
}
void traverse(HuffNode* root, map<char, string>& result, int length, vector<string>& store) {
	if (root == NULL) return;
	if (root->isLeaf() == true) {
		string s = "";
		for (int i = 0; i < length; i++) {
			s = s + store[i];
		}
		result.insert({ root->val(), s });
	}
	else {
		store[length] = '0';
		traverse(root->left(), result, length + 1, store);
		store[length] = '1';
		traverse(root->right(), result, length + 1, store);
	}
}
void print(HuffNode* root) {
	if (root == NULL) return;
	if (root->isLeaf() == true) cout << root->val() << "-" << root->weight() << endl;
	print(root->left());
	print(root->right());
}
void deleteforHuffNode(HuffNode* root) {
	if (root == NULL) return;
	deleteforHuffNode(root->left());
	deleteforHuffNode(root->right());
	delete root;
}
int encode(string s) {
	map<char, int> mp;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		mp[s[i]]++;
	}
	if (mp.size() == 1) {
		int result = 0;
		for (int i = 0; i < size; i++) {
			result += pow(2, i);
		}
		return result;
	}
	vector<HuffTree*> vc;
	int n = mp.size();
	for (auto& c : mp) {
		vc.push_back(new HuffTree(c.first, c.second));
	}
	HuffTree* r = buildHuff(vc, n);
	HuffNode* root = r->root();
	map<char, string> result;
	int length = 0;
	vector<string> store(128);
	traverse(root, result, length, store);
	string temp = "";
	for (int i = size - 1; i >= 0; i--) {
		temp = result[s[i]] + temp;
		if (temp.length() >= 15) break;
	}
	if (temp.length() > 15) {
		temp = temp.substr(temp.length() - 15, 15);
	}
	int sum = 0;
	for (int i = temp.length() - 1; i >= 0; i--) {
		sum += (temp[i] - 48) * pow(2, temp.length() - i - 1);
	}
	delete r;
	deleteforHuffNode(root);
	return sum;
}
HashTable* hashTable = new HashTable();
AVLTree* avlTree = new AVLTree();
resHeap* rheap = new resHeap();
List* listres = new List();
vector<bool> boolofID(33, false);
void REG(string name) {
	if (rheap->check(name) == true) {
		rheap->add(name);
		listres->push(rheap->found(name));
	}
	else if (hashTable->sizeofHash() + avlTree->sizeofAVL() == MAXSIZE) {
		int result = encode(name);
		if (result % 3 == 0) {
			int ID = rheap->earliest();
			rheap->deleteNode(ID);
			hashTable->deleteNode(ID);
			avlTree->remove(ID);
			listres->deleteNode(ID);

			rheap->push(ID, name, result);
			hashTable->insert(ID, name, result);
			avlTree->insert(ID, name, result);
			listres->push(ID);
		}
		else if (result % 3 == 1) {
			int ID = listres->latest();
			rheap->deleteNode(ID);
			hashTable->deleteNode(ID);
			avlTree->remove(ID);
			listres->deleteNode(ID);

			rheap->push(ID, name, result);
			hashTable->insert(ID, name, result);
			avlTree->insert(ID, name, result);
			listres->push(ID);
		}
		else if (result % 3 == 2) {
			heapNode* temp = rheap->pop();
			hashTable->deleteNode(temp->ID);
			avlTree->remove(temp->ID);
			listres->deleteNode(temp->ID);

			rheap->push(temp->ID, name, result);
			hashTable->insert(temp->ID, name, result);
			avlTree->insert(temp->ID, name, result);
			listres->push(temp->ID);
			delete temp;
		}
	}
	else {
		int result = encode(name);
		if (result % 2 == 1 && hashTable->sizeofHash() < MAXSIZE / 2) {
			int ID = result % MAXSIZE + 1;
			while (boolofID[ID] == true) {
				ID++;
				if (ID > MAXSIZE) ID = ID % MAXSIZE;
			}
			hashTable->insert(ID, name, result);
			rheap->push(ID, name, result);
			listres->push(ID);
			boolofID[ID] = true;
		}
		else if (result % 2 == 1 && hashTable->sizeofHash() == MAXSIZE / 2) {
			int ID = result % MAXSIZE + 1;
			while (boolofID[ID] == true) {
				ID++;
				if (ID > MAXSIZE) ID = ID % MAXSIZE;
			}
			avlTree->insert(ID, name, result);
			rheap->push(ID, name, result);
			listres->push(ID);
			boolofID[ID] = true;
		}
		else if (result % 2 == 0 && avlTree->sizeofAVL() < MAXSIZE / 2) {
			int ID = result % MAXSIZE + 1;
			while (boolofID[ID] == true) {
				ID++;
				if (ID > MAXSIZE) ID = ID % MAXSIZE;
			}
			avlTree->insert(ID, name, result);
			rheap->push(ID, name, result);
			listres->push(ID);
			boolofID[ID] = true;
		}
		else if (result % 2 == 0 && avlTree->sizeofAVL() == MAXSIZE / 2) {
			int ID = result % MAXSIZE + 1;
			while (boolofID[ID] == true) {
				ID++;
				if (ID > MAXSIZE) ID = ID % MAXSIZE;
			}
			hashTable->insert(ID, name, result);
			rheap->push(ID, name, result);
			listres->push(ID);
			boolofID[ID] = true;
		}
	}
}
void CLE(int NUM) {
	if (NUM < 1) {
		hashTable->deleteAll(rheap, listres, boolofID);
	}
	else if (NUM > MAXSIZE) {
		avlTree->deleteAll(rheap, listres, boolofID);
	}
	else {
		rheap->deleteNode(NUM);
		hashTable->deleteNode(NUM);
		avlTree->remove(NUM);
		listres->deleteNode(NUM);
		boolofID[NUM] = false;
	}
}
void printHT() {
	hashTable->print(rheap);
}
void printAVL() {
	avlTree->print(rheap);
}
void printMH() {
	rheap->print();
}
void simulate(string filename)
{
	ifstream file;
	file.open(filename);
	string line;
	while (!file.eof()) {
		getline(file, line);
		if (line == "PrintHT") {
			printHT();
		}
		else if (line == "PrintAVL") {
			printAVL();
		}
		else if (line == "PrintMH") {
			printMH();
		}
		else {
			string func = "";
			int i = 0;
			int n = line.size();
			while (i != n && line[i] != ' ') {
				func += line[i];
				i++;
			}
			if (i == n) continue;
			i++;
			if (func == "REG") {
				string name = "";
				bool check = false;
				while (i != n && line[i] != ' ') {
					if (line[i] < 65 || (line[i] > 90 && line[i] < 97) || line[i] > 122) check = true;
					name += line[i];
					i++;
				}
				if (check == true) continue;
				if (name == "" || line[i] == ' ') continue;
				REG(name);
			}
			else if (func == "CLE") {
				int ID = 0;
				bool check = false;
				while (i != n && line[i] != ' ') {
					if (line[i] < 48 || line[i] > 57) check = true;
					ID = 10 * ID + line[i] - 48;
					i++;
				}
				if (check == true) continue;
				if (line[i] == ' ') continue;
				CLE(ID);
			}
		}
	}
	delete hashTable;
	delete avlTree;
	delete rheap;
	delete listres;
	return;
}
