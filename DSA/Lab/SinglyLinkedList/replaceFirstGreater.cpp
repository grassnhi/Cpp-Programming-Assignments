/*
Class LLNode representing a node of singly linked lists is declared as below:
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}
Given a singly linked list head node.
Your task is to implement a function with following prototype:
LLNode* replaceFirstGreater(LLNode* head);
The function returns head node of the singly linked list after replacing every node's value 
with the first greater node's value to its right. If a node doesn't have a next greater node, set its value to 0.

Note:
- The iostream and stack libraries have been included and namespace std is being used. 
No other libraries are allowed.
- The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
- You can write helper functions.

*/

#include <iostream>
#include <stack>

using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next) : val(val), next(next) {}
};

LLNode* replaceFirstGreater(LLNode* head) {
    // STUDENT ANSWER
     if (!head) {
        return nullptr;
    }
    LLNode* curr = head;
    std::stack<LLNode*> s;
    while (curr) {
        while (!s.empty() && curr->val > s.top()->val) {
            s.top()->val = curr->val;
            s.pop();
        }
        s.push(curr);
        curr = curr->next;
    }
    while (!s.empty()) {
        s.top()->val = 0;
        s.pop();
    }
    return head;
}
/*
int arr[] = {0, 3, 2, 1, 5};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = replaceFirstGreater(head);
LLNode::printList(newhead);
int arr[] = {8, 3, 5, 0, 8, 7, 1, 6, 5, 4};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = replaceFirstGreater(head);
LLNode::printList(newhead);
[8, 3, 5, 0, 8, 7, 1, 6, 5, 4]
[0, 5, 8, 8, 0, 0, 6, 0, 0, 0]
[8, 3, 5, 0, 8, 7, 1, 6, 5, 4]
[8, 8, 8, 8, 8, 7, 6, 6, 5, 4]
int arr[] = {8, 1, 8, 1, 6, 9, 7, 8, 4, 0, 7, 6, 1, 0, 3, 4, 3, 7, 3, 3, 5, 0, 3, 7, 3, 8, 4, 9, 9, 0, 9, 7, 2, 5, 2, 5, 0, 1, 7, 4, 9, 1, 2, 2, 4, 2, 9, 7, 0, 0, 7, 3, 8, 8, 1, 7, 7, 7, 8, 1, 0, 7, 6, 3, 7, 3, 0, 3, 0, 2, 2, 7, 7, 2, 2, 4, 5, 2, 2, 1, 1, 8, 6, 8, 1, 4, 7, 1, 5, 5, 7, 5, 5, 3, 0, 0, 5, 4, 1, 8, 4, 7, 1, 7, 8};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = replaceFirstGreater(head);
LLNode::printList(newhead);
*/

LLNode* replaceFirstGreater(LLNode* head) {
    if (!head || !head->next) { // If list is empty or has only one node
        return head;
    }
    
    stack<LLNode*> s; // To store nodes with greater value
    LLNode* curr = head;
    while (curr) {
        while (!s.empty() && s.top()->val < curr->val) { // Pop all nodes with value less than current node's value
            s.top()->val = curr->val; // Replace popped node's value with current node's value
            s.pop();
        }
        s.push(curr);
        curr = curr->next;
    }
    
    while (!s.empty()) { // Nodes remaining in the stack don't have a greater value to their right
        s.top()->val = 0;
        s.pop();
    }
    
    return head;
}
