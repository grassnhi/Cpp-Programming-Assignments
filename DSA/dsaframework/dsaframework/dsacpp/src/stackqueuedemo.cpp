#include <iostream>
#include <iomanip>
#include "stacknqueue/Stack.h"
#include "list/XArrayList.h"
#include "stacknqueue/Queue.h"
#include "util/ArrayLib.h"

using namespace std;

string dec2hex(int dec){
    string LK = "0123456789ABCDEF";
    Stack<char> stack;
    while(dec > 0){
        char bit = LK[dec % 16];
        stack.push(bit);
        dec = dec/16;
    }
    
    string bits = "";
    while(!stack.empty()) bits.push_back(stack.pop());
    return bits;  
}
string dec2bin(int dec){
    Stack<char> stack;
    while(dec > 0){
        char bit = '0' + dec % 2; //bit = 0 or 1 only
        stack.push(bit);
        dec = dec/2;
    }
    string bits = "";
    while(!stack.empty()) bits.push_back(stack.pop());
    return bits;   
}
int bin2dec(string bin){
    int dec = 0;
    int acc = 1;
    for(int idx=bin.length()-1; idx >= 0; idx--){
        dec += (bin[idx] - '0')*acc;
        acc *=2;
    }
    return dec;
}
int hex2dec(string hex){
    int dec = 0;
    int acc = 1;
    for(int idx=hex.length()-1; idx >= 0; idx--){
        int magnitude = 0;
        if((hex[idx] >= '0') && (hex[idx] <= '9')) magnitude = hex[idx] - '0';
        else if((hex[idx] >= 'a') && (hex[idx] <= 'f')) magnitude = 10 + (hex[idx] - 'a');
        else if((hex[idx] >= 'A') && (hex[idx] <= 'F')) magnitude = 10 + (hex[idx] - 'A');
        else throw hex[idx];
       
        dec += magnitude*acc;
        acc *=16;
    }
    return dec;
}

struct SNode{
    int data;
    SNode* next;
    SNode(int data, SNode* next=0){
        this->data = data;
        this->next = next;
    }
};
SNode* create_schain(int *ptr, int size){
    SNode* head =0;
    for(int idx=size-1; idx >= 0; idx--) head = new SNode(ptr[idx], head);
    return head;
}
void delete_schain(SNode*& head){
    while(head != NULL){
        SNode* anode = head;
        head = head->next;
        delete anode;
    }
}
void println_schain(SNode* const head){
    SNode* cursor = head;
    stringstream os;
    while(cursor != NULL){
        os << cursor->data << ", ";
        cursor = cursor->next;
    }
    string s = os.str();
    if(head != NULL) s = s.substr(0, s.length() -2);
    cout << "[" << s << "]" << endl;
}
void reverse_schain(SNode*& head){
    if(head == NULL) return;
    
    Stack<SNode*> stack;
    SNode* cursor = head;
    while(cursor != NULL){
        stack.push(cursor);
        cursor = cursor->next;
    }
    head = stack.pop();
    cursor = head;
    while(!stack.empty()){
        cursor->next = stack.pop();
        cursor = cursor->next;
        cursor->next = NULL;
    }
}

bool inside_of(char ch, string sequence){
    for(int idx =0; idx < sequence.length(); idx++)
        if(ch == sequence[idx]) return true;
    return false;
}
char close2open(char cchar, string close="}])", string open="{[("){
    for(int idx =0; idx < close.length(); idx++)
        if(cchar == close[idx]) return open[idx];
    return '*';
}
bool expr_balanced(string expr){
    string open="{[(", close="}])";
    Stack<char> stack;
    for(int idx=0; idx < expr.length(); idx++){
        char cur_char = expr[idx];
        if(inside_of(cur_char, open)) stack.push(cur_char);
        else if(inside_of(cur_char, close)){
            char ochar = stack.pop();
            char expected_ochar =  close2open(cur_char);
            if(ochar != expected_ochar) return false;
        }
        else{
            //other characters in expr => do nothing now
        }
    }
    return stack.empty();
    
}
struct Node{
    int data;
    Node *left, *right;
    Node(int data, Node* left=NULL, Node* right=NULL){
        this->data = data;
        this->left = left;
        this->right = right;        
    }
};

/*
                  50
                 /   \
                20    79
              /  \      \
             10   40     90
 
 HOW to generate the sequence: level-by-level (breadth-first mode/traveral/search)
 => [50, 20, 79, 10, 40, 90]
 
 */

Node* create_tree(){
    Node* a = new Node(20, new Node(10), new Node(40));
    Node* b = new Node(79, NULL, new Node(90));
    Node* root = new Node(50, a, b);
    return root;
}

/*
 front -> rear
 [20, 79]
 [79, 10, 40]
 
 */
XArrayList<int>* breadth_first_traversal(Node* root){
    XArrayList<int>* plist = new XArrayList<int>();
    //
    Queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* pnode = q.pop();
        plist->add(pnode->data);
        if(pnode->left != NULL) q.push(pnode->left);
        if(pnode->right != NULL) q.push(pnode->right);
    }
    //
    return plist;
}

XArrayList<int>* depth_first_traversal(Node* root){
    XArrayList<int>* plist = new XArrayList<int>();
    //
    Stack<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* pnode = q.pop();
        plist->add(pnode->data);
        if(pnode->left != NULL) q.push(pnode->left);
        if(pnode->right != NULL) q.push(pnode->right);
    }
    //
    return plist;
}
void demo_converter(){
    int* ptr = genIntArray(10, 0, 100);
    for(int idx=0; idx < 10; idx++){
        cout << ((ptr[idx] == bin2dec(dec2bin(ptr[idx]))) ? "Correct": "Incorrect") << endl;
        cout << ((ptr[idx] == hex2dec(dec2hex(ptr[idx]))) ? "Correct": "Incorrect") << endl;
    }
}

void demo_schain(){
    int ptr[] = {10, 20, 30, 40};
    SNode* head = create_schain(ptr, 4);
    println_schain(head);
    reverse_schain(head);
    println_schain(head);
    delete_schain(head);
}
void demo_expr_balanced(){
    string exprs[] ={
        "{[x + (5*y)] / (2 + z)}", //expected: balanced
        "{[x + (5*y) / 2] + (z  * (6 - t))}", //expected: balanced
        "{[x + (5*y)] / (2 + z)", //expected: unbalanced (stack not empty)
        "{[x + (5*y)] / 2 + z)}", //expected: unbalanced (not match open-close)
    };
    for(string expr: exprs){
        cout << (expr_balanced(expr)? "Balanced": "Unbalanced") << endl;
    }
}
int main(int argc, char** argv){
    demo_converter();
    return 0;
}
        
/*
 Create a list: for example [10, 90, 2, 9, 20]
 Reverse the list; expectation: [20, 9, 2, 90, 10]
 => stack
 */


/**
 USe stack to traverse trees  (Depth-first traveral)
 */


/*
 "ASB**EG***SE*"
 what is the stack's content?
 Answer:
 FROM-TOP: [S ]
 * 
 what is the queue's content?
 Answer:
 FROM-FRONT: [E ]
 * 
 * 
 * front => rear
 [E]
 
 * 
 * Programming capability???? 
 => Google Colab
 */