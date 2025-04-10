/*
Viết hàm void process(const char str[], char outstr[]) loại bỏ các khoảng trắng thừa trong chuỗi sao cho không còn hai khoảng trắng liền kề nhau và không có khoảng trắng nào ở đầu và cuối chuỗi.

- Đầu vào:

Mảng kí tự chứa chuỗi cần loại bỏ khoảng trắng

- Đầu ra:

Kết quả của bài toán được ghi vào chuỗi outstr

- Các thư viện có thể dùng: <iostream>, <cstring>

- Note: Sinh viên không được sử dụng các từ khoá sau trong đoạn code nộp bài, kể cả trong comment: "include", "string"

---------------------------------------

Implement void process(const char str[], char outstr[]) function which eliminates redundant space characters so that there are no consecutive space characters and there is no space character at the beginning/end of string.

- Input:

Char array contains the string

- Output:

The result is written to outstr

- Available library: <iostream>, <cstring>

- Note: Your code MUST NOT contain any of the words in the list {"include", "string"} even in the comment


*/

using namespace std;
#include <iostream>
#include <cstring>

void process(const char str[], char outstr[]) {
    int i = 0, j = 0;
    int len = strlen(str);

    // Bỏ qua khoảng trắng ở đầu
    while (i < len && str[i] == ' ') {
        i++;
    }

    bool spaceFound = false; // Cờ kiểm tra khoảng trắng

    while (i < len) {
        if (str[i] != ' ') {
            outstr[j++] = str[i];
            spaceFound = false;
        } else {
            if (!spaceFound) { // Thêm 1 khoảng trắng duy nhất
                outstr[j++] = ' ';
                spaceFound = true;
            }
        }
        i++;
    }

    // Xóa khoảng trắng ở cuối
    if (j > 0 && outstr[j - 1] == ' ') {
        j--;
    }

    outstr[j] = '\0'; // Kết thúc chuỗi
}


void process_NHI(char str[], char outstr[]) {
    // TODO
    int i = 0, j = 0;
    while(str[i] == ' '){
        i++;
    }
    while(str[i] != '\0'){
        while(str[i] == ' ' && str[i+1] == ' '){
            i++;
        }
        outstr[j++] = str[i++];
    }
    while(j > 0 && outstr[j - 1] == ' '){
        j--;
    }
    outstr[j] = '\0';
}

int main() {
    const int MAX_SIZE = 100;
    char str[] = "  abc  def  ghi  ";
    char outstr[MAX_SIZE];
    process(str, outstr);
    cout << outstr << endl; // Output: abc def ghi

    char str2[] = "     hello    world   !   ";
    process(str2, outstr);
    cout << outstr << endl; // Output: hello world !

    return 0;
}
