/*
Viết một chương trình C++ để tìm giá trị sau khi đảo ngược thứ tự các chữ số của một số. 
Ví dụ 123 là kết quả của quá trình đảo ngược thứ tự các chữ số của 321.

Đầu vào:
Một số nguyên n kiểu int

Đầu ra:
Hàm reverseNum sẽ trả về số thỏa yêu cầu bài toán

Lưu ý:
Sinh viên chỉ cần hiện thực hàm reverseNum, có thể hiện thực các hàm khác để hỗ trợ
*/

#include<iostream>
using namespace std;

int reverseNum(int n)
{
    int rN =0, r=0;

    while(n>0){
        r = n % 10;
        rN = rN * 10 + r;
        n = n / 10;
    }
    
    return rN;
}

int main()
{
    int n;
    cin>>n;

    cout<<reverseNum(n);
    
    return 0;
}