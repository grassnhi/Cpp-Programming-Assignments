/*
Hiện thực hàm sau:
int findMax(int *ptr, int n);
Tìm và trả về phần tử lớn nhất trong mảng 1 chiều được cho bởi con trỏ.
Trong đó:
ptr là con trỏ tới phần tử đầu tiên trong mảng.
n là kích thước của mảng.
------------------------------------------------------------
Implement the following function:
int findMax(int *ptr, int n);
Find and return the maximum element of a 1-dimension array given by a pointer.
Where:
ptr is a pointer to the first element in the array.
n is the size of the array.




For example:

Test	Result
int arr[] = {1, 2, 3, 4, 5};
cout << findMax(arr, sizeof(arr) / sizeof(arr[0]));
5

*/

int findMax(int *ptr, int n)
{
    int maxI = 0;
    for(int i = 0; i < n; i++){
        if(*(ptr+i) > maxI){
            maxI = *(ptr+i);
        }
    }
    return maxI;
}