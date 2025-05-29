/*
[Tiếng Việt]


Cho một số dương, in theo một mẫu mà không sử dụng bất kỳ vòng lặp nào.

Đầu vào: n = 16

Đầu ra: 16, 11, 6, 1, -4, 1, 6, 11, 16 (không có khoảng trắng ở cuối)

Đầu vào: n = 10

Đầu ra: 10, 5, 0, 5, 10 (không có khoảng trắng ở cuối)

Về cơ bản, đầu tiên chúng ta bớt 5 cái một cho đến khi chúng ta đạt đến số âm hoặc 0. Sau khi chúng tôi đạt đến 0 hoặc số âm, chúng tôi thêm 5 cho đến khi chúng tôi đạt đến n.

Lưu ý: Xin lưu ý rằng bạn không thể sử dụng key work for, while, goto (ngay cả trong tên biến, comment).

Bạn có thể triển khai các hàm đệ quy khác nếu cần.

Đối với bài tập này, chúng ta có #include <iostream> và sử dụng namespace std;

[English ]

Given a positive number, print following a pattern without using any loop.

 

Input: n = 16

Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)

Input: n = 10

Output: 10, 5, 0, 5, 10 (has no space at the end)

We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.

Note: Please note that you can't using key work for, while, goto (even in variable names, comment).

You can implement other recursive functions if needed.

For this exercise, we have #include <iostream> and using namespace std;




For example:

Test	Result
printPattern(16);
16, 11, 6, 1, -4, 1, 6, 11, 16
printPattern(10);
10, 5, 0, 5, 10

*/

void printPattern(int n)
{
	/*
	* STUDENT ANSWER
	*/
	cout << n;
	if(n <= 0){
	    return;
	}
	cout << ", ";
	printPattern(n-5);
	cout << ", ";
	cout << n;
}