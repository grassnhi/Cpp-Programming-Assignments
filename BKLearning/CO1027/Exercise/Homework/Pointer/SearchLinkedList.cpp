/*
Write a program where:

- struct node: 
  represents a node in linkedlists

- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is 
    add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.

- function searchLinkedList: 
    + receive the linked list's head pointer
    + The searching Value
    + If found, return the first position the value appeared in the Linked List 
    (index start from 0), otherwise -1.

- function main read the linked list's size, calls function createLinkedList to 
initialize the linked list, then calls function print to print the linked list.

Complete functions searchLinkedList

Input:
  All the input from standard input (stdin) with value in (0; 5000)
*/

#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int searchLinkedList(node* head, int key)
{
  // TODO
  int i = 0;

  while(head != NULL){
      if(head -> data == key){
          return i;
      }
      else{
          head = head -> next;
          i++;
      }
  }

  return -1;
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
  print(head);

  int m;
  cin>>m;

  cout<<searchLinkedList(head,m);

  return 0;
}
