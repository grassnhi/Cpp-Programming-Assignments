class LineStreet {
public:
    LineStreet(string homepage) {
        current = new Node(homepage);
    }
    
    void addNewElement(string ele) {
        Node* new_node = new Node(ele);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
        
        // Clear all forward elements
        Node* next_node = current->next;
        while (next_node != nullptr) {
            Node* to_delete = next_node;
            next_node = next_node->next;
            delete to_delete;
        }
        current->next = nullptr;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->prev == nullptr) {
                break;
            }
            current = current->prev;
        }
        return current->val;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->next == nullptr) {
                break;
            }
            current = current->next;
        }
        return current->val;
    }
    
private:
    class Node {
    public:
        string val;
        Node* prev;
        Node* next;
        
        Node(string val) {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    
    Node* current;
};