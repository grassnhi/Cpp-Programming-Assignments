/*

Hiện thực hàm sau:
void add(int *ptr, int n, int k);
Thực hiện thêm phần tử vào cuối của mảng 1 chiều được cho bởi con trỏ.
Trong đó:
ptr là con trỏ tới phần tử đầu tiên trong mảng.
n, k lần lượt là kích thước của mảng và phần tử cần được thêm vào.
------------------------------------------------------------
Implement the following function:
void add(int *ptr, int n, int k);
Insert element to the end of the 1-dimension array given by a pointer.
Where:
ptr is a pointer to the first element in the array.
n, k respectively is the size of the array and the element that need to be added.

 

 

For example:

Test	Result
int arr[100] = {1, 2, 3, 4, 5};
int n = 5;
int k = 7;
add(arr, n, k);
cout << arr[n];
7
int arr[100] = {3, 9, 20, 6, 18, 0, 16, 8, 15, 14};
int n = 10;
int k = 0;
add(arr, n, k);
cout << arr[n];
0
int arr[100] = {15, 8, -14, 13, -17, -12, 10, -15, -9, 4, 1, 0, 16, -11, -5, 19, 17, -13, -18, -4, 0};
int n = 22;
int k = -100;
add(arr, n, k);
cout << arr[n];
-100

*/

void add(int *ptr, int n, int k)
{
    *(ptr + n) = k;
}