/*
Class LinkedList is used to represent single linked list, described as the following:
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
	void partition(int k);
};
In this class; head, tail and size are the pointers of the first element, the last element and size of linked list.
Request: Implement function 
void LinkedList::partition(int k);
To rearrange elements in this linked list by this way: split all elements of this linked list to 3 groups include:
group I (the value  of each element is smaller than k), group II (the value of each element is equal to k) 
and group III (the value of each element is larger than k); after that, move group I to the head  of linked list, 
group II is after group I and group III is after group II. Note that the orders of the elements of each group 
are unchanged.
Example:

- The given linked list: 10->55->45->42->50

- k=45

In this case, group I includes elements with value 10 and 42, group II includes elements with 45 
and group III includes elements with value 55 and 50. Rearrange by above way,  this linked list will become 
10->42->45->55->50 (the orders of th elements in each group is unchanged: 10 before 42 and 55 before 50). 
Note: In this exercise, libraries iostream, sstream and using namespace std; have been used. You can add 
other functions for your answer, but you are not allowed to add other libraries.

*/

void LinkedList::partition(int k) {
    if (head == nullptr || head->next == nullptr) {
        // the list is empty or has only one element
        return;
    }
    
    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    Node* head3 = nullptr;
    Node* tail3 = nullptr;

    Node* tmp = head;

    while (tmp != nullptr)
    {
        if(tmp->value < k){
            if(head1 != nullptr){
                tail1->next = tmp;
                tail1 = tail1->next;
            }else{
                head1 = tail1 = tmp;
            }
        }else if(tmp->value == k){
            if(head2 != nullptr){
                tail2->next = tmp;
                tail2 = tail2->next;
            }else{
                head2 = tail2 = tmp;
            }            
        }else{
            if(head3 != nullptr){
                tail3->next = tmp;
                tail3 = tail3->next;
            }else{
                head3 = tail3 = tmp;
            }            
        }

        tmp = tmp->next;
    }
    
    if(head1 == nullptr){
        if(head2 == nullptr){
            head = head3;
            tail = tail3;
        }else{ 
            head = head2;
            if(head3 == nullptr){               
                tail = tail2;
            }else{
                tail2->next = head3;
                tail = tail3;
            }
        }
    }else{
        head = head1;
        if(head2 == nullptr){
            if(head3 == nullptr){
                tail = tail1;
            }else{
                tail1->next = head3;
                tail = tail3;
            }    
        }else{ 
            tail1->next = head2;
            if(head3 == nullptr){
                tail = tail2;
            }else{
                tail2->next = head3;
                tail = tail3;
            }
        }
    }

    tail->next = nullptr;
}

/*
LinkedList* l1 = new LinkedList();
l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
l1->partition(45);
cout << l1->toString() << "\n";
*/

if(head == nullptr || head->next == nullptr){
        return;
    }
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;
    Node* tail3 = nullptr;
    Node* tmp = head;
    while(tmp != nullptr){
        if(tmp->value < k){
            if(head1 != nullptr){
                tail1->next = tmp;
                tail1 = tmp;
            }else{
                head1 = tail1 = tmp;
            }
        }else if(tmp->value == k){
            if(head2 != nullptr){
                tail2->next = tmp;
                tail2 = tmp;
            }else{
                tail2 = head2 = tmp;
            }
        }else{
            if(head3 != nullptr){
                tail3->next = tmp;
                tail3 = tmp;
            }else{
                tail3 = head3 = tmp;
            }
        }
        tmp = tmp->next;
    }
    if(head1 != nullptr){
        head = head1;
        if(head2 != nullptr){
            tail1->next = head2;
            if(head3 != nullptr){
                tail2->next = head3;
                tail = tail3;
            }else{
                tail = tail2;
            }
        }else{
            if(head3 != nullptr){
                tail1->next = head3;
                tail = tail3;
            }else{
                tail = tail1;
            }
        }
    }else{
        if(head2 != nullptr){
            head = head2;
            if(head3 != nullptr){
                tail2->next = head3;
                tail = tail3;
            }else{
                tail = tail2;
            }
        }else{
            if(head3 != nullptr){
                head = head3;
                tail = tail3;
            }
        }
    }