#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Define a Huffman Node struct
struct HuffmanNode {
    int frequency;
    char character;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(int frequency, char character) {
        this->frequency = frequency;
        this->character = character;
        left = nullptr;
        right = nullptr;
    }
};

// Define a comparison struct for Huffman Nodes based on their frequency values
struct CompareNodes {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Define a class for the Huffman Tree
class HuffmanTree {
private:
    HuffmanNode* root;
    unordered_map<char, string> encodingMap;
    
    // Recursive function to build the encoding map by traversing the tree
    void buildEncodingMapHelper(HuffmanNode* node, string encoding) {
        if (node) {
            if (!node->left && !node->right) {
                encodingMap[node->character] = encoding;
            }
            buildEncodingMapHelper(node->left, encoding + "0");
            buildEncodingMapHelper(node->right, encoding + "1");
        }
    }
    
public:
    // Constructor to build the Huffman Tree and encoding Map
    HuffmanTree(string text) {
        unordered_map<char, int> frequencyMap;
        
        // Calculate frequency of each character in the input text
        for (char c : text) {
            if (c >= 'a' && c <= 'z') { // lowercase letters
                frequencyMap[c - ('a' - 'A')]++;
            } else { // uppercase letters and other characters
                frequencyMap[c]++;
            }
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
        
        buildEncodingMapHelper(root, "");
    }
    
    // Function to encode the input name using the encoding map
    string encodeName(string name) {
        string encodedString = "";
        for (char c : name) {
            encodedString += encodingMap[c];
        }
        return encodedString;
    }
};

int main() {
    string input;
    cin >> input;
    
    // Create a Huffman Tree with the input text
    HuffmanTree huffmanTree(input);
    
    // Encode the name and convert binary to decimal
    string encodedName = huffmanTree.encodeName(input);
    int decimalValue = stoi(encodedName, nullptr, 2);
    
    // Print the decimal value (up to 15 digits)
    cout << decimalValue % 1000000000000000 << endl;
    
    return 0;
}

class HuffTree {
private:
    HuffNode* root; // con trỏ đến nút gốc của cây Huffman

public:
    // constructor khởi tạo cây Huffman từ một danh sách các LeafNode
    HuffTree(std::vector<LeafNode*> leaves) {
        // tạo một hàng đợi ưu tiên (min heap) dựa trên tần số (weight) của các lá
        std::priority_queue<HuffNode*, std::vector<HuffNode*>, CompareHuffNodes> minHeap;
        for (auto leaf : leaves) {
            minHeap.push(leaf);
        }

        // xây dựng cây Huffman từ các lá
        while (minHeap.size() > 1) {
            HuffNode* left = minHeap.top();
            minHeap.pop();
            HuffNode* right = minHeap.top();
            minHeap.pop();
            HuffNode* internal = new IntNode(left, right); // tạo nút nội bộ
            minHeap.push(internal);
        }

        root = minHeap.top(); // lấy nút gốc của cây Huffman
    }

    ~HuffTree() {
        // giải phóng bộ nhớ của các nút trong cây Huffman
        deleteSubtree(root);
        root = nullptr;
    }

    // Hàm giải phóng bộ nhớ của một cây con dựa trên DFS
    void deleteSubtree(HuffNode* node) {
        if (node) { // nếu đang xem nút hợp lệ
            if (!node->isLeaf()) { // nếu đây là một nút nội bộ
                IntNode* internal = dynamic_cast<IntNode*>(node); // ép kiểu node thành IntNode
                deleteSubtree(internal->leftNode()); // giải phóng bộ nhớ của cây con bên trái
                deleteSubtree(internal->rightNode()); // giải phóng bộ nhớ của cây con bên phải
            }

            delete node; // giải phóng bộ nhớ của nút hiện tại
        }
    }

    // Hàm chuyển đổi thông điệp sang mã Huffman
    std::string encode(const std::string& message) const {
        std::unordered_map<char, std::string> encodingMap;
        buildEncodingMap(encodingMap, root, std::string());
        std::string encodedMessage;
        for (char c : message) {
            encodedMessage += encodingMap[c];
        }
        return encodedMessage;
    }

    // Hàm chuyển đổi mã Huffman sang thông điệp gốc
    std::string decode(const std::string& code) const {
        std::string decodedMessage;
        HuffNode* currentNode = root;
        for (char c : code) {
            if (c == '0') { // tiếp tục đi xuống cây theo bên trái
                currentNode = dynamic_cast<IntNode*>(currentNode)->leftNode();
            } else if (c == '1') { // tiếp tục đi xuống cây theo bên phải
                currentNode = dynamic_cast<IntNode*>(currentNode)->rightNode();
            }
            if (currentNode->isLeaf()) { // nếu đến lá
                LeafNode* leaf = dynamic_cast<LeafNode*>(currentNode); // ép kiểu thành LeafNode
                decodedMessage += leaf->character(); // thêm kí tự của lá vào thông điệp đã giải mã
                currentNode = root; // quay lại điểm xuất phát cho lần duyệt tiếp theo
            }
        }
        return decodedMessage;
    }

private:
    // Hàm xây dựng bảng mã Huffman từ cây Huffman
    void buildEncodingMap(
            std::unordered_map<char, std::string>& encodingMap,
            HuffNode* node,
            std::string code) const {
        if (node->isLeaf()) { // nếu đang xem một lá
            LeafNode* leaf = dynamic_cast<LeafNode*>(node); // ép kiểu node thành LeafNode
            encodingMap[leaf->character()] = code; // lưu mã Huffman tương ứng với kí tự
        } else { // nếu đang xem một nút nội bộ
            IntNode* internal = dynamic_cast<IntNode*>(node); // ép kiểu node thành IntNode
            buildEncodingMap(encodingMap, internal->leftNode(), code + "0"); // duyệt theo bên trái và thêm số 0 vào mã
            buildEncodingMap(encodingMap, internal->rightNode(), code + "1"); // duyệt theo bên phải và thêm số 1 vào mã
        }
    }
};

class HuffmanTree {
private:
    TreeNode *root;
    std::unordered_map<char, std::string> codes;

    // Duyệt cây Huffman để tạo bảng mã
    void buildCodeTable(TreeNode *node, std::string code) {
        if (auto leaf = dynamic_cast<LeafNode *>(node)) {
            codes[leaf->character()] = code;
        } else if (auto inner = dynamic_cast<InnerNode *>(node)) {
            buildCodeTable(inner->getLeftChild(), code + "0");
            buildCodeTable(inner->getRightChild(), code + "1");
        }
    }

public:
    HuffmanTree(const std::unordered_map<char, int> &frequencies) {
        auto cmp = [](TreeNode *a, TreeNode *b) { return a->weight() > b->weight(); };
        std::priority_queue<TreeNode *, std::vector<TreeNode *>, decltype(cmp)> q(cmp);

        for (auto pair : frequencies) {
            q.push(new LeafNode(pair.first, pair.second));
        }

        while (q.size() >= 2) {
            auto left = q.top();
            q.pop();
            auto right = q.top();
            q.pop();
            auto parent = new InnerNode(left, right);
            q.push(parent);
        }

        root = q.top();

        buildCodeTable(root, "");
    }

    ~HuffmanTree() {
        destroy(root);
    }

    std::string encode(const std::string &text) const {
        std::string result;
        for (char c : text) {
            result += codes.at(c);
        }
        return result;
    }

    std::string decode(const std::string &bits) const {
        std::string result;
        auto p = root;
        for (char bit : bits) {
            if (bit == '0') {
                p = dynamic_cast<InnerNode *>(p)->getLeftChild();
            } else {
                p = dynamic_cast<InnerNode *>(p)->getRightChild();
            }
            if (dynamic_cast<LeafNode *>(p)) {
                result += dynamic_cast<LeafNode *>(p)->character();
                p = root;
            }
        }
        return result;
    }

private:
    void destroy(TreeNode *node) {
        if (auto leaf = dynamic_cast<LeafNode *>(node)) {
            delete leaf;
        } else if (auto inner = dynamic_cast<InnerNode *>(node)) {
            destroy(inner->getLeftChild());
            destroy(inner->getRightChild());
            delete inner;
        }
    }
};

class Customer {
private:
    std::string name;

public:
    Customer(const std::string &name) {
        this->name = name;
    }

    const std::string &getName() const {
        return name;
    }
};

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    os << "Customer " << customer.getName();
    return os;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    std::unordered_map<char, int> frequencies;
    std::ifstream file(argv[1]);
    std::string line;

    // Đọc file và tính tần số xuất hiện của các ký tự
    while (std::getline(file, line)) {
        if (line.substr(0, 3) == "REG") { // Chỉ xử lý dòng lệnh REG
            std::string name = line.substr(4);
            for (char c : name) {
                frequencies[c]++;
            }
        }
    }

    // Xây dựng cây Huffman từ tần số xuất hiện
    HuffmanTree tree(frequencies);

    // Mở file lại để đọc tính năng khác
    file.clear();
    file.seekg(0);

    // Đọc file và mã hóa tên khách hàng bằng cây Huffman để lưu vào codeword
    while (std::getline(file, line)) {
        if (line.substr(0, 3) == "REG") { // Chỉ xử lý dòng lệnh REG
            std::string name = line.substr(4);
            auto encodedName = tree.encode(name);
            long long codeword = std::bitset<15>(encodedName).to_ulong();
            std::cout << "Encoded Name: " << encodedName << std::endl;
            std::cout << "Codeword: " << codeword << std::endl;

            Customer customer(name);
            LeafNode *leaf = dynamic_cast<LeafNode *>(tree.decode(encodedName));
            leaf->setCode(encodedName);
            std::cout << "Customer: " << customer << ", Codeword: " << leaf->getCode() << std::endl;
        }
    }

    file.close();

    return 0;
}