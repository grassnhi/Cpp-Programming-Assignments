#include <iostream>
#include <stack>
#include <string>

using namespace std;

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


int main(){
    string s = "aabbbdddadd";
    int k = 3;
    cout << deleteDuplicate(s, k);
}