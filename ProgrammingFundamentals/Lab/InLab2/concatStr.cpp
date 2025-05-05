/*
Mô tả tiếng Việt:

Hiện thực hàm char* concatStr(char* str1, char* str2) trả về một chuỗi là kết quả sau khi nối 2 chuỗi str1 và str2 thành một chuỗi duy duy nhất.

Đầu vào: Hai chuỗi str1 và str2.

Đầu ra: Chuỗi được nỗi từ 2 chuỗi con str1 và str2.

Lưu ý: Không được phép sử dụng các hàm hỗ trợ của thư viện string và string.h cho bài tập này.

English version:

Implement the function char* concatStr(char* str1, char* str2) that return a string merged from two smaller string str1 and str2.

Input: Two string str1 and str2.

Output: The string merged from two smaller string str1 and str2.

Note: The string and string.h library are not allowed to use for this exercise.

For example:

Test	Result
char s1[] = "Hello, ";
char s2[] = "how are you?";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;
Hello, how are you?
char s1[] = "Nice to ";
char s2[] = "meet you.";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;
Nice to meet you.
char s1[] = "Nice ";
char s2[] = "to meet ";
char s3[] = "you.";
char* temp = concatStr(s1, s2);
char* s = concatStr(temp, s3);
cout << s;
delete[] s; delete[] temp;
Nice to meet you.
char s1[] = "Ho Chi Minh ";
char s2[] = "University ";
char s3[] = "of Technology.";
char* temp = concatStr(s1, s2);
char* s = concatStr(temp, s3);
cout << s;
delete[] s; delete[] temp;
Ho Chi Minh University of Technology.
char s1[] = "This question ";
char s2[] = "is as easy as ";
char s3[] = "the other.";
char* temp = concatStr(s1, s2);
char* s = concatStr(temp, s3);
cout << s;
delete[] s; delete[] temp;
This question is as easy as the other.
char s1[] = "That's ";
char s2[] = "a good idea.";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;
That's a good idea.
char s1[] = "123";
char s2[] = "456";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;
123456
char s1[] = "";
char s2[] = "CSE";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;
CSE
char s1[] = "";
char s2[] = "";
char* s = concatStr(s1, s2);
cout << s;
delete[] s;

*/

char* concatStr(char* str1, char* str2) {
    // TODO
    int len1 = 0;
    while (str1[len1] != '\0'){
        len1++;
    }
    
    int len2 = 0;
    while(str2[len2] != '\0'){
        len2++;
    }
    
    char* str = new char[len1 + len2 + 1];
    
    for(int i = 0; i < len1 ; i++){
        str[i] = str1[i];
    }
    
    for(int i = 0; i < len2; i++){
        str[len1+i] = str2[i];
    }
    
    str[len1+len2] = '\0';
    
    return str;
}