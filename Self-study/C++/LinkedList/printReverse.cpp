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

// Function to print reverse circular linked list without changing the original list
void printReverseCircularLinkedList(Node *head) {
    if (head == nullptr) {
        return;
    }
    cout << "Reverse list: ";
    Node *curr = head;
    do {
        curr = curr->next;
    } while (curr->next != head);
    Node *last = curr;
    curr = last;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != last);
    cout << endl;
}

// Function to print circular linked list
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
    // create a circular linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    cout << "Original list: ";
    printLinkedList(head);

    // print the reverse circular linked list without changing the original list
    printReverseCircularLinkedList(head);

    return 0;
}
