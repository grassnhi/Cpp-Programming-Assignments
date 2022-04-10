/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- function countNode:
    + Input is the head pointer of the linked list
    + return the number of nodes in linked list
- function main reads the size of the linked list, calls createLinkedList to Initialize the linked list, then calls print to print the linked list.
Complete function countNode
Input:
n is size of the linked list (0 < n < 5000)
n following numbers are values of each node in the linked list, each value is an integer in (-5000; 5000)
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

int countNode(node* head)
{
  //TODO
  int i = 0;
  while (head != NULL){
      i++;
      head = head -> next;
  }
  return i;
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
  cout<<endl;
  cout<<countNode(head);
  return 0;
}
