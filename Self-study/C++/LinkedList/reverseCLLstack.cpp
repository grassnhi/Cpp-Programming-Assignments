#include <iostream>
#include <stack>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to reverse circular singly linked list using a stack
void reverseCircularLinkedList(Node *&head) {
    // check if list is empty or contains only one node
    if (head == nullptr || head->next == head) {
        return;
    }

    // initialize a stack to store nodes
    stack<Node*> s;

    // traverse the list and push nodes onto the stack
    Node *curr = head;
    do {
        s.push(curr);
        curr = curr->next;
    } while (curr != head);

    // pop nodes from the stack and update pointers to reverse the list
    Node *prev = s.top();
    s.pop();
    head = prev;
    while (!s.empty()) {
        Node *next = s.top();
        s.pop();
        prev->next = next;
        prev = next;
    }

    // set the last node to point to the new first node
    prev->next = head;
}

// Function to print circular singly linked list
void printLinkedList(Node *head) {
    Node *curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

// Driver code
int main() {
    // create a circular singly linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head; // make it circular

    cout << "Original list: ";
    printLinkedList(head);

    // reverse the list using a stack
    reverseCircularLinkedList(head);

    cout << "Reversed list: ";
    printLinkedList(head);

    return 0;
}
