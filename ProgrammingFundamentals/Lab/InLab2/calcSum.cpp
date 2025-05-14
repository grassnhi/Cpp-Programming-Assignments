/*
Hiện thực hàm sau:
int calcSum(int *ptr, int n);
Tính và trả về tổng của các phần tử trong mảng 1 chiều được cho bởi con trỏ.
Trong đó:
ptr là con trỏ tới phần tử đầu tiên trong mảng.
n là kích thước của mảng.
Lưu ý: Bạn cần phải dùng dereference operator (*) để lấy giá trị của các phần tử trong mảng. Không được dùng subscript operator ([]).
------------------------------------------------------------
Implement the following function:
int calcSum(int *ptr, int n);
Calculate and return the sum of elements of a 1-dimension array given by a pointer.
Where:
ptr is a pointer to the first element in the array.
n is the size of the array.

Note: You need to use the dereference operator (*) to get the values of the elements in the array. The subscript operator ([]) cannot be used.

For example:

Test	Result
int arr[] = {1, 2, 3, 4, 5};
cout << calcSum(arr, sizeof(arr) / sizeof(arr[0]));
15
int arr[] = {0, -1, 5, 6, -5, 1, -9, -10, -6, 3};
cout << calcSum(arr, sizeof(arr) / sizeof(arr[0]));
-16

*/

int calcSum(int *ptr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(ptr + i);
    }
    return sum;
}