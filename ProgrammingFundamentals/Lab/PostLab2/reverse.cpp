/*
Hiện thực hàm sau:
void reverse(int *ptr, int n);
Đảo ngược mảng 1 chiều được cho bởi con trỏ.
Trong đó:
ptr là con trỏ tới phần tử đầu tiên trong mảng.
n là kích thước của mảng 1 chiều.

Lưu ý: Bạn cần phải dùng dereference operator (*) để lấy giá trị của các phần tử trong mảng. Không được dùng subscript operator ([]).
------------------------------------------------------------
Implement the following function:
void findMax(int *ptr, int n);
Reverse the 1-dimension array given by a pointer.
Where:
ptr is a pointer to the first element in the array.
n is the size of the array.

Note: You need to use the dereference operator (*) to get the values of the elements in the array. The subscript operator ([]) cannot be used.




 

For example:

Test	Result
int arr[] = {1, 2, 3, 4, 5};
reverse(arr, sizeof(arr) / sizeof(arr[0]));
cout << arr[0];
for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
{
    cout << ", " << arr[i];
}
5, 4, 3, 2, 1 

*/

void reverse(int *ptr, int n) {
    int* rev = new int[n];
    for(int i = 0; i < n; i++){
        *(rev + i) = *(ptr + n - 1 - i);
    }
    
    for (int i = 0; i < n; i++) {
        *(ptr + i) = *(rev + i);
    }
    
    delete[] rev;
}