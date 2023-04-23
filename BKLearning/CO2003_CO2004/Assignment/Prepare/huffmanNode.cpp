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
    char chars;
    int fred;
    HuffNode* left;
    HuffNode* right;
    
public:
    IntNode(HuffNode* left, HuffNode* right){
        this->fred = left->weight() + right->weight();
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

    char character() { return chars; }

    void setChar(char chars){
        this->chars = chars;
    }
};

class CompareNodes {
public:
    bool operator()(HuffNode* a, HuffNode* b) const{
        if(a->weight() == b->weight()){
            
            if(a->isLeaf() && b->isLeaf()){
                if (isupper(a->character()) && !isupper(b->character())){
                    
                    return false; // nếu node a là chữ in hoa, node b là chữ thường => a có ưu tiên hơn
                }else if (!isupper(a->character()) && isupper(b->character())){
                    
                    return true; // nếu node a là chữ thường, node b là chữ in hoa => b có ưu tiên hơn
                }else{
                    
                    return a->character() > b->character(); // ưu tiên kí tự lớn
                }
            }else if(a->isLeaf() && !b->isLeaf()){
                
                return false; // ưu tiên lá
            }else if(!a->isLeaf() && b->isLeaf()){
                
                return true; // ưu tiên lá
            }else{
                
                // nếu cả 2 node không phải đều là node lá thì vào trước ưu tiên
                return false;//
            }
        }
        
        return a->weight() >= b->weight(); 
    }
};

class HuffTree
{
private:
    HuffNode* root;
    

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
    map<char, string> encodingMap;

    HuffTree(){
        this->root = nullptr;
    }

    void buildTree(string name) {
        map<char, int> freqMap;
        
        // Calculate frequency of each character in the input text
        for (char c : name) {
            freqMap[c]++;
        }

        for (const auto& pair : freqMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
        priority_queue<HuffNode*, vector<HuffNode*>, CompareNodes> minHeap;
        for (auto entry : freqMap) {
            minHeap.push(new LeafNode(entry.first, entry.second));
        }

        while (minHeap.size() > 1) {
            auto left = minHeap.top();
            minHeap.pop();
            cout << left->character() << "-" << left->weight() << " ";
            auto right = minHeap.top();
            minHeap.pop();
            cout << right->character() << "-" << right->weight() << " ";
            auto internal = new IntNode(left, right);
            internal->setChar('.');
            minHeap.push(internal);
            this->root = internal;
        }
        cout << endl;
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
    string text = "ukkajhsdfjkasbndbmnFJKHJKsdbfsabdf";

    HuffTree* ht = new HuffTree();
    ht->buildTree(text);
    for (auto entry : ht->encodingMap) {
        cout << entry.first << ": " << entry.second << endl;
    }
    cout << ht->encode(text);
    delete ht;
    return 0;
}