/*
Class LLNode representing a node of singly linked lists is declared as below:
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
Given a singly linked list head node.
Your task is to implement a function with following prototype:
LLNode* foldLinkedList(LLNode* head);
The function returns head node of the folded singly linked list.

More info:
A folded singly linked list is achieved by taking the first half of the linked list and 
folding over the second half and merging the intersecting nodes by taking their sum.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
- You can write helper functions.

*/

LLNode* foldLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if(head == nullptr){
        return nullptr;
    }
    int len = 0;
    LLNode* curr = head;
    while(curr != nullptr){
        len++;
        curr = curr->next;
    }
    curr = head;
    int count = 1;
    LLNode* fold = new LLNode(curr->val, nullptr);
    while(count < len / 2){
        curr = curr->next;
        fold = new LLNode(curr->val, fold);
        count++;
    }
    curr = curr->next;
    LLNode* tmp = fold;
    if(len % 2 != 0){
        fold = new LLNode(curr->val, fold);
        curr = curr->next;
    }
    while(tmp != nullptr){
        tmp->val += curr->val;
        tmp = tmp->next;
        curr = curr->next;
    }
    return fold;
}

/*
int arr[] = {9, 5, 7, 5, 0};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead);
[9, 5, 7, 5, 0]
[7, 10, 9]
int arr[] = {8, 4, 6, 8, 5, 3};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead);
*/
