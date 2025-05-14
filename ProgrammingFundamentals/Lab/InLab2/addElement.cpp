/*
Mô tả tiếng Việt:

Hiện thực hàm void addElement(int*& arr, int n, int val, int index) nhận vào một mảng động arr có chính xác n phần tử và tiến hành chèn giá trị val vào vị trí thứ index.
 

Đầu vào: Mảng một chiều arr có kích thước n, giá trị cần chèn val và vị trí cần chèn index.
Đầu ra: Mảng arr sau khi chèn.
Lưu ý: Việc chèn phần tử vào mảng động phải được thực hiện bằng cách giải phóng mảng cũ có n phần tử và cấp phát mảng mới có n+1 phần tử. 
English version:

Implement the function void addElement(int*& arr, int n, int val, int index) that inputs a dynamic array, arr, consisting of exactly n elements and insert a value, val, into the a specific position, index.

Input: The n-size dynamic array needs to be inserted the value, val, into the specific position, index.

Output: The dynamic array after insert.

Note: Insertion of elements into a dynamic array must be executed by freeing the old array and allocating new memory for the new one.

For example:

Test	Input	Result
1
2
2 3
1 1
2 1 3
2
2
2 3
1 2
2 3 1

*/

void addElement(int*& arr, int n, int val, int index) {
    // TODO
    int* newArr = new int[n+1];
    for(int i = 0; i <= n; i++){
        if(i < index){
            *(newArr + i) = *(arr + i);
        }else if(i == index){
            *(newArr + i) = val;
        }else{
            *(newArr + i) = *(arr + i - 1);
        }
    }
    
    delete [] arr;
    
    arr =  newArr;
}


void addElement(int*& arr, int n, int val, int index) {
    // TODO
    int * na = new int[n+1];
    int i = 0;
    for (; i < index; ++i) {
        na[i] = arr[i];
    }
    na[i++] = val;
    for (; i < n+1; ++i) {
        na[i] = arr[i-1];
    }
    delete [] arr;
    arr = na;
}
