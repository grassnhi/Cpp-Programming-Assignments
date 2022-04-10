/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function replace:
    + receive the head pointer of the linked list
    + position that needed to be replaced (count from 0)
    + new Value
    + function replace will replace the value at input position to the new Value. If position is equal or greater than the size of the linked list or negative, do nothing.
- Function main reads the linked list's size, calls function createLinkedList to initialize the linked list, then calls function print to print the linked list.
Complete functions replace
Input:
All the input from standard input (stdin) with value in (0, 5000). Except position can be negative
Output:
Satisfy the requirements


*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

void replace(node* head, int position, int value)
{
  //TODO
  int count = 0;
  node* cur = head;
  while(head != NULL){
    head = head -> next;
    count++;  
  }
  head = cur;
  if(position >= 0 && position < count){
      for(int i = 0; i < position; i++){
          cur = cur -> next;
      }
      cur -> data = value;
  }
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  int pos, val;
  cin>>pos>>val;
  replace(head, pos, val);
  print(head);
  return 0;
}
