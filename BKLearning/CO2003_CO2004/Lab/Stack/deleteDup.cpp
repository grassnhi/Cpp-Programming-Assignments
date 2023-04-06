/*
Given a string s and an integer k (k >= 1). Manipulate the string following these rules:

- Repeatly delete the earliest k-consecutive characters appear in string s. 

- There is no k-consecutive characters in the final string (after manipulating).

Request: Implement function

string deleteDuplicate(string s, int k);

To return the final string.

Example:

- deleteDuplicate("aabbbdddadd", 3).

- The final string returned is dd.

- Explanation: Firstly, delete the "bbb" to get "aadddadd", then delete "ddd" to get "aaadd", then delete "aaa" and final string is "dd".

Note: In this exercise, libraries iostream, stack, utility and using namespace std have been used. You can add other functions; however, you are not allowed to add other libraries.
*/

string deleteDuplicate(string s, int k) {
    if(k == 1) return "";
    stack<pair<char, int>> stk; // pair of character and count
    for (char c : s) {
        if (!stk.empty() && stk.top().first == c) {
            stk.top().second++; // increment count
            if (stk.top().second == k) {
                stk.pop(); // remove k-consecutive characters
            }
        } else {
            stk.push({c, 1}); // add new character with count 1
        }
    }
    string result;
    while (!stk.empty()) {
        for (int i = 0; i < stk.top().second; i++) {
            result = stk.top().first + result; // build result in reverse order
        }
        stk.pop();
    }
    return result;
}

string deleteDuplicate(string s, int k) {
    stack<char> st;
    string result = "";
    int count = 0;
    for(unsigned int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        }else{
            if(s[i] == st.top()){
                int count = 1;
                while (!st.empty() && s[i] == st.top())
                {
                    count++;
                    st.pop();
                }
                if(count != k){
                    while (count != 0)
                    {
                        st.push(s[i]);
                        count--;
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
    }
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}


/*
Test	Result
string s = "aabbbdddadd";
int k = 3;
cout << deleteDuplicate(s, k);
dd
string s = "aaabbbbccddddefffghiiiiihhhhggggffda";
int k = 5;
cout << deleteDuplicate(s, k);
aaabbbbccddddeda
*/