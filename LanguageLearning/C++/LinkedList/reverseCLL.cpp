#include <iostream>
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

// Function to reverse circular singly linked list without using stack
void reverseCircularLinkedList(Node *&head) {
    // check if list is empty or contains only one node
    if (head == nullptr || head->next == head) {
        return;
    }

    // initialize pointers
    Node *prev = head;
    Node *curr = head->next;
    Node *next = curr->next;

    // traverse the list and update next pointers
    while (curr != head) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }

    // update pointers to reverse the list
    curr->next = prev;
    head = curr->next;
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

    // reverse the list without using stack
    reverseCircularLinkedList(head);

    cout << "Reversed list: ";
    printLinkedList(head);

    return 0;
}
