/*
[Tiếng Việt]
Viết hàm tìm chữ cái xuất hiện nhiều lần nhất trong một chuỗi và số lần xuất hiện của chữ cái đó. Nếu có nhiều chữ cái thỏa mãn, xác định chữ cái có thứ tự alphabet nhỏ nhất.

Đầu vào:
const char* str: chuỗi ký tự đang xét, chỉ bao gồm chữ cái thường và hoa
 

Đầu ra:
char& res: chữ cái xuất hiện nhiều lần nhất trong chuỗi str
int& freq: số lần xuất hiện của chữ cái đó

Chú ý: tham số res là chữ cái thường. Chữ cái viết hoa strong str cũng được tính là giống chữ cái viết thường (VD "aA" chứa hai ký tự 'a')

Lưu ý: Sinh viên chỉ có 5 lần nộp không tính penalty, ở lần nộp thứ 6 trở đi bài làm sẽ được tính là 0 điểm.

[English]
Write a function that finds the most frequent character in a given string and how many times that character appears. If there are multiple characters satisfy the condition, find the one with the lowest alphabetical order.

Input:
const char* str: the input string, contains only lowercase and uppercase ASCII letters

Output:
char& res: the most frequent character in str 
int& freq: the times that the result character appears in the string

Note: return res as a lowercase letter. Uppercase letters in str is also counted as lowercase letters (e.g the string "aA" contains two letter 'a')
*/

#include <iostream>
#include <cstring> // Dùng strlen()

using namespace std;

// Hàm tìm ký tự xuất hiện nhiều nhất
void mostFrequentCharacter(const char* str, char& res, int& freq) {
    int count[26] = {0}; // Mảng đếm số lần xuất hiện của các chữ cái từ 'a' đến 'z'

    // Duyệt qua chuỗi và đếm số lần xuất hiện
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32; // Chuyển chữ hoa thành chữ thường bằng cách cộng 32
        }
        count[ch - 'a']++; // Tăng số lần xuất hiện của ký tự đó
    }

    // Tìm ký tự có tần suất xuất hiện nhiều nhất
    freq = 0;
    res = 'z'; // Khởi tạo với giá trị lớn để cập nhật dễ hơn

    for (int i = 0; i < 26; i++) {
        if (count[i] > freq) { // Nếu có tần suất cao hơn, cập nhật
            freq = count[i];
            res = 'a' + i;
        }
    }
}

// Hàm chính
int main() {
    int n;
    cin >> n; // Nhập số lượng ký tự trong chuỗi

    char* str = new char[n + 1]; // Cấp phát động mảng để chứa chuỗi
    for (int i = 0; i < n; i++) {
        cin >> str[i]; // Nhập từng ký tự
    }
    str[n] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null

    char res = 0; // Biến lưu ký tự xuất hiện nhiều nhất
    int freq = 0; // Biến lưu số lần xuất hiện của ký tự đó

    mostFrequentCharacter(str, res, freq); // Gọi hàm xử lý

    cout << res << " " << freq << endl; // In kết quả

    delete[] str; // Giải phóng bộ nhớ

    return 0;
}
