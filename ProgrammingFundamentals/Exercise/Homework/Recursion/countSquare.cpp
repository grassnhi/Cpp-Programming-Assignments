/*
Give an integer x, implement function
        int countWaySumOfSquare(int x)
to find number of ways to express x as sum of squares of unique positive integers.

For example:
    Input  : x = 100
    Output : 3
    Explain: 100 = 10^2 = 8^2 + 6^2 = 1^2 + 3^2 + 4^2 + 5^2 + 7^2

Note:   Please note that you can't using key work for, while, goto (even in variable names, comment).
        You can implement other recursive functions if needed.

For this exercise, we have #include <iostream>, #include <math.h> and using namespace std;
*/

#include <iostream>
#include <math.h>

using namespace std;

int countWaysUtil(int x, int num)
{
    int val = (x - pow(num, 2));
    if (val == 0) return 1;
    if (val < 0) return 0;

    return countWaysUtil(val, num + 1) + countWaysUtil(x, num + 1);
}

int countWaySumOfSquare(int x)
{
	return countWaysUtil(x, 1);
}

int main()
{
    int x; cin >> x;

    cout << countWaySumOfSquare(x);

    return 0;
}