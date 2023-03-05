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
    if (head == NULL) return NULL;
    float listSize = 0;
    LLNode* cur = head;
    while(cur!=NULL){
        listSize++;
        cur = cur->next;
    }
    int size = listSize;
    //listSize = listSize/2;
    cur = head;
    int count = 1;
    LLNode* s1 = new LLNode(cur->val,NULL);
    while(count<listSize/2){
        cur = cur->next;
        count++;
        s1 = new LLNode(cur->val,s1);
    }
    if(size%2!=0){
        cur = new LLNode(0, cur->next);
    }
    else {
        cur = cur->next;
    }
    LLNode* headS1 = s1;
    while(s1!=NULL){
        s1->val = s1->val + cur->val;
        s1 = s1->next;
        cur = cur->next;
    }
    return headS1;
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