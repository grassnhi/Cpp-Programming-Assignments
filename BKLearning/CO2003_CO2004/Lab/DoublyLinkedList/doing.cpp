
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};


ListNode* reverse(ListNode* head, int a, int b) {
    // /To Do
    // Delete node position from a to b
    if(head == nullptr){
        return head;
    }
    ListNode* nodeA = head;
    ListNode* prev = nullptr;
    for(int i = 0; i < a; i++){
        prev = nodeA;
        nodeA = nodeA->right;
    }
    ListNode* nodeB = nodeA;
    ListNode* follow = nullptr;
    ListNode* newHead = nullptr;
    for(int i = a; i < b; i++){
        follow = nodeA->right;
        nodeA->right = newHead;
        newHead = nodeA;
        nodeA = follow;
    }
    if(prev != nullptr){
        prev->right = newHead;
    }else{
        head = newHead;
    } 
    nodeB->right = nodeA;
    
    if(nodeA != nullptr){
        nodeA->left = nodeB;
    }
    return head;
}