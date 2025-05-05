/*
Mô tả tiếng Việt:

Hãy hiện thực hàm void shallowCopy(int*& newArr, int*& arr) có chức năng tạo một bản sao của một mảng một chiều.

Đầu vào: Mảng một chiều arr cần được sao chép.

Đầu ra: Mảng đích một chiều newArr cần sao chép tới.

Lưu ý: sau thực thi mảng được sao chép và mảng cần sao chép đều sử dụng chung một vùng nhớ.

English version:

Implement the function void shallowCopy(int*& newArr, int*& arr) that can create a copy from a one-dimensional array.

Input:  The one-dimensional array that needs to be copied.

Output: The destination array.

Note: After finishing execution, both the one-dimensional array that needs to be copied and the destination array use the same data memory.

 





For example:

Test	Result
int* arr = new int[2];
arr[0] = 2; arr[1] = 3;
int* newArr = nullptr;
shallowCopy(newArr, arr);
cout << newArr[0] << ' ' << newArr[1];
delete[] arr;
2 3

*/

void shallowCopy(int*& newArr, int*& arr) {
    // TODO
    newArr = arr;
}