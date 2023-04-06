/*
Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
For example:

String "[]()" is a valid string, also "[()]".
String "[])" is not a valid string.
Your task is to implement the function
bool isValidParentheses (string s){
    /*TODO*//*
}
*/

bool isValidParentheses(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                return false;
            }
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stk.empty();
}


/*
Test	Result
cout << isValidParentheses("[]");
1
cout << isValidParentheses("[]()");
1
cout << isValidParentheses("[)");
0

*/