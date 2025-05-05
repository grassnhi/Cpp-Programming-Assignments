/*
[Tiếng Việt]

 

Cho một chuỗi, hiện thực hàm 

 

int strLen(char* str){} 
 

để tính độ dài của chuỗi sử dụng đệ quy.

Lưu ý không được sử dụng các từ khóa như for, while, goto (thậm chí là tên biến, comment).

Trong bài tập này đã khai báo #include <iostream> và  using namespace std;

[English]

 

 

Given a string, implement function

 

int strLen(char* str){}
 

to calculate length of the string using recursion.

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream> and using namespace std;




 

For example:

Test	Result
char str[] = "Truong DH Bach Khoa";
cout << strLen(str);
19

*/

int strLen(char* str)     
{ 
    /*  
     * STUDENT ANSWER
     */
     
    if( *str == '\0'){
        return 0;
    }
    return 1 + strLen(str+1);
}