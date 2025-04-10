/*
[Tiếng Việt]

Hiện thực hàm tính giai thừa của số N, sau đó gọi hàm vừa hiện thực trong hàm main để gán kết quả tính được vào biến result.

Đầu vào: 

int N: số tự nhiên N



[English]

Implement a function that calculates the factorials of N. Then call that function inside the main function to assign the calculated value to the variable result.

Input: 

int N: a natural number N


Template:

#include <iostream>

using namespace std;
// implement calculate factorial function in here
# TODO

int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    // call function calculate factorial in here and assign value to the variable result
    # TODO


    cout << result << endl;
    return 0;
}
*/

#include <iostream>

using namespace std;

// Hàm tính giai thừa
long factorial(int N) {
    long fact = 1;
    for (int i = 2; i <= N; ++i) {
        fact *= i;
    }
    return fact;
}

int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    // Gọi hàm factorial và gán vào result
    result = factorial(N);

    cout << result << endl;
    return 0;
}
