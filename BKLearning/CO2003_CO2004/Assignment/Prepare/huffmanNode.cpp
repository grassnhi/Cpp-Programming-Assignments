#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <bitset>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

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

int main(){
    string text = "";

    HuffTree* ht = new HuffTree();
    ht->buildTree(text);

    cout << ht->encode(text);
    delete ht;
    return 0;
}