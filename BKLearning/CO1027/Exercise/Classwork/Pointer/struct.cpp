#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

int main() {
    Node* p = new Node();
    p->data = 5; 
    cout << p->data << endl;
    Node* q = p;
    cout << q->data << endl;
    Node* r = new Node();
    r->data = 10;
    q-> next = r;
    cout << p-> next ->data << endl;
    cout << r->data << endl;
    return 0;
}

