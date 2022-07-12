
// C++ program to evaluate a prefix expression.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

double evaluatePrefix(string exp)
{
    
    stack<double> Stack;
    for (int j = exp.length() - 1; j >= 0; j--) {

        // if jth character is the delimiter ( which is
        // space in this case) then skip it
        if (exp[j] == ' ') continue;
 
        else if (isdigit(exp[j])) {
            string t = "";
            int i = j;
            while(exp[i] != ' ') i--;
            i++;
            for (i; i <= j; i++){
                t += exp[i];
            }

            double result = stod(t);
            while(exp[j] != ' ') j--;
            j++;
            Stack.push(result);
        }

        else {

            double val1 = Stack.top();
            Stack.pop();
            double val2 = Stack.top();
            Stack.pop();
 
            switch (exp[j]) {
            case '+':
                Stack.push(val1 + val2);
                break;
            case '-':
                Stack.push(val1 - val2);
                break;
            case '*':
                Stack.push(val1 * val2);
                break;
            case '/':
                Stack.push(val1 / val2);
                break;
            }
        }
    }
 
    return Stack.top();
}
 

int main()
{
    string exprsn = "- * + 1 / 4.9 5.6 2.8 * 3 0.7";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}