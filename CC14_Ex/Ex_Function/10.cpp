/*
Viết một chương trình C++ để hoán đổi giá trị của 2 biến x, y.

Đầu vào:
Hai số nguyên x, y kiểu int

Đầu ra:
Sau khi thực thi hàm swap, giá trị của x,y được hoán đổi với nhau

Lưu ý:
Sinh viên chỉ cần hiện thực hàm swap, có thể hiện thực các hàm khác để hỗ trợ
*/

#include<iostream>
using namespace std;

void swap( int *a , int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
void swapnum(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}
*/

int main()
{
    int x,y;
    cin>>x>>y;

    swap(x,y);

    cout<<x<<" "<<y;

    return 0;
}