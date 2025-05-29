/*
Cho chương trình khởi tạo, trong đó:
- struct node: đại diện cho một node của linked list
- Hàm print: nhận vào con trỏ head của linked list và in ra từng phần tử của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm insertNode
    + Nhận vào con trỏ head của linked list, con trỏ của một node mới, và vị trí position
    + Hàm sẽ chèn node mới này vào vị trí position (lấy vị trí của node head là 1). Nếu position <=0, hàm không làm gì cả. Nếu position lớn hơn số phần tử hiện tại của linked list thì node mới được chèn vào cuối của linked list.
- Hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm insertNode
Đầu vào: 
Các giá trị nhập vào từ đầu vào chuẩn (stdin) đều có giá trị trong khoảng (0; 5000)
English version
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function insertNode
    + receive the linked list's head pointers, a pointer of a new nodei, the position
    + The function will insert the new node to the input position(head's position is 1). If position <=0, do nothing. If position is greater than the size of the linked list, insert to the end of the linked list.
- function main reads the size of the linked list, calls function createLinkedList to initialize the linked list, then call function print to print the linked list.
Complete functions insertNode
Input: 
Value from standards input (stdin) with value in (0; 5000)


For example:

Test	Input	Result
1
5
1 3 5 7 9
2 4
1
3
5
2
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

node *createLinkedList(int n); // The implementation is provided implicitly

node *insertNode(node *head, node *newNode, int position)
{
  // TO DO
  if (position <= 0 || newNode == nullptr){
      return head;
  }else if(position == 1){
      newNode->next = head;
      head = newNode;
      return head;
  }else{
      node* temp = head;
      node* prev = temp;
      int idx = 1;
      while(temp != nullptr){
          if(idx < position){
              prev = temp;
              temp = temp->next;
              idx++;
          }else if(idx = position){
              prev->next = newNode;
              newNode->next = temp;
              break;
          }
      }
      if(idx < position){
          prev->next = newNode;
      }
      return head;
  }
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
  node *newNode = new node();
  cin >> newNode->data;
  int position = 0;
  cin >> position;
  head = insertNode(head, newNode, position);
  print(head);
  return 0;
}


