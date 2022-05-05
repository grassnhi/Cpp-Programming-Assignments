#include <iostream>
using namespace std;


struct node
{
    int data;
    node *next;
    node(int data, node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

node *createLinkedList(int n)
{
    int data = 0;
    int count = 0;
    node* head = nullptr;
    while(count != n){
        cin >> data;
        count++;
        if(head == nullptr){
            head = new node(data);
        }
        else{
            head = new node(data, head);
//            node * temp = new node(data, head);
//            head = temp;
        }
    }
    return head;
}
void print(node *head)
{
    node* curr = head;
    while(curr != nullptr){
        cout << curr->data << endl;
        curr = curr->next;
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