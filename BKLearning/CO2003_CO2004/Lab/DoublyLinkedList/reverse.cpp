/*
Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

Constraint:
1 <= list.length <= 10^5
0 <= node.val <= 5000
1 <= left <= right <= list.length

Example 1:
Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
Output: 3 6 5 4 7

Example 2:
Input: list = {8, 9, 10}, a = 1, b = 3
Output: 10 9 8

*/

/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    ListNode* head1 = head;
    for(int i = 1; i < a; i++){
        head1 = head1->right;
    }
    ListNode* tail1 = head1;
    for(int i = a; i < b; i++){
        tail1 = tail1->right;
    }
    ListNode* curr = head1;
    ListNode* tmp = nullptr;
    for(int i = a; i <= b; i++){
        tmp = curr->left;
        curr->left = curr->right;
        curr->right = tmp;
        curr = curr->left;
    }
    tmp = head1->right;
    curr = tail1->left;
    tail1->left = tmp;
    head1->right = curr;
    if(tmp != nullptr){
        tmp->right = tail1;
    }else{
        head = tail1;
    }
    if(curr != nullptr){
        curr->left = head1;
    }
    return head;
}

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
    if(head == nullptr){
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = nullptr;
    for(int i = 1; i < a; i++) {
        prev = curr;
        curr = curr->right;
    }
    ListNode* start = curr;
    ListNode* next = nullptr;
    ListNode* newHead = nullptr;
    for(int i = a; i <= b; i++) {
        next = curr->right;
        curr->right = newHead;
        newHead = curr;
        curr = curr->left = next;
    }
    if(prev != nullptr) 
        prev->right = newHead;
    else 
        head = newHead;
    
    start->right = curr;
    
    if(curr != nullptr) 
        curr->left = start;
    
    return head;
}

/*
Test	Input	Result
int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
5
3 4 5 6 7
2 4 
3 6 5 4 7 
int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
3
8 9 10
1 3
10 9 8 

*/