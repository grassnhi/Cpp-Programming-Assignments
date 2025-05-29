/*
Cho chương trình khởi tạo, trong đó:
- struct node: đại diện cho một node của linked list
- Hàm print: nhận vào con trỏ head của linked list và in ra từng phần tử của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm replace:
    + Nhận vào con trỏ head của linked list
    + Vị trí position muốn thay thế (tính từ index 0)
    + Giá trị value
    + Hàm replace sẽ thay thế giá trị tại vị trí position bằng giá trị value. Nếu position lớn hơn hoặc bằng số lượng node hoặc position âm thì hàm replace không làm gì cả.
- Hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm replace
Đầu vào:
Tất cả giá trị từ đầu vào chuẩn (stdin) đều nằm trong khoảng (0, 5000). Riêng giá trị của position có thể âm
Đầu ra:
Thỏa yêu cầu bài toán
English version
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function replace:
    + receive the head pointer of the linked list
    + position that needed to be replaced (count from 0)
    + new Value
    + function replace will replace the value at input position to the new Value. If position is equal or greater than the size of the linked list or negative, do nothing.
- Function main reads the linked list's size, calls function createLinkedList to initialize the linked list, then calls function print to print the linked list.
Complete functions replace
Input:
All the input from standard input (stdin) with value in (0, 5000). Except position can be negative
Output:
Satisfy the requirements


For example:

Test	Input	Result
1
5
1 3 5 7 9
0 10
1 3 5 7 9
10 3 5 7 9

*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

void replace(node* head, int position, int value)
{
  //TODO
  if(position >= 0 && head != nullptr){
      node* temp = head;
      int idx = 0;
      while(temp != nullptr){
          if(idx == position){
              temp->data = value;
              break;
          }
          idx++;
          temp = temp->next;
      }
  }
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  int pos, val;
  cin>>pos>>val;
  replace(head, pos, val);
  print(head);
  return 0;
}
