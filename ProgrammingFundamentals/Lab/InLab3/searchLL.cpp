/*
Cho chương trình khởi tạo, trong đó:
- struct node: đại diện cho một node của linked list
- Hàm print: nhận vào con trỏ head của linked list và in ra từng phần tử của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm searchLinkedList: 
    + Nhận vào con trỏ head của linked list
    + Giá trị cần tìm
    + Nếu tìm thấy thì trả về vị trí đầu tiên của nó trong Linked List (index từ 0), không thì trả về -1.
- hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm searchLinkedList
Đầu vào:
Các giá trị từ đầu vào chuẩn đều có giá trị trong khoảng từ (0; 5000)
English version
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- function searchLinkedList: 
    + receive the linked list's head pointer
    + The searching Value
    + If found, return the first position the value appeared in the Linked List (index start from 0), otherwise -1.
- function main read the linked list's size, calls function createLinkedList to initialize the linked list, then calls function print to print the linked list.
Complete functions searchLinkedList
Input:
All the input from standard input (stdin) with value in (0; 5000)



For example:

Test	Input	Result
1
5
1 3 5 7 9
3
1
3
5
7
9
1

*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int searchLinkedList(node* head, int key)
{
  // TODO
  if(head == nullptr){
      return -1;
  }
  node* temp = head;
  int idx = 0;
  while(temp != nullptr){
      if(temp->data == key){
          return idx;
      }
      idx++;
      temp = temp->next;
  }
  return -1;
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
  node *head = createLinkedList(n);
  print(head);
  int m;
  cin>>m;
  cout<<searchLinkedList(head,m);
  return 0;
}
