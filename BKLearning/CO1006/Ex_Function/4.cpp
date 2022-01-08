/*
Viết một chương trình C++ để kiểm tra xem một số có phải là số chẵn (even) hay số lẻ (odd).

Đầu vào:
Một dòng chứa một số nguyên dương n. (0 < n < 100 000)

Đầu ra:
Nếu n là số chẵn thì in ra màn hình chuỗi "Even", ngược lại in ra màn hình chuỗi "Odd"

Lưu ý:
Các bạn chỉ cần hoàn thiện hàm EvenOrOdd
*/

#include <iostream>
using namespace std;

void EvenOrOdd()
{
    int n; 

    cin >> n;

    if(n%2==0) 
        cout<< "Even";
    else 
        cout<< "Odd";

    return;
}

int main(){
    EvenOrOdd();
    return 0;
}
