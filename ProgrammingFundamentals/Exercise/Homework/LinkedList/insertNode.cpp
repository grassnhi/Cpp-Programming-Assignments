/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function insertNode
    + receive the linked list's head pointers, a pointer of a new node, the position
    + The function will insert the new node to the input position(head's position is 1). If position <=0, do nothing. If position is greater than the size of the linked list, insert to the end of the linked list.
- function main reads the size of the linked list, calls function createLinkedList to initialize the linked list, then call function print to print the linked list.
Complete functions insertNode
Input: 
Value from standards input (stdin) with value in (0; 5000)
*/
#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

node *insertNode(node *head, node *newNode, int position)
{
  // TO DO
  int count = 0;
  node* cur = head;

  while(head != NULL){
    head = head -> next;
    count++;  
  }

  head = cur;

  if(position > 0){
    if(position > count) 
      position = count + 1;

    for(int i =2; i <= position -1; i++){
        cur = cur -> next;
    }
    
    newNode -> next = cur -> next;
    cur -> next = newNode;
  }
  
  return head;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main()
{
  int n = 0;
  cin >> n;

  node *head = createLinkedList(n);

  node *newNode = new node();
  cin >> newNode->data;

  int position = 0;
  cin >> position;

  head = insertNode(head, newNode, position);

  print(head);

  return 0;
}


