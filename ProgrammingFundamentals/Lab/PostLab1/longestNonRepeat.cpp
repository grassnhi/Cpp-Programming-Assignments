/*
[Tiếng Việt ]

 

Viết chương trình tìm và trả về độ dài của chuỗi con dài nhất không có ký tự nào được lặp lại có trong s.

Đầu vào:

Chuỗi s.

Đầu ra:

Độ dài của chuỗi con dài nhất không có ký tự nào được lặp lại có trong s.

 

[English ]

Write a program find and return the length of the longest sub-string that doesn't have any repeated character in s.

Input:

String s.

Output:

Length of the longest sub-string that doesn't have any repeated character in s.

*/

#include <iostream>
#include <string>
using namespace std;

int longestNonRepeatSubString(string s) {
    // TO DO 
    bool chars[128] = {false};
    int left = 0;
    int maxlen = 0;
    for(int right = 0; right < s.length(); right++){
        while(chars[s[right]]){
            chars[s[left]] = false;
            left++;
        }
        chars[s[right]] = true;
        maxlen = max(right-left+1, maxlen);
    }
    return maxlen;
}

int main()  {
    string s;
    cin >> s;
    cout << longestNonRepeatSubString(s);
    return 0;
}

int longestNonRepeatSubString(string s) {
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        bool visited[256] = {false}; // Đánh dấu ký tự đã xuất hiện

        for (int j = i; j < n; j++) {
            if (visited[(unsigned char)s[j]]) {
                break; // Ký tự bị lặp, dừng lại
            }
            visited[(unsigned char)s[j]] = true;
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
            }
        }
    }
    return maxLen;
}

/*----------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int longestNonRepeatSubString(string s) {
    // TO DO 
    if (s.length() == 0) return 0;
    
    // Array to store frequency of characters (ASCII characters)
    int charCount[256] = {0};
    
    // Two pointers for sliding window
    int left = 0;
    int maxLength = 0;
    
    // Iterate through string with right pointer
    for (int right = 0; right < s.length(); right++) {
        // Increment count of current character
        charCount[s[right]]++;
        
        // If we find a repeating character, move left pointer
        while (charCount[s[right]] > 1) {
            charCount[s[left]]--;
            left++;
        }
        
        // Update maxLength if current window is larger
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main()  {
    string s;
    cin >> s;
    cout << longestNonRepeatSubString(s);
    return 0;
}
*/
