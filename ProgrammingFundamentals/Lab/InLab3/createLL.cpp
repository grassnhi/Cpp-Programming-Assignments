/*
Cho chương trình khởi tạo, trong đó:
- struct node: đại diện cho một node của linked list
- Hàm print: nhận vào con trỏ head của linked list và in ra từng phần tử của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm createLinkedList
Đầu vào:
Số n là số lượng phần tử trong linked list (0 < n < 5000)
n số tiếp theo là giá trị của mỗi node trong linked list, giá trị là một số nguyên có giá trị trong khoảng (-5000; 5000)
Đầu ra:
Thỏa yêu cầu bài toán
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function main reads the size of the linked list, calls function createLinkedList to Initialize the linked list, then call function print to print the linked list.
Complete function createLinkedList
Input:
size n of the linked list(0 < n < 5000)
following n numbers are values of each node in the linked list each number is an integers in (-5000; 5000)
Input:
Satisfy the requirements




For example:

Test	Input	Result
1
5
1 3 5 7 9
1
3
5
7
9

*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
  // TO DO
  node* head = nullptr;
  node* tail = nullptr;
  for(int i = 0; i < n; i++){
      int value;
      cin >> value;
      node *newNode = new node;
      newNode->data = value;
      newNode->next = nullptr;
      if(head == nullptr){
          head = tail = newNode;
      }else{
          tail->next = newNode;
          tail = newNode;
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
