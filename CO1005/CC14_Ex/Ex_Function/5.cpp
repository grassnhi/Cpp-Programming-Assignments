/*
Viết một chương trình C++ để tìm giá trị lớn nhất trong một mảng

Đầu vào:
Tham số của hàm getMaxElement bao gồm mảng arr chứa các số nguyên kiểu int, 
n là một số nguyên dương chỉ kích thước của mảng

Đầu ra:
Hàm getMaxElement trả về giá trị lớn nhất trong mảng arr

Lưu ý:
Sinh viên chỉ cần hiện thực hàm getMaxElement, có thể hiện thực thêm các hàm khác để hỗ trợ
*/

#include <iostream>
using namespace std;

int getMaxElement(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)

    max = arr[i];
 
    return max;
}

int main()
{
    int n;
    cin>>n;

    int ar[n];

    for(int i=0;i<n;i++) 
        cin>>ar[i];

    cout<<getMaxElement(ar,n);

    return 0;
}
