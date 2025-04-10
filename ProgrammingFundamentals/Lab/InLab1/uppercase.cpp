/*
Viết hàm void uppercase(string output) để đọc vào chuỗi S từ bàn phím, sau đó chuyển tất các ký tự trong chuỗi S thành ký tự viết HOA và xuất kết quả ra file output.

Chú ý: chỉ thay đổi các chữ cái in thường, các kí tự khác sẽ được giữ nguyên.


Đầu vào:

Biến "output" chứa tên file dùng để xuất kết quả.

Đầu ra:


Hàm đọc chuỗi S từ bàn phím và xử lý chuỗi như mô tả. Sau đó ghi chuỗi đã xử lý vào file có tên được chứa trong biến “output” (hàm không trả về kết quả).



Write a function void uppercase(string output) to read the string S from the keyboard, then convert all characters in string S to uppercase characters and output the result to the output file.

Note: change only lowercase letters, other characters will not change.

Input:

The variable "output" contains the filename used to output the result.

Output:

The function reads the string S from the keyboard and processes the string as described. Then write the processed string to a file whose name is contained in the variable “output” (the function does not return results).


*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void uppercase(string output) {
    string S;
    getline(cin, S); // Đọc cả dòng từ bàn phím, bao gồm cả dấu cách

    // Chuyển ký tự thường thành chữ hoa
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= 'a' && S[i] <= 'z') {
            S[i] = S[i] - ('a' - 'A'); // Hoặc: S[i] = toupper(S[i]);
        }
    }

    // Ghi chuỗi đã xử lý vào file
    ofstream fout(output);
    fout << S;
    fout.close();
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void uppercase(string output) {
    string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] -= ('a' - 'A');
        }
    }

    // Không gán output = input nữa!
    ofstream file(output); // Mở file đúng tên
    file << input;
    file.close();
}


int main() {
    uppercase("output.txt");
    return 0;
}

