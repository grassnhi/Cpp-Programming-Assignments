#include "main.h"

const int TABLE_SIZE = MAXSIZE/2;

class DLinkedList{
public:
    class Table{
    private:
        int ID; // ID bàn
        int name; // tên khách == result
        int NUM; // số lần gọi món

        Table* next;
        Table* prev; 
        
        friend class DLinkedList;
    public:
        Table(){
            this->next = next;
            this->prev = prev;
        }
        
        Table(int ID, int name, int NUM = 0, Table* next = nullptr, Table* prev = nullptr)
        {
            this->ID = ID;
            this->name = name;
            this->NUM = NUM;
            this->next = next;
            this->prev = prev;
        }
    };
protected:
    int count;
    Table* head;
    Table* tail;
    
public:
    DLinkedList(int count = 0, Table* head = nullptr, Table* tail = nullptr){
        this->count = count;
        this->head = head;
        this->tail = tail;
    }
    ~DLinkedList(){
        clear();
    }

    void    add(int ID, int name, int NUM = 0){
        Table* node = new Table(ID, name, NUM);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        count++;
    }

    int     size(){
        return count;
    }

    bool    empty(){
        return count == 0;
    }

    void    set(int index, int e);

    bool    contains(int item){
        Table* tmp = head;
        int i = 0;
        while (tmp != nullptr) {
            if (tmp->name == item) {
                return true;
            }
            tmp = tmp->next;
            i++;
        }
        return false;
    }

    void    removeAt(int index){
        if(index < 1 || index > count || head == nullptr){
            return;
        }else if(index == 1){
            if(head == tail){
                head = tail = nullptr;
                count--;
            }
            head = head->next;
            head->prev = nullptr;
            count--;
        }else if(index == count){
            tail = tail->prev;
            tail->next = nullptr;
            count--;
        }else{
            if(index < count /2){
                Table* tmp = head;
                Table* prev = nullptr;
                for(int i = 0; i < index; i++){
                    prev = tmp;
                    tmp = tmp->next;
                }
                prev->next = tmp->next;
                tmp = tmp->next;
                tmp->prev = prev;
            }else{
                Table* tmp = tail;
                Table* follow = nullptr;
                for(int i = count - 1; i > index; i--){
                    follow = tmp;
                    tmp = tmp->prev;
                }
                follow->prev = tmp->prev;
                tmp = tmp->prev;
                tmp->next = follow;
            }
            count--;
        }
    }

    void    clear(){
        Table* tmp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        tail = nullptr;
        count = 0;
    }
};

class HuffNode
{
public:
    virtual ~HuffNode(){}
    virtual int weight() = 0;
    virtual char character() = 0;
    virtual bool isLeaf() = 0;
    virtual HuffNode* leftNode() const = 0;
    virtual HuffNode* rightNode() const = 0;
};

class LeafNode : public HuffNode
{
private:
    char chars;
    int fred;

public:
    LeafNode(char chars, int fred = 0){
        this->chars = chars;
        this->fred = fred;
    }

    int weight(){
        return fred;
    }

    char character(){
        return chars;
    }

    bool isLeaf() { 
        return true; 
    }

    virtual HuffNode* leftNode() const { return nullptr; }
    virtual HuffNode* rightNode() const { return nullptr; }

};

class IntNode : public HuffNode
{
private:
    int fred;
    HuffNode* left;
    HuffNode* right;
    
public:
    IntNode(HuffNode* left = nullptr, HuffNode* right = nullptr){
        fred = left->weight() + right->weight();
        this->left = left;
        this->right = right;
    }
    ~IntNode(){
        left = nullptr;
        right = nullptr;
    }

    int weight(){
        return fred;
    }

    bool isLeaf() { 
        return false; 
    }

    HuffNode* leftNode() const{
        return left;
    }

    void setLeft(HuffNode* left){
        this->left = left;
    }

    HuffNode* rightNode() const{
        return right;
    }

    void setRight(HuffNode* right){
        this->right = right;
    }

    virtual char character() { return '\0'; }
};

class CompareNodes {
public:
    bool operator()(HuffNode* a, HuffNode* b) const {
        if (a->weight() == b->weight()) {
            if (a->isLeaf() && b->isLeaf()) {
                // ưu tiên in hoa
                if (isupper(a->character()) && !isupper(b->character())) {
                    return true; 
                } else if (!isupper(a->character()) && isupper(b->character())) {
                    return false;
                }
            } else {
                // nếu cả 2 node không phải đều là node lá thì node nào được add vào queue trước sẽ được xử lý trước
                return a < b;
            }
        }

        return a->weight() > b->weight();
    }
};

class HuffTree
{
private:
    HuffNode* root;
    

    void buildEncodingMap(HuffNode* node, string code) {
        if (node == NULL) {
            return;
        }
        
        if (node->leftNode() == NULL && node->rightNode() == NULL) {
            encodingMap[node->character()] = code;
            return;
        }
        
        buildEncodingMap(node->leftNode(), code + "0");
        buildEncodingMap(node->rightNode(), code + "1");
    }

public:
    unordered_map<char, string> encodingMap;

    HuffTree(){
        this->root = nullptr;
    }

    void buildTree(string name) {
        unordered_map<char, int> freqMap;
        
        for (char c : name) {
            freqMap[c]++;
        }

        priority_queue<HuffNode*, vector<HuffNode*>, CompareNodes> minHeap;
        for (auto entry : freqMap) {
            minHeap.push(new LeafNode(entry.first, entry.second));
        }

        while (minHeap.size() > 1) {
            auto left = minHeap.top();
            minHeap.pop();
            auto right = minHeap.top();
            minHeap.pop();
            auto internal = new IntNode(left, right);
            minHeap.push(internal);
            this->root = internal;
        }

        buildEncodingMap(this->root, "");
    }

    ~HuffTree(){
        clear();
    }

    // Hàm chuyển đổi sang mã Huffman
    int encode(string name){
        string result = "";
        
        for (char c : name) {
            string code = "";
            code = encodingMap.at(c);
            result += code;
        }
        result = result.substr(max(0, (int)result.size() - 15)); // chỉ lấy tối đa 15 số từ bên phải
        int decimal = stoi(result, nullptr, 2);
        return decimal; 
    }

    void clear(HuffNode* node) {
        if (node == nullptr) {
            return;
        }
        if(node->leftNode()){
            clear(node->leftNode());
        }
        if(node->rightNode()){
            clear(node->rightNode());
        }
        delete node;
    }

    void clear(){
        clear(this->root);
        this->root = nullptr;
        encodingMap.clear();
    }

};

class HashMap
{
public:
    class Entry
    {
    private:
        int key; // name (result) -> hashCode
        int value; // name (result)
        int ID; // table ID
        friend class HashMap;
    public:
        Entry(int key, int value, int ID){
            this->key = key;
            this->value = value;
            this->ID = ID;
        }
    };
    
protected:
    Entry** table;
    int capacity;
    int count;
public:
    HashMap(){
        this->capacity = TABLE_SIZE;
        this->count = 0;
        this->table = new Entry*[capacity];
        for(int i = 0; i < capacity; i++){
            this->table[i] = nullptr;
        }
    }

    ~HashMap(){
        deleteMap();
    }

    int hashFunct(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value, int ID){
        int index = this->hashFunct(key);

        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }
        if (table[index] != nullptr) {
            table[index]->value = value;
            table[index]->ID = ID;
        }else{
            table[index] = new Entry(key, value, ID);
            count++;
        }
    }

    int getValue(int key){
        int index = this->hashFunct(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }
        if (table[index] == nullptr) {
            return -1;
        } else {
            return table[index]->value;
        }
    }

    void remove(int key){
        int index = this->hashFunct(key);
        
        while (table[index] != nullptr && table[index]->key != key) {
            index = hashFunct(index + 1);
        }

        if (table[index] == nullptr) {
            return;
        }else{
            delete table[index];
            table[index] = nullptr;
            count--;
        }
    }

    void deleteMap(){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr) { 
                delete table[i];
                table[i] = nullptr;
            }
        }
        delete[] table;
        this->count = 0;
    }

    void printTable() {
        for(int i = 0; i < capacity; i++) {
            if(table[i] != nullptr) {
                cout << table[i]->ID << "-" << table[i]->value << endl;
            }
        } 
    }
};

class AVLTree
{
public:
    class Node
    {
    public:
        enum BalanceValue
        {
            LH = -1,
            EH = 0,
            RH = 1
        };
    private:
        int ID;
        int name;
        BalanceValue balance;
        friend class AVLTree;
        Node* left;
        Node* right;
    public:
        Node(){
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int ID, int name, Node* left = nullptr, Node* right = nullptr){
            this->ID = ID;
            this->name = name;
            this->left = left;
            this->right = right;
        }
    };
    
private:
    Node* root;
protected:
    int getHeight(Node* node){
        if(node == nullptr){
            return 0;
        }
        int lh = this->getHeight(node->left);
        int rh = this->getHeight(node->right);
        return max(lh, rh) + 1;
    }

    int getBalance(Node* node){
        if(node == nullptr){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void printInorder(Node* node){
        if(node == nullptr){
            return;
        }
        printInorder(node->left);
        cout << node->ID << "-" << node->name << endl;
        printInorder(node->right);
    }

    Node* rightRotate(Node* node){
        Node* newNode = node->left;
        node->left = newNode->right;
        newNode->right = node;
        return newNode;
    }

    Node* leftRotate(Node* node){
        Node* newNode = node->right;
        node->right = newNode->left;
        newNode->left = node;
        return newNode;
    }

    Node* getRightmost(Node* node){
        Node* curr = node;
        while (curr->right != nullptr)
        {
            curr = curr->right;
        }
        return curr;
    }

public:
    AVLTree(){
        this->root = nullptr;
    }

    ~AVLTree(){
        clear();
    }

    int getHeight(){
        return this->getHeight(this->root);
    }

    Node* insert(Node* node, int ID, int name){
        if(node == nullptr){
            return new Node(ID, name);
        }
        if(name < node->name){
            node->left = insert(node->left, ID, name);
        }else if(name >= node->name){
            node->right = insert(node->right, ID, name);
        }

        int balance = getBalance(node);
        if(balance > 1 && name < node->left->name){
            return rightRotate(node);
        }
        if(balance < -1 && name >= node->right->name){
            return leftRotate(node);
        }
        if(balance > 1 && name >= node->left->name){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && name < node->right->name){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void insert(const int ID, const int name){
        this->root = insert(this->root, ID, name);
    }

    Node* remove(Node* node, int ID){
        if(node == nullptr){
            return nullptr;
        }
        if(ID < node->ID){
            node->left = remove(node->left, ID);
        }else if(ID > node->ID){
            node->right = remove(node->right, ID);
        }else if(ID == node->ID){
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                return nullptr;
            }else if(node->left == nullptr){
                Node* tmp = node->right;
                *node = *tmp;
                delete tmp;
            }else if(node->right == nullptr){
                Node* tmp = node->left;
                *node = *tmp;
                delete tmp;
            }else{
                Node* tmp = getRightmost(node->left);
                node->name = tmp->name;
                node->ID = tmp->ID;
                node->left = remove(node->left, tmp->ID);
            }
        }
        if(node == nullptr){
            return node;
        }
        int balance = getBalance(node);
        if(balance > 1 && getBalance(node->left) >= 0){
            return rightRotate(node);
        }
        if(balance < -1 && getBalance(node->right) <= 0){
            return leftRotate(node);
        }
        if(balance > 1 && getBalance(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void remove(const int ID){
        this->root = remove(this->root, ID);
    }

    void printInorder(){
        this->printInorder(this->root);
    }

    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }
        if(node->left){
            clear(node->left);
        }
        if(node->right){
            clear(node->right);
        }
        delete node;
    }

    void clear(){
        clear(this->root);
        this->root = nullptr;
    }
};

class MinHeap
{
public:
    class Node {
    public:
        int ID;
        int name;
        int NUM;
        
        Node(){}
        
        Node(int ID, int name, int NUM) {
            this->ID = ID;
            this->name = name;
            this->NUM = NUM;
        }
    };
private:
    int capacity;
    int count;
    Node** nodes;
protected:
    void reheapUp(int position){
        if(position <= 0 || position >= this->count){
            return;
        }
        int parent = (position - 1) / 2;
        if(this->nodes[parent]->NUM < this->nodes[position]->NUM){
            Node* tmp = this->nodes[parent];
            this->nodes[parent] = this->nodes[position];
            this->nodes[position] = tmp;
            this->reheapUp(parent);
        }
    }

    void reheapDown(int position){
        if(position < 0 || position >= this->count){
            return;
        }
        int leftChild = 2 * position + 1;
        int rightChild = 2 * position + 2;
        int minChild = position; 
        
        if(leftChild < this->count && this->nodes[leftChild]->NUM < this->nodes[minChild]->NUM){
            minChild = leftChild;
        }
        
        if(rightChild < this->count && this->nodes[rightChild]->NUM < this->nodes[minChild]->NUM){
            minChild = rightChild;
        }
        
        if(minChild != position){
            Node* tmp = this->nodes[position];
            this->nodes[position] = this->nodes[minChild];
            this->nodes[minChild] = tmp;
            this->reheapDown(minChild);
        }
    }

public:
    MinHeap(){
        this->capacity = MAXSIZE;
        this->count = 0;
        this->nodes = new Node*[capacity]; 
        for (int i = 0; i < capacity; i++) {
            nodes[i] = new Node();  
        }
    }

    ~MinHeap(){
        clear();
    }

    void push(int ID, int name, int NUM){
        if (this->count < this->capacity) {
            this->nodes[count]->ID = ID;
            this->nodes[count]->name = name;
            this->nodes[count]->NUM = NUM;
            this->count++;
            this->reheapUp(this->count - 1);
        }
    }

    int locateID(int ID){
        if (this->isEmpty()) {
            return -1;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->ID == ID) {
                return i;
            }
        }
        return -1;
    }

    void increaseNUM(int i){
        this->nodes[i]->NUM++;
    }

    int getCount(){
        return this->count;
    }

    void remove(int ID){
        int index = this->locateID(ID);
        if (index == -1) {
            return;
        }else{
            this->nodes[index] = this->nodes[this->count - 1];
            this->count--;
            this->reheapDown(index);
        }
    }

    bool isEmpty(){
        return (this->count == 0);
    }

    void clear(){
        for (int i = 0; i < this->capacity; i++) {
            if (this->nodes[i] != nullptr) {
                delete this->nodes[i];
            }
        }
        delete[] this->nodes;  
        this->nodes = nullptr;
        this->count = 0;
    }
};

void REG(string name){
	cout << "REG: " << name << endl;
}

void CLE(int NUM){
	cout << "CLE: " << NUM << endl;
}

void PrintHT(){
	cout << "PrintHT" << endl;
}

void PrintAVL(){
	cout << "PrintAVL" << endl;
}

void PrintMH(){
	cout << "PrintMH" << endl;
}

void simulate(string filename)
{
	ifstream orders(filename);
    string command;
	
    if (orders.is_open()) {
        while (getline(orders, command)) {
			int space = count(command.begin(), command.end(), ' ');

			string request = "";
			string para = "";
			int NUM = 0;

			if(space == 1){
				stringstream ss(command);
				ss >> request >> para;

				if(request == "REG"){
                    bool noDigit = true;
                    for (char c : para){
                        if (isdigit(c)){
                            noDigit = false;
                            break;
                        }
                    }
                    if(noDigit){
                        REG(para);
                    }
				}else if(request == "CLE"){
                    bool isNum = true;
                    for (char c : para){
                        if (!isdigit(c)){
                            isNum = false;
                            break;
                        }
                    }
                    if(isNum){
                        NUM = stoi(para);
					    CLE(NUM);
                    }
				}
			}else if(space == 0){
				stringstream ss(command);
				ss >> request;
				if(request == "PrintHT"){
					PrintHT();
				}else if(request == "PrintAVL"){
					PrintAVL();
				}else if(request == "PrintMH"){
					PrintMH();
				}
			}
		}
        orders.close();
    }
}