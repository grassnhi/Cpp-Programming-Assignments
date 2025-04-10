/*
Viết hàm void printFirstRepeatedWord(char str[]) in ra từ đầu tiên trong chuỗi bị lặp lại. Từ bị lặp lại trong một chuỗi là từ mà từ vị trí của nó trở về phía trước có xuất hiện một từ giống với nó.
- Đầu vào:

Mảng kí tự chứa chuỗi

- Đầu ra:

In ra từ đầu tiên trong chuỗi có lặp lại. Nếu không có từ nào lặp lại thì in ra "No Repetition"

- Các thư viện có thể dùng: <iostream>, <cstring>

- Note: Sinh viên không được sử dụng các từ khoá sau trong đoạn code nộp bài, kể cả trong comment: "include", "string". Mỗi từ trong chuỗi có không quá 30 ký tự.

 

---------------------------------------

Implement void printFirstRepeatedWord(char str[]) function which print the first word that repeats. In a string, a repeated word is a word that, from its position to the left, has a similar word appearing before it.

- Input:

Char array contains string

- Output:

Print the first word that has repetition. If there is no repeated word, print "No Repetition"

- Available library: <iostream>, <cstring>

- Note: Your code MUST NOT contain any of the words in the list {"include", "string"} even in the comment. Each word in the string has no more than 30 characters.
*/

using namespace std;
#include <iostream>
#include <cstring>

#  pragma once
using namespace std;

void printFirstRepeatedWord(char str[]) {
    char words[100][31]; // Mảng lưu tối đa 100 từ, mỗi từ 30 ký tự + 1 '\0'
    int wordCount = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        char temp[31]; // Mảng tạm lưu từ hiện tại
        int k = 0;
        
        // Bỏ qua khoảng trắng
        while (str[i] == ' ') {
            // cout << i << "-" <<  str[i] << " ";
            i++;
        }
        cout << endl;

        // Lấy từ
        while (str[i] != ' ' && str[i] != '\0') {
            cout << i << "-" << str[i] << " ";
            temp[k++] = str[i++];
            
        }
        cout << endl;
        temp[k] = '\0'; // Kết thúc từ
        
        if (k > 0) { // Có từ
            // Kiểm tra trùng với từ trước đó
            for (int j = 0; j < wordCount; j++) {
                if (strcmp(words[j], temp) == 0) {
                    cout << temp << endl;
                    return;
                }
            }
            // Lưu từ vào mảng
            strcpy(words[wordCount], temp);
            wordCount++;
        }
    }
    
    // Nếu không tìm thấy từ lặp
    cout << "No Repetition" << endl;
}

void printFirstRepeatedWord_NHI(char str[]) {
    // TODO
    char collect[100][31];
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        char temp[31];
        int k = 0;
        
        while(str[i] == ' '){
            i++;
        }
        
        while(str[i] != ' ' && str[i] != '\0'){
            temp[k++] = str[i++];
        }
        temp[k] = '\0';
        
        if(k > 0){
            for(int j = 0; j < count; j++){
                if(strcmp(collect[j],temp) == 0){
                    cout << temp << endl;
                    return;
                }
            }
            
            strcpy(collect[count], temp);
            count++;
        }
    }
    
    cout << "No Repetition" << endl;
}    

int main() {
    char str1[] = "car taxi bike bike car taxi";
    printFirstRepeatedWord(str1); // Output: bike
    
    char str2[] = "football voleyball badminton football";
    printFirstRepeatedWord(str2); // Output: football
    
    char str3[] = "apple banana cherry";
    printFirstRepeatedWord(str3); // Output: No Repetition
    
    return 0;
}
