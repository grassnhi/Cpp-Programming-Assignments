/*
Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> st;
    string result = "";
    for(unsigned int i = 0; i < S.size(); i++){
        if (!st.empty() && st.top() == S[i]){
            st.pop();
        }else{
            st.push(S[i]);
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
cout << removeDuplicates("abbaca");
ca
cout << removeDuplicates("aab");
b
*/