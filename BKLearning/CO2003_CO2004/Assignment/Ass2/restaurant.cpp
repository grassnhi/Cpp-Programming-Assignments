#include "main.h"

const int HALFMAX = MAXSIZE / 2;

class Table{
public:
    int ID; // ID bàn

    Table* next;
    Table* prev; 
    
    friend class DLinkedList;
public:
    Table(){
        this->next = next;
        this->prev = prev;
    }
    
    Table(int ID, Table* next = nullptr, Table* prev = nullptr)
    {
        this->ID = ID;
        this->next = next;
        this->prev = prev;
    }
};

class DLinkedList{
public:
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

    // chưa có gì thì insert cho có :>
    void insert(int ID){
        Table* node = new Table(ID);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        count++;
    }

    // có thì xóa add lại :> 
    void update(int ID){
        if(head == nullptr){
            head = tail = new Table(ID);
        }else{
            remove(ID);
            insert(ID);
        }
    }

    void removeAt(int index){
        if(index < 0 || index >= count || head == nullptr){
            return;
        }else if(index == 0){
            if(head == tail){
                Table* tmp = head;
                head = tail = nullptr;
                delete tmp;
                count--;
            }else{
                Table* tmp = head;
                head = head->next;
                head->prev = nullptr;
                delete tmp;
                count--;
            }
        }else if(index == count - 1){
            Table* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            count--;
        }else{
            if(index < count /2){
                Table* tmp = head;
                Table* prev = nullptr;
                for(int i = 0; i < index; i++){
                    prev = tmp;
                    tmp = tmp->next;
                }
                //Table* del = tmp;
                prev->next = tmp->next;
                //tmp = prev->next;
                prev->next->prev = prev;
                delete tmp;
            }else{
                Table* tmp = tail;
                Table* follow = nullptr;
                for(int i = count - 1; i > index; i--){
                    follow = tmp;
                    tmp = tmp->prev;
                }
                //Table* del = tmp;
                follow->prev = tmp->prev;
                //tmp = follow->prev;
                follow->prev->next = follow;
                delete tmp;
            }
            count--;
        }
    }

    // có ID thì xóa :>
    void remove(int ID){
        if(head == nullptr){
            return;
        }else{
            Table* tmp = head;
            for (int i = 0; i < count; i++) {
                if (tmp->ID == ID){
                    removeAt(i);
                    return;
                }
                tmp = tmp->next;
            }
        }
    }

    int front(){
        return this->head->ID;
    }

    void clear(){
        while (head != nullptr)
        {
            Table* tmp = head;
            head = head->next;
            delete tmp;
        }
        head = tail = nullptr;
        count = 0;
    }

    int size(){
        return count;
    }

    bool empty(){
        return count == 0;
    }

    void printList(){
        Table* tmp = head;
        cout << "List: ";
        for (int i = 0; i < count; i++)
        {
            cout << tmp->ID << " ";
            tmp = tmp->next;
        }
        
    }
};

class HuffNode
{
public:
    virtual ~HuffNode(){}
    virtual int weight() = 0;
    virtual char character() = 0;
    virtual int priority() = 0;
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

    virtual int priority(){ return 0;}
    virtual HuffNode* leftNode() const { return nullptr; }
    virtual HuffNode* rightNode() const { return nullptr; }

};

class IntNode : public HuffNode
{
private:
    int fred;
    int prior;
    HuffNode* left;
    HuffNode* right;
    
public:
    IntNode(int prior, HuffNode* left, HuffNode* right){
        this->prior = prior;
        this->fred = left->weight() + right->weight();
        this->left = left;
        this->right = right;
    }
    ~IntNode(){
        left = nullptr;
        right = nullptr;
    }

    int weight(){
        return this->fred;
    }

    int priority(){
        return this->prior;
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

    char character() { return ' '; }
};

class CompareNodes {
public:
    bool operator()(HuffNode* a, HuffNode* b) const{
        if(a->weight() < b->weight()){
            return false;
        }else if(a->weight() == b->weight()){
            if(a->isLeaf() && b->isLeaf() && a->character() < b->character()){
                return false;
            }else if(a->isLeaf() && !b->isLeaf()){
                return false;
            }else if(!a->isLeaf() && !b->isLeaf() && a->priority() < b->priority()){
                return false;
            }
        }
        return true;
    }
};

class HuffTree
{
private:
    HuffNode* root;
    map<char, string> encodingMap;

    void buildEncodingMap(HuffNode* node, string code) {
        if (node == nullptr) {
            return;
        }
        
        if (node->leftNode() == nullptr && node->rightNode() == nullptr) {
            encodingMap[node->character()] = code;
            return;
        }
        
        buildEncodingMap(node->leftNode(), code + "0");
        buildEncodingMap(node->rightNode(), code + "1");
    }

public:
    HuffTree(){
        this->root = nullptr;
    }

    void buildTree(string name) {
        map<char, int> freqMap;
        
        // Calculate frequency of each character in the input text
        for (char c : name) {
            freqMap[c]++;
        }

        priority_queue<HuffNode*, vector<HuffNode*>, CompareNodes> minHeap;
        for (auto entry : freqMap) {
            minHeap.push(new LeafNode(entry.first, entry.second));
        }

        if (minHeap.size() == 1) {
            this->root = minHeap.top();
            minHeap.pop();
        }

        int prior = 0;
        while (minHeap.size() > 1) {
            auto left = minHeap.top();
            minHeap.pop();
            auto right = minHeap.top();
            minHeap.pop();
            prior++;
            auto internal = new IntNode(prior, left, right);
            minHeap.push(internal);
            this->root = internal;
        }
        
        buildEncodingMap(this->root, "");
    }

    ~HuffTree(){
        clear();
    }

    // Hàm chuyển đổi thông điệp sang mã Huffman
    int encode(string name){
        string result = "";
        
        for (char c : name) {
            string code = "";
            code = encodingMap.at(c);
            if(code == ""){
                code = "1";
            }
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

class HashTable
{
public:
    class Entry
    {
    private:
        int key; // name (result) -> hashCode
        int ID; // table ID
        string name; // name 
        int result;
        int NUM;
        friend class HashTable;
    public:
        Entry(){}
        Entry(int key, string name, int ID, int result, int NUM = 1){
            this->key = key;
            this->name = name;
            this->NUM = NUM;
            this->ID = ID;
            this->result = result;
        }
    };
    
protected:
    Entry** table;
    int capacity;
    int count;
public:
    HashTable(){
        this->capacity = HALFMAX;
        this->count = 0;
        this->table = new Entry*[capacity];
        for(int i = 0; i < capacity; i++){
            this->table[i] = nullptr;
        }
    }

    ~HashTable(){
        deleteMap();
    }

    int hashFunct(int key) {
        return key % HALFMAX;
    }

    void insert(int key, string name, int ID, int result){
        int index = this->hashFunct(key);

        while (table[index] != nullptr){
            index = hashFunct(index + 1);
        }
        if (table[index] != nullptr){
            table[index]->name = name;
            table[index]->ID = ID;
            table[index]->result = result;
            table[index]->NUM = 1;
        }else{
            table[index] = new Entry(key, name, ID, result);
            this->count++;
        }
    }

    void updateOrders(string name){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->name == name) { 
                table[i]->NUM++;
            }
        }
    }

    bool search(string name){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->name == name) { 
                return true;
            }
        }
        return false;
    }

    int getCount(){
        return this->count;
    }

    void remove(int ID){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr && table[i]->ID == ID){
                Entry* tmp = table[i]; 
                table[i] = nullptr;
                count--;
                delete tmp;
            }
        }
    }

    void clear(){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr){ 
                Entry* tmp = table[i];
                table[i] = nullptr;
                delete tmp;
            }
        }
        this->count = 0;
    }

    void deleteMap(){
        for(int i = 0; i < capacity; i++){
            if (table[i] != nullptr) { 
                Entry* tmp = table[i];
                table[i] = nullptr;
                delete tmp;
            }
        }
        delete[] table;
        this->count = 0;
    }

    void printTable() {
        for(int i = 0; i < capacity; i++) {
            if(table[i] != nullptr) {
                cout << table[i]->ID << "-" << table[i]->result << "-" << table[i]->NUM << endl;
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
        // enum BalanceValue
        // {
        //     LH = -1,
        //     EH = 0,
        //     RH = 1
        // };
    private:
        int ID;
        int result;
        string name;
        int NUM;
        //BalanceValue balance;
        friend class AVLTree;
        Node* left;
        Node* right;
    public:
        Node(){
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int ID, int result, string name, int NUM = 1, Node* left = nullptr, Node* right = nullptr){
            this->ID = ID;
            this->result = result;
            this->name = name;
            this->NUM = NUM;
            this->left = left;
            this->right = right;
        }
    };
    
private:
    int count;
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
        cout << node->ID << "-" << node->result << "-" << node->NUM << endl;
        printInorder(node->right);
    }

    void printLevel(Node* node, int level){
        if(node == nullptr){
            return;
        }
        if(level == 0){
            cout << node->ID << "-" << node->result << "-" << node->NUM << endl;
        }else if(level > 0){
            printLevel(node->left, level - 1);
            printLevel(node->right, level - 1);
        }
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

    Node* leftmostRight(Node* node){ 
        Node* curr = node;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
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

    Node* insert(Node* node, int ID, int result, string name){
        if(node == nullptr){
            return new Node(ID, result, name);
        }
        if(result < node->result){
            node->left = insert(node->left, ID, result, name);
        }else if(result >= node->result){
            node->right = insert(node->right, ID, result, name);
        }

        int balance = getBalance(node);
        if(balance > 1 && result < node->left->result){
            return rightRotate(node);
        }
        if(balance < -1 && result >= node->right->result){
            return leftRotate(node);
        }
        if(balance > 1 && result >= node->left->result){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && result < node->right->result){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* remove(Node* node, int ID){
        if(node == nullptr){
            return node;
        }
        if (node->ID != ID) {
			node->left = remove(node->left, ID);
			node->right = remove(node->right, ID);
		}else if(ID == node->ID){
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                return nullptr;
            }else if(node->right == nullptr){
                Node* tmp = node->left;
                *node = *tmp;
                delete tmp;
            }else if(node->left == nullptr){
                Node* tmp = node->right;
                *node = *tmp;
                delete tmp;
            }else{
                Node* tmp = leftmostRight(node->right);  
                node->result = tmp->result;
                node->ID = tmp->ID;
                node->NUM = tmp->NUM;
                node->name = tmp->name;
                // *node = *tmp;
                node->right = remove(node->right, tmp->ID); 
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

    bool search(Node* node, string name){
        if(node == nullptr){
            return false;
        }
        if(node->name != name){
            this->search(node->left, name);
            this->search(node->right, name);
        }else{
            return true;
        }
        return false;
    }

    void updateOrders(Node* node, string name){
        if(node == nullptr){
            return;
        }else if(node->name == name){
            node->NUM++;
        }else{
            this->updateOrders(node->left, name);
            this->updateOrders(node->right, name);
		}
    }
public:
    AVLTree(){
        this->count = 0;
        this->root = nullptr;
    }

    ~AVLTree(){
        clear();
    }

    int getHeight(){
        return this->getHeight(this->root);
    }

    int getCount(){
        return this->count;
    }

    void insert(const int ID, const int result, string name){
        this->root = insert(this->root, ID, result, name);
        this->count++;
    }

    void remove(const int ID){
        this->root = remove(this->root, ID);
        this->count--;
    }

    bool search(string name){
        return this->search(this->root, name);
    }

    void updateOrders(string name){
        this->updateOrders(this->root, name);
    }

    void printInorder(){
        this->printInorder(this->root);
    }

    void printLevel(){
        int height = this->getHeight(this->root);
        for(int i = 0; i < height; i++){
            printLevel(this->root, i);
        }
    }

    void clear(){
        clear(this->root);
        this->root = nullptr;
        this->count = 0;
    }
};

class MinHeap
{
public:
    class Node{
    private:
        int ID; // ID
        string name; // name
        int NUM; // sổ lần gọi món
        int prior; // thứ tự ưu tiên
        friend class MinHeap;
    public:    
        Node(){}
        
        Node(int ID, string name, int prior, int NUM = 1) {
            this->ID = ID;
            this->name = name;
            this->prior = prior;
            this->NUM = NUM;
        }
    };
    
private:
    int capacity;
    int count;
    Node** nodes;
protected:
    bool compare(int position, int relative){
        if(this->nodes[relative]->NUM > this->nodes[position]->NUM){
            return true;
        }else if(this->nodes[relative]->NUM == this->nodes[position]->NUM){
            if(this->nodes[relative]->prior > this->nodes[position]->prior){
                return true;
            }
        }
        return false;
    }
    void reheapUp(int position){
        if(position <= 0 || position >= this->count){
            return;
        }
        int parent = (position - 1) / 2;
        if(compare(position, parent)){
            Node* tmp = this->nodes[parent];
            this->nodes[parent] = this->nodes[position];
            this->nodes[position] = tmp;
// cout << "PrintHeap" << endl;
// this->printHeap();  
            this->reheapUp(parent);
        }
    }

    void reheapDown(int position){
        if(position < 0 || position >= this->count){
            return;
        }
        int leftChild = 2 * position + 1;
        int rightChild = 2 * position + 2;
         
        if(leftChild < this->count){
            int minChild = leftChild;
            if(rightChild < this->count && compare(rightChild, leftChild)){
                minChild = rightChild;
            }
            if(compare(minChild, position)){
                Node* tmp = this->nodes[position];
                this->nodes[position] = this->nodes[minChild];
                this->nodes[minChild] = tmp;
// cout << "PrintHeap" << endl;
// this->printHeap();      
                this->reheapDown(minChild);
            }
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

    int locateID(string name){
        if (this->isEmpty()) {
            return -1;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                return i;
            }
        }
        return -1;
    }

    void printPreOrder(int i){
        if(i >= this->count){
            return;
        }
        cout << this->nodes[i]->ID << "-" << this->nodes[i]->NUM << endl;
        printPreOrder(2 * i + 1);
        printPreOrder(2 * i + 2);
        
    }
public:
    MinHeap(){
        this->capacity = MAXSIZE;
        this->count = 0;
        this->nodes = new Node*[capacity]; 
        for (int i = 0; i < capacity; i++) {
            nodes[i] = nullptr;  
        }
    }

    ~MinHeap(){
        clear();
    }

    void insert(int ID, string name, int prior){
        if (this->count < this->capacity){
            // this->nodes[count]->ID = ID;
            // this->nodes[count]->name = name;
            // this->nodes[count]->NUM = NUM;
            // this->nodes[count]->prior = prior;
            this->nodes[count] = new Node(ID, name, prior);
            this->count++;
// cout << "PrintHeap" << endl;
// this->printHeap();  
            this->reheapUp(this->count - 1);
        }
    }

    bool checkName(string name){
        if (this->isEmpty()) {
            return false;
        }
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                return true;
            }
        }
        return false;
    }

    void updateOrder(string name){
        for(int i = 0; i < this->count; i++){
            if(this->nodes[i]->name == name){
                this->nodes[i]->NUM++;
                
                Node* tmp = this->nodes[i];
                this->nodes[i] = this->nodes[this->count - 1];
                this->nodes[this->count - 1] = tmp;
                
                this->count--;
// cout << "PrintHeap" << endl;
// this->printHeap();  
                this->reheapDown(i);

                if(i < this->count){
                    reheapUp(i);
                }

                this->count++;
// cout << "PrintHeap" << endl;
// this->printHeap();                
                this->reheapUp(this->count - 1);

				break;
            }
        }
    }

    int numOrders(string name){
        int index = this->locateID(name);
        if(index != -1){
            return this->nodes[index]->NUM;
        }
        return -1;
    }

    void remove(int ID){
        int index = this->locateID(ID);
        if (index == -1) {
            return;
        }else{
            Node* tmp = this->nodes[index];
            this->nodes[index] = this->nodes[this->count - 1];
            this->nodes[this->count - 1] = nullptr;
            delete tmp;
            this->count--;
// cout << "PrintHeap" << endl;
// this->printHeap(); 
            this->reheapDown(index);
            if(index < this->count){
                reheapUp(index);
            }
        }
    }

    int front(){
        return this->nodes[0]->ID;
    }
    
    bool isEmpty(){
        return (this->count == 0);
    }

    int getCount(){
        return this->count;
    }

    int getID(string name){
        for (int i = 0; i < this->count; i++) {
            if (this->nodes[i]->name == name) {
                return this->nodes[i]->ID;
            }
        }
        return -1;
    }

    void clear(){
        for (int i = 0; i < this->capacity; i++){
            if (this->nodes[i] != nullptr){
                Node* tmp = this->nodes[i];
                this->nodes[i] = nullptr;
                delete tmp;
            }
        }
        delete[] this->nodes;  
        this->count = 0;
    }

    void printPreOrder(){
        this->printPreOrder(0);
    }
    void printHeap(){
        for (int i = 0; i < this->count; i++) {
            cout << this->nodes[i]->ID << "-" << this->nodes[i]->NUM << endl;
        }
    }
};

long long int prior = 0;
int* checkID = new int[MAXSIZE + 1]; // reg1 = 1 reg2 = 2 no use = 0
HashTable* hashTable = new HashTable();
AVLTree* avlTree = new AVLTree();
DLinkedList* FIFO = new DLinkedList(); // không update nếu trùng name
DLinkedList* LRCO = new DLinkedList(); // update for order
MinHeap* LFCO = new MinHeap();

int encodeName(string name){
    HuffTree* ht = new HuffTree();
    ht->buildTree(name);
    int cusName = ht->encode(name);
    delete ht;
    return cusName;
}

int generateID(int result){
    int tableID = result % MAXSIZE + 1;
    for(int i = 0; i < MAXSIZE; i++){
        if(checkID[tableID] == 1 || checkID[tableID] == 2){
            tableID++;
        }
        if(tableID > MAXSIZE){
            tableID = tableID % MAXSIZE;
        }
        if(checkID[tableID] == 0){
            break;
        }
    }
    return tableID;
}

void REG(string name){
    if(LFCO->checkName(name)){
        LFCO->updateOrder(name);
        LRCO->update(LFCO->getID(name));
        hashTable->updateOrders(name);
        avlTree->updateOrders(name);
    }else{
        int result = encodeName(name);
        if(hashTable->getCount() + avlTree->getCount() < MAXSIZE){
            int tableID = generateID(result);
            prior++;

            if(result % 2 == 1){
                if(hashTable->getCount() < HALFMAX){
                    checkID[tableID] = 1; 
                    hashTable->insert(result, name, tableID, result);
                }else if(hashTable->getCount() == HALFMAX){
                    checkID[tableID] = 2; 
                    avlTree->insert(tableID, result, name);
                }
            }else if(result % 2 == 0){
                if(avlTree->getCount() < HALFMAX){
                    checkID[tableID] = 2; 
                    avlTree->insert(tableID, result, name);
                }else if(avlTree->getCount() == HALFMAX){
                    checkID[tableID] = 1; 
                    hashTable->insert(result, name, tableID, result);
                }
            }

            FIFO->insert(tableID);
            LRCO->insert(tableID);
            LFCO->insert(tableID, name, prior);
        }else{
            int tableID = -1;
            prior++;

            if(result % 3 == 0){
                tableID = FIFO->front();
            }else if(result % 3 == 1){
                tableID = LRCO->front();
            }else if(result % 3 == 2){
                tableID = LFCO->front();
            }

            if(checkID[tableID] == 1){
                hashTable->remove(tableID);
                hashTable->insert(result, name, tableID, result);
            }else if(checkID[tableID] == 2){
                avlTree->remove(tableID);
                avlTree->insert(tableID, result, name);
            }
            
            FIFO->remove(tableID);
            LRCO->remove(tableID);
            LFCO->remove(tableID);

            FIFO->insert(tableID);
            LRCO->insert(tableID);
            LFCO->insert(tableID, name, prior);
        }
    }
}

void CLE(int NUM){
    if(NUM < 1 && hashTable->getCount() != 0){
        int delID[HALFMAX] = {};
        Table* tmp = FIFO->head;
        int i = 0;
        while (tmp != nullptr)
        {
            int ID = tmp->ID;
            if(checkID[ID] == 1){
            	delID[i] = ID;
                i++;
                //cout << ID << " ";
            }
            tmp = tmp->next;
        }
        for(int j = 0; j < i; j++){
            LFCO->remove(delID[j]);
            FIFO->remove(delID[j]);
            LRCO->remove(delID[j]);
            checkID[delID[j]] = 0;
        }
        hashTable->clear();
        //FIFO->printList();
    }else if(NUM > MAXSIZE && avlTree->getCount() != 0){
        int delID[HALFMAX] = {};
        Table* tmp = FIFO->head;
        int i = 0;
        while (tmp != nullptr)
        {
            int ID = tmp->ID;
            if(checkID[ID] == 2){
            	delID[i] = ID;
                i++;
            }
            tmp = tmp->next;
        }
        for(int j = 0; j < i; j++){
            LFCO->remove(delID[j]);
            FIFO->remove(delID[j]);
            LRCO->remove(delID[j]);
            checkID[delID[j]] = 0;
        }
        avlTree->clear();
        //FIFO->printList();
    }else if(NUM >= 1 && NUM <= MAXSIZE){
        if(checkID[NUM] == 1){ 
            hashTable->remove(NUM);
        }else if(checkID[NUM] == 2){
            avlTree->remove(NUM);
        }
        checkID[NUM] = 0;
        FIFO->remove(NUM);
        LRCO->remove(NUM);
        LFCO->remove(NUM);
    }
}

void PrintHT(){
    //cout << "PrintHT" << endl;
    hashTable->printTable();
}

void PrintAVL(){
	//cout << "PrintAVL" << endl;
    avlTree->printLevel();
}

void PrintMH(){
	//cout << "PrintMH" << endl;
    LFCO->printPreOrder();
    //cout << "PrintHeap" << endl;
    //LFCO->printHeap();
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
                    bool charac = true;
                    for (char c : para){
                        if (!isalpha(c)){
                            charac = false;
                            break;
                        }
                    }
                    if(charac){
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

    delete[] checkID;
    delete hashTable;
    delete avlTree;
    delete FIFO;
    delete LRCO;
    delete LFCO;
}