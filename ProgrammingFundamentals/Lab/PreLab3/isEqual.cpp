/*
Cho chương trình khởi tạo, trong đó:

- struct node: đại diện cho một node của linked list
- Hàm createLinkedList:
    + Nhận vào số phần tử (>0) của link list
    + Xây dựng một linked list với dữ liệu của các node được nhập từ đầu vào chuẩn (stdin), node mới được thêm vào CUỐI linked list
    + Trả về con trỏ đến node đầu tiên của linked list.
- Hàm isEqual so sánh hai linked list:
   + Nhận vào con trỏ head1 của linked list thứ nhất, con trỏ của một head2 của linked list thứ 2
   + Hàm trả về true khi và chỉ khi hai linked list có cùng chiều dài và giá trị của node ở vị trí tương ứng luôn bằng nhau. Ngược lại, hảm trả về false.
- Hàm main đọc vào số phần tử của linked list, gọi hàm createLinkedList để khởi tạo linked list, sau đó gọi hàm print để in ra các phần tử của linked list.
Bạn hãy hoàn thành hàm isEqual 
Đầu vào: 
Các giá trị nhập vào từ đầu vào chuẩn (stdin) đều có giá trị trong khoảng (0; 5000)


Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function isEqual compare two linked list:
   + Receive the pointer head1 of the 1st linked list , pointer head2 of the 2nd linked list
   + Return true if and only if 2 the linked lists have indentical size, and node value. Otherwise, return false.
- Function main reads the size of the linked list, calls function createLinkedList to Initialize the linked list, then call functdion print to print all the node's values of the linked list.
Complete function isEqual 
Input: 
The value input from standard input (stdin) with value in (0; 5000)

For example:

Test	Input	Result
1
5
1 3 5 7 9
5
1 3 5 7 9
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

bool isEqual(node *head1, node *head2)
{
  // TO DO
  node* node1 = head1;
  node* node2 = head2;
  while(node1 != nullptr && node2 != nullptr){
      if(node1->data != node2->data){
          return false;
      }
      node1 = node1->next;
      node2 = node2->next;
  }
  return node1 == nullptr && node2 == nullptr; 
}

int main()
{
  int n = 0;
  cin>> n;
  node *head1 = createLinkedList(n);
  int m = 0;
  cin>> m;
  node *head2 = createLinkedList(m);
  cout << isEqual(head1, head2) << endl;
  return 0;
}
