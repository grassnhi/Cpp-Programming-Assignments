/*
Viết một chương trình C++ để in tất cả các số nguyên tố trong một khoảng [lower, upper] cho trước

Đầu vào:
2 số nguyên lower, upper (0 ≤ lower, upper ≤ 1000)

Đầu ra:
Các số nguyên tố trong khoảng [lower, upper]. Mỗi số nguyên tố cách nhau một khoảng trắng. 

Lưu ý:
Sinh viên chỉ hiện thực hàm printPrimes. Sinh viên có thể viết thêm các hàm khác để hỗ trợ.

*/

#include <iostream>
using namespace std;

void printPrimes(int lower, int upper)
{
    int temp =0;

    if(lower <= 2)
        lower =2;

    for( int i = lower; i <= upper; i++){
	    for(int j = 2; j < i; j++){
		    if(i % j == 0)
                temp = 1;
	    }

	    if(temp == 0) 
	        cout << i << " ";

	   temp =0;
	}
}

int main()
{
    int lower, upper;
    cin>>lower;
    cin>>upper;

    printPrimes(lower, upper);

    return 0;
}

