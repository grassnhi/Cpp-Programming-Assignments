/*
Cho chương trình khởi tạo, trong đó:
- struct node: đại diện cho một node của linked list
- Hàm print: nhận vào con trỏ head của linked list và in ra từng phần tử của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm countNode:
    + Nhận đầu vào là con trỏ head của linked list
    + Trả về số lượng nodes trong linked list
- Hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm countNode
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
- function countNode:
    + Input is the head pointer of the linked list
    + return the number of nodes in linked list
- function main reads the size of the linked list, calls createLinkedList to Initialize the linked list, then calls print to print the linked list.
Complete function countNode
Input:
n is size of the linked list (0 < n < 5000)
n following numbers are values of each node in the linked list, each value is an integer in (-5000; 5000)
Output:
Satisfy the requirements





For example:

Test	Input	Result
1
5
1 3 5 7 5
1
3
5
7
5

5

*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int countNode(node* head)
{
  //TODO
  int n = 0;
  node* temp = head;
  while(temp != nullptr){
      n++;
      temp = temp->next;
  }
  return n;
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
  cout<<endl;
  cout<<countNode(head);
  return 0;
}
