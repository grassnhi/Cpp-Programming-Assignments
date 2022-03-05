#include <iostream>

using namespace std;

Node* deleteFirstNode(struct Node* head)
{
   if (head == NULL)
   return NULL;
 
   // Move the head pointer to the next node
   Node* tempNode = head;
   head = head->next;
   delete tempNode;
 
   return head;
}
int main()
{
   /* Start with the empty list */
   Node* head = NULL;

   // create linked list
   push(&head, 2);
   push(&head, 4);
   push(&head, 6);
   push(&head, 8);
   push(&head, 10);
   Node* temp;
 
   cout<<"Linked list created "<<endl; 
    for (temp = head; temp != NULL; temp = temp->next)
  	 cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;
   //delete first node
   head = deleteFirstNode(head);
   cout<<"Linked list after deleting head node"<<endl; 
for (temp = head; temp != NULL; temp = temp->next)
   		cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;
 return 0;
}
