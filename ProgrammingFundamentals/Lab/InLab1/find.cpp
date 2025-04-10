/*
Viết hàm int find(char str[], char substr[]) để tìm vị trí của chuỗi con trong một chuỗi cho trước. Hàm trả về vị trí đầu tiên của chuỗi con trong chuỗi ban đầu. Nếu không tìm thấy chuỗi con, hàm trả về -1.

- Mô tả hàm: Hàm này thực hiện việc tìm kiếm chuỗi con trong chuỗi ban đầu và trả về vị trí đầu tiên của chuỗi con nếu được tìm thấy. Nếu không tìm thấy, hàm trả về -1.

- Đầu vào: 

char str[]: Mảng kí tự chứa chuỗi ban đầu.

char substr[]: Mảng kí tự chứa chuỗi con cần tìm.

- Đầu ra:

int: Vị trí đầu tiên của chuỗi con trong chuỗi ban đầu. Nếu không tìm thấy, trả về -1.

- Các thư viện có thể dùng: <iostream>, <cstring>

- Note: Sinh viên không được sử dụng các từ khoá sau trong đoạn code nộp bài, kể cả trong comment: "include", "string"
Tham số truyền vào: 

---------------------------------------

Implement the int find(char str[], char substr[]) function to find the position of a substring in a given string. The function returns the position of the first occurrence of the substring in the original string. If the substring is not found, the function returns -1.

- Function Description: This function searches for the substring in the original string and returns the position of the first occurrence of the substring if found. If not found, it returns -1.

- Input:

char str[]: Character array containing the original string.

char substr[]: Character array containing the substring to search for.

- Output:

int: The position of the first occurrence of the substring in the original string. If not found, returns -1.

- Available library: <iostream>, <cstring>

- Note: Your code MUST NOT contain any of the words in the list {"include", "string"} even in the comment
*/

#include <iostream>

using namespace std;

int find(char str[], char substr[]) {
    int lenStr = 0, lenSub = 0;
    
    // Tính độ dài chuỗi str
    while (str[lenStr] != '\0') {
        lenStr++;
    }
    
    // Tính độ dài chuỗi substr
    while (substr[lenSub] != '\0') {
        lenSub++;
    }
    
    // Duyệt từng vị trí trong str để kiểm tra
    for (int i = 0; i <= lenStr - lenSub; i++) {
        bool found = true;
        for (int j = 0; j < lenSub; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; // Vị trí đầu tiên tìm thấy
        }
    }
    
    return -1; // Không tìm thấy
}

int main() {
    char str[] = "hello world";
    char substr[] = "world";
    cout << find(str, substr) << endl;
    return 0;
}
