/*
Mô tả tiếng Việt:
Hãy hiện thực hàm int* zeros(int n) tạo một mảng có n phần tử 0.
Đầu vào: Kích thước mảng n.

Đầu ra: Con trỏ trỏ tới mảng vừa được cấp phát.

Lưu ý: Trong trường hợp cấp phát thất bại, hàm sẽ trả về nullptr.

English version:

Implement the function  int* zeros(int n) which can create an array with n zero element.

Input: The array size n.

Output: The pointer that points to the allocated array.

Note: In the case of failed allocation, the function will return nullptr value.

 

 

 

For example:

Test	Input	Result
1
1
0

*/

int* zeros(int n) {
    // TODO
    if(n <= 0){
        return nullptr;
    }
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    return arr;
}