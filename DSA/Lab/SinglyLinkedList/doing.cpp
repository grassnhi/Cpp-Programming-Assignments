class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	void replace(LinkedList* linked_list, int low, int high);
};

void LinkedList::replace(LinkedList* linked_list, int low, int high) {
    if(low < 0){
        low = 0;
    }
    if(high >= size){
        high = size - 1;
    }
    if(low > high){
        return;
    }
    int count = 0;
    Node* tmp = head;
    if(low == 0){
        while(low != high + 1){
            Node* curr = tmp;
            tmp = tmp->next;
            delete curr;
            low++;
        }
        linked_list->tail->next = tmp;
        head = linked_list->head;
    }else{ 
        Node* prev = tmp;     
        while(count != low){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = linked_list->head;
        while(low != high + 1){
            Node* curr = tmp;
            tmp = tmp->next;
            delete curr;
            low++;
        }
        linked_list->tail->next = tmp;
    }
    size = size - (high - low + 1);
}