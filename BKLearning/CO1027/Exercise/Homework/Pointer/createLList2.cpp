/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  First  position of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function main reads the size of the linked list, calls function createLinkedList to Initialize the linked list, then call function print to print the linked list.
Complete function createLinkedList
Input:
size n of the linked list (0 < n < 5000)
following by n numbers, each number is a value of a node in the linked list, each number is an integer in (-5000; 5000)
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
node* head = NULL;
node *createLinkedList(int n)
{
    // TO DO  
    node* tmp = new node();
    int x;
    for ( int i = 0; i < n; i++ )
    {
        cin >> x;
        node* tmp = new node{x, NULL};
        if( head == NULL )
            head = tmp;
        else 
        {
            tmp->next = head;
            head = tmp;
        }
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
  if (n > 0)
  {
    node *head = createLinkedList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }
  return 0;
}