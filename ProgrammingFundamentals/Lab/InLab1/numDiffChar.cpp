/*
[Tiếng Việt]

Sinh viên hiện thực hàm int numberOfDiffCharac(string str)  để trả về số kí tự phân biệt trong chuỗi str.

Lưu ý: Chuỗi str chỉ bao gồm các kí tự từ a đến z (các chữ cái lower case trong bảng chữ cái tiếng anh)

[English]

Implement int numberOfDiffCharac(string str) function which returns number of distinct character in a string.

Note: str string contains only lower character from a to z

 

 

For example:

Test	Result
char str[] ="aa";
printf("%d", numberOfDiffCharac(str));
1
char str[] ="ababbba";
printf("%d", numberOfDiffCharac(str));
2

*/

int numberOfDiffCharac(string str) {
    bool chars[26] = {false};
    for(size_t  i = 0; i < str.length(); i++){
        chars[str[i] - 'a'] = true;
    }
    
    int count = 0;
    for(int i = 0; i < 26; i++){
        if(chars[i]){
            count++;
        }
    }

    return count;
}