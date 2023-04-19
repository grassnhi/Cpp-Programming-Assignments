#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class HuffmanNode {
public:
    int frequency;
    char character;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode (int freq, char ch) {
        this->frequency = freq;
        this->character = ch;
        this->left = NULL;
        this->right = NULL;
    }
    
    ~HuffmanNode() {
        delete left;
        delete right;
    }
};

class CompareNodes {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

class HuffmanTree {
public:
    HuffmanNode* root;
    unordered_map<char, string> encodingMap;
    
    HuffmanTree(string text) {
        unordered_map<char, int> frequencyMap;
        
        // Calculate frequency of each character in the input text
        for (char c : text) {
            frequencyMap[c]++;
        }
        
        // Build priority queue of Huffman Nodes based on frequency
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
        for (auto entry : frequencyMap) {
            pq.push(new HuffmanNode(entry.second, entry.first));
        }
        
        // Build Huffman Tree by merging nodes
        while (pq.size() > 1) {
            HuffmanNode* a = pq.top();
            pq.pop();
            
            HuffmanNode* b = pq.top();
            pq.pop();
            
            HuffmanNode* c = new HuffmanNode(a->frequency + b->frequency, '#');
            c->left = a;
            c->right = b;
            
            pq.push(c);
        }
        
        root = pq.top();
        pq.pop();
        
        buildEncodingMap(root, "");
    }
    
    ~HuffmanTree() {
        delete root;
    }
    
private:
    void buildEncodingMap(HuffmanNode* node, string code) {
        if (node == NULL) {
            return;
        }
        
        if (node->left == NULL && node->right == NULL) {
            encodingMap[node->character] = code;
            return;
        }
        
        buildEncodingMap(node->left, code + "0");
        buildEncodingMap(node->right, code + "1");
    }
};

int main() {
    string text = "Hello, World!";
    
    HuffmanTree ht(text);
    
    for (auto entry : ht.encodingMap) {
        cout << entry.first << ": " << entry.second << endl;
    }
    
    return 0;
}
