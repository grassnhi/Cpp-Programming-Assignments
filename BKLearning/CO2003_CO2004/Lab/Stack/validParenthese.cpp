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

bool isValidParentheses (string s){
    /*TODO*/
    stack<char> stk;
    for(char c : s){
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                return false;
            }
            if ((c == ')' && stk.top() != '(') ||
                (c == ']' && stk.top() != '[') ||
                (c == '}' && stk.top() != '{')) {
                return false;
            }
            stk.pop();
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