/*
Hiện thực hàm sau:
bool isSymmetry(int *head, int *tail);
Kiểm tra mảng 1 chiều có phải là một mảng đối xứng hay không.
Trong đó:
head, tail lần lượt là con trỏ tới phần tử đầu tiên và cuối cùng trong mảng.
------------------------------------------------------------
Implement the following function:
bool isSymmetry(int *head, int *tail);
Checks if the 1-dimensional array is a symmetric array.
Where:
head, tail respectively are pointers to the first element and last element of the array.

Lưu ý: Sinh viên chỉ có 5 lần nộp không tính penalty, ở lần nộp thứ 6 trở đi bài làm sẽ được tính là 0 điểm.



For example:

Test	Result
int arr[] = {1, 2, 1};
cout << isSymmetry(arr, arr + (sizeof(arr) / sizeof(arr[0])) - 1);
1

*/

bool isSymmetry(int *head, int *tail)
{
    while(head < tail){
        if(*head != *tail){
            return false;
        }
        head++;
        tail--;
    }
    return true;
}

bool isSymmetry(int *head, int *tail) {
    if (head >= tail) return true; 
    if (*head != *tail) return false; 
    return isSymmetry(head + 1, tail - 1); 
}