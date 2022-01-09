/*
Viết một chương trình C++ để kiểm tra xem một số có phải số nguyên tố hay không.

Đầu vào:
Một số nguyên không âm n (0 ≤ n ≤ 1 000 000)

Đầu ra:
Nếu n là số nguyên tố thì hàm checkPrimeNumber sẽ trả về true, ngược lại trả về false

Lưu ý: 
Sinh viên chỉ cần hoàn thiện hàm checkPrimeNumber
*/

#include <iostream>
using namespace std;

bool checkPrimeNumber(int n) {
    if(n < 2)
		return false;

	for(int i = 2; i <= n / 2; i++){
		if(n % i == 0)
			return false;
    }

	return true;
}

int main() {
    int n;
    cin >> n;

    if (checkPrimeNumber(n))
        cout << n << " is a prime number.";
    else
        cout << n << " is not a prime number.";

    return 0;
}