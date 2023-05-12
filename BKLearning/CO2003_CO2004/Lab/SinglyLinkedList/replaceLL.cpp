/*
- Class LinkedList is used to represent single linked list, described as the following:

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
- In this class; head, tail and size are the pointers of the first element, 
the last element and size of linked list.
- Request: Implement function 'replace(LinkedList* linked_list, int low, int high)'  
(low <= high and high >= 0) to delete all elements from position low to position high in the linked list 
(head's position is 0). After that, add linked_list to this linked list in the position after position (low - 1) 
(if low - 1 < 0, the head of this linked list will become the head of linked_list. 
(If high >= size, delete all elements from low position to the last position of this linked list. 
If low < 0, delete all elements from the first position of this linked list to high position) 
- Example:
+ The given linked list: 10->20->30->40->50
+ The linked_list: 55->45->42
+ low=1, high=3
In this case, delete all elements from position 1 (value 20) to position 3 (value 40). 
After that, add linked_list to this linked list to the position after position 0 (value 10), 
therefore, this linked list will become: 10->55->45->42->50 .
Note: In this exercise, library 'iostream' and 'sstream' and 'using namespace std;' has been used. 
You can add other functions, however, you are not allowed to add other libraries.
*/

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
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;
    while(curr != nullptr && count <= high){
        if(count == low){
            if(prev == nullptr){
                head = linked_list->head;
            }else{
                prev->next = linked_list->head;
            }
        }
        if(count == high){
            linked_list->tail->next = curr->next;
            if(curr == tail){
                tail = linked_list->tail;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
    size = size - (high - low + 1) + linked_list->size;
}

/*
LinkedList* l1 = new LinkedList();
LinkedList* l2 = new LinkedList();
l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
l2->add(55); l2->add(45); l2->add(42);
l1->replace(l2, -1, 2);
cout << l1->toString() << "\n";
*/