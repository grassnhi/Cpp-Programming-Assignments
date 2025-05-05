/*
[Tiếng Việt ]

Cho một số nguyên x, thực hiện hàm

 

 

int countWaySumOfSquare(int x)
 

để tìm số cách biểu thị x thành tổng bình phương của các số nguyên dương duy nhất.

Ví dụ:

 

Input  : x = 100
Output : 3
Giải thích: 100 = 10^2 = 8^2 + 6^2 = 1^2 + 3^2 + 4^2 + 5^2 + 7^2
 

Lưu ý: Xin lưu ý rằng bạn không thể sử dụng từ khóa for, while, goto (ngay cả trong tên biến, comment).

Bạn có thể triển khai các hàm đệ quy khác nếu cần.

 

Đối với bài tập này, chúng ta có #include <iostream>, #include <math.h> và using namespace std;

 

[English ]

Give an integer x, implement function

 

int countWaySumOfSquare(int x)
 

to find number of ways to express x as sum of squares of unique positive integers.

For example:

 

Input  : x = 100
Output : 3
Explain: 100 = 10^2 = 8^2 + 6^2 = 1^2 + 3^2 + 4^2 + 5^2 + 7^2
Note: Please note that you can't using key work for, while, goto (even in variable names, comment).

You can implement other recursive functions if needed.

For this exercise, we have #include <iostream>, #include <math.h> and using namespace std;

 

 

For example:

Test	Result
cout << countWaySumOfSquare(100);
3

*/

int countWays(int x, int n){
    if(x == 0){
        return 1;
    }
    if(x < 0 || n == 0){
        return 0;
    }
    
    int square = n * n;
    return countWays(x - square, n - 1) + countWays(x, n - 1);
}

int countWaySumOfSquare(int x)
{
	/*
	* STUDENT ANSWER
	*/
	if (x <= 0) return 0;
	int maxRoot = (int)sqrt(x);
	return countWays(x, maxRoot);
}