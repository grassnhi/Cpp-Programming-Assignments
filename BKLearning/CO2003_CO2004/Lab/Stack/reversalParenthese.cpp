/*
Given a string consisting of 'a'-'z' and brackets '(' and ')'.
Your task is to implement a function with following prototype:
string parenthesesReversal(string s);
The function returns the string after recursively reversing every string enclosed between brackets.

Note:
- The iostream, vector and stack libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverseSubstring(string& s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string parenthesesReversal(string s) {
    // STUDENT ANSWER
    stack<char> st;
    string result = "";
    for (unsigned int i = 0; i < s.size(); i++) {
        st.push(s[i]);
        if(s[i] == ')'){
            st.pop();
            string rev = "";
            while (st.top() != '(')
            {
                rev += st.top();
                st.pop();
            }
            st.pop();
            for(unsigned int j = 0; j < rev.size(); j++){
                st.push(rev[j]);
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

int main() {
    string s = "vi(ik)kq";
    cout << parenthesesReversal(s) << endl;
    string s1 = "dblcblpb(vgmoj(dbmvy))";  // dblcblpbdbmvyjomgv
    cout << parenthesesReversal(s1) << endl;
    return 0;
}


/*
Test	Result
string s = "vi(ik)kq";
cout << parenthesesReversal(s);
vikikq
string s = "jeadm(ikq)dghlv(q(p)okihwuwshgzufaangetetu)aw(dvuunwr)(qvnvim(pxiitwv)whcv)pb(amas((nar)h)t(tixs()uynmjeeitpeejbkhdlfslunedyjdhpoigda(vbamwyay)kmvs)lp)da(bh)nxu(lbwkxz(cw(rehyejwtl(blzjp(iiv)sncjvdu((uqtycjou(lu(iutzzvajintwz((ftv)tguyectqgusnkcy)zcjqvlh)irkiytrirxuowgoyiacmkbrg(owezrimrf)boxh(mor)sxzlb(rsrtp)wozj()pjnmez(lezanwxgmmvwr(kxs(ahxqbcxgtobqnn)nktbrmnpxkjbqxsobl)(x)kvrfukmyapjohkgrktkyshmbmwc)ymrefqrajn(ireosiwqqfnohgcrgwmtnrbjziiwklxosmlxmwsgrer)hkbgz(d)orsdv)wxpvvvky(uwqnkzangdmejqr)))))))";
cout << parenthesesReversal(s);
*/

