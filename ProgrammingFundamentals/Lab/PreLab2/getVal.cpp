/*
Hiện thực hàm sau:
int getValueAtIndex(int *ptr, int k);
Trả về giá trị của tại vị trí được chỉ định trong mảng qua con trỏ.
Trong đó:
ptr là con trỏ tới phần tử đầu tiên trong mảng.
k là vị trí cần truy xuất phần tử (giá trị này không vượt quá độ dài của mảng).
------------------------------------------------------------
Implement the following function:
int getValueAtIndex(int *ptr, int k);
Return value at the position of the index number through pointer.
Where:
ptr is a pointer to the first element in the array.
k is the access position (this value does not exceed the length of the array).
For example:

Test	Result
int arr[] = {1, 2, 3, 4, 5};
int k = 3;
cout << getValueAtIndex(arr, k);
4

*/

int getValueAtIndex(int *ptr, int k)
{
    return *(ptr+k);
}