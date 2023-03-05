/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int a, int b) {
    // /To Do
    ListNode* curr = head;
    ListNode* prev = NULL;
    for(int i = 1; i < a; i++) {
        prev = curr;
        curr = curr->right;
    }
    ListNode* start = curr;
    ListNode* next = NULL;
    ListNode* newHead = NULL;
    for(int i = a; i <= b; i++) {
        next = curr->right;
        curr->right = newHead;
        newHead = curr;
        curr = curr->left = next;
    }
    if(prev) 
        prev->right = newHead;
    else 
        head = newHead;
    
    start->right = curr;
    if(curr) 
        curr->left = start;
    
    return head;
}