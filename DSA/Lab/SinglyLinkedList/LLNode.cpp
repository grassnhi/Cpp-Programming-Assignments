#include<iostream>
#include<math.h>
using namespace std;

class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode(){
            this->val = 0;
            next = nullptr;
        }
        LLNode(int val, LLNode* next){
            this->val = val;
            next = nullptr;
        }
};

// each node is a digit, the head is the least significant digit, 
// returns the linked list representing the sum of the two integers.
LLNode* addLinkedList(LLNode* l0, LLNode* l1){
    int sum = 0, sum0 = 0, sum1 = 0, i = 0;
    while (l0 != nullptr)
    {
        sum0 += (l0->val)* pow(10, i);
        l0 = l0->next;
        i++;
    }
    while (l1 != nullptr)
    {
        sum1 += (l1->val)* pow(10, i);
        l1 = l1->next;
        i++;
    }
    sum = sum0 + sum1;
    sum = sum / 10;
    int digit = sum % 10; 
    LLNode* currNode = new LLNode(digit, nullptr);
    LLNode* head = currNode;
    LLNode* prevNode = nullptr;
    while(sum != 0){
        sum = sum / 10;
        digit = sum % 10;       
        LLNode* newNode = new LLNode(digit, nullptr);
        if (prevNode) prevNode->next = newNode;
        prevNode = newNode;
    }
    return head;
}

int main(){
    return 0;
}