/*
Write a program where:

- struct node: 
    represents a node in linkedlists

- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  
    END  of the linked list
    + Return a pointer which points to the first node of the linked list.

- Function isEqual compare two linked list:
   + Receive the pointer head1 of the 1st linked list , pointer head2 of the 2nd linked list
   + Return true if and only if 2 the linked lists have indentical size, and node value. 
   Otherwise, return false.

- Function main reads the size of the linked list, calls function createLinkedList to 
Initialize the linked list, then call functdion print to print all the node's values of the linked list.

Complete function isEqual 

Input: 
    The value input from standard input (stdin) with value in (0; 5000)
*/

#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

bool isEqual(node *head1, node *head2)
{
  // TO DO
  if(head1 == NULL && head2 == NULL) return true;
  while (head1 != NULL && head2 != NULL){
        if (head1 -> data != head2 -> data)
            return false;
 
        head1 = head1 -> next;
        head2 = head2 ->  next;
    }

    return (head1 == NULL && head2 == NULL);
}

int main()
{
  int n = 0;
  cin>> n;

  node *head1 = createLinkedList(n);

  int m = 0;
  cin>> m;

  node *head2 = createLinkedList(m);

  cout << isEqual(head1, head2) << endl;
  
  return 0;
}
