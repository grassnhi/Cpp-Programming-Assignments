/*
Viết một chương trình C++ để chuyển một số nhị phân thành một số thập phân

Đầu vào:
Một chuỗi ký tự n là một số nhị phân. Ví dụ "01001"

Đầu ra:
Hàm convertBinaryToDecimal trả về giá trị thập phân của số nhị phân vừa truyền vào.

Lưu ý:
Sinh viên chỉ hiện thực hàm convertBinaryToDecimal. 
Số thập phân được trả về luôn đảm bảo là một số không âm và nhỏ hơn hoặc bằng 1000
*/

#include <iostream>
#include <math.h>
using namespace std;

int convertBinaryToDecimal(string n)
{
    int deci = 0, r, i=0, m;
    m=stoi(n);

    while (m!=0)
    {
        r = m % 10;
        m = m / 10;
        deci += r*pow(2,i);
        i++;
    }

    return deci;
}

int main()
{
    string n;
    cin >> n;

    cout << n << " in binary = " << convertBinaryToDecimal(n) << " in decimal";
    
    return 0;
}
