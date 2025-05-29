/*
[Tiếng Việt]

Viết chương trình theo cấu trúc OOP để tiến hành đổi chỗ các cặp giá trị liên tiếp nhau trong danh sách liên kết.

Sinh viên được yêu cầu hiện thực phần TODO của các hàm đã cho, không được tự ý điều chỉnh mã nguồn khởi tạo của chương trình.

Đầu vào:

n: độ dài của mảng

arr: mảng các giá trị trong linked list ban đầu

Đầu ra:

Tiến hành in ra màn hình danh sách liên kết sau khi chuyển đổi.

Mô tả chức năng các hàm:

swap: có chức năng đổi chỗ các cặp trong danh sách liên kết ban đầu, nhận đầu vào là địa chỉ head của danh sách liên kết ban đầu, trả về địa chỉ head của danh sách liên kết sau khi đã chuyển đổi.
createList: nhận đầu vào là mảng các giá trị khởi tạo và biến n là số lượng các phần tử của mảng, trả về địa chỉ con trỏ head của danh sách liên kết sau khi khởi tạo.
printList: nhận đầu vào là địa chỉ head của danh sách liên kết, in ra màn hình giá trị của các node trong danh sách liên kết.



For example:

Test	Input	Result
1
5
1 2 3 4 5
2 1 4 3 5

*/

#include <iostream>

using namespace std;

// YOU ARE NOT ALLOWED TO MODIFY INITIAL CODE, ONLY CODE IN TODO
class Node {
    int val;
    Node* next;

   public:
    Node() : val(0), next(nullptr) {}
    Node(int x) {
        // TO DO
        this->val = x;
        this->next = nullptr;
    }
    Node(int x, Node* next) {
        // TO DO
        this->val = x;
        this->next = next;
    }
    int getVal() {
        // TO DO
        return this->val;
    }
    Node* getNext() {
        // TO DO
        return this->next;
    }
    void setVal(int x) {
        // TO DO
        this->val = x;
    }
    void setNext(Node* next) {
        // TO DO
        this->next = next;
    }
};
class ListNode {
   public:
    Node* swap(Node* head) {
        // TO DO
        if (head == nullptr || head->getNext() == nullptr){
            return head;
        }
        Node* newHead = head->getNext();
        Node* prev = nullptr;
        Node* current = head;
        while(current != nullptr && current->getNext() != nullptr){
            Node* nextNode = current->getNext();
            Node* nextPair = nextNode->getNext();

            nextNode->setNext(current);
            current->setNext(nextPair);

            if (prev != nullptr) {
                prev->setNext(nextNode);
            }

            prev = current;
            current = nextPair;
        }

        return newHead;
    }

    Node* createList(int arr[], int n) {
        // TO DO
        if (n == 0) return nullptr;

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(arr[i]);
            tail->setNext(newNode);
            tail = newNode;
        }
        return head;
    }
    void printList(Node* head) {
        // TO DO
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->getVal();
            if(temp->getNext() != nullptr){
                cout << " ";
            }
            temp = temp->getNext();
        }
        cout << endl;
    }
};