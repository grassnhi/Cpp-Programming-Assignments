// C++ program to evaluate value of a postfix
// expression having multiple digit operands
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "1c.h"

using namespace std;

//POSTFIX EVALUATTION
double evaluatePostfix(string exp)
{
    // Create a stack of capacity equal to expression size
    Stack* stack = createStack(exp.length());
    int i;
 
    // See if stack was created successfully
    if (!stack) return -1;
 
    // Scan all characters one by one
    for (i = 0; exp[i]; i++)
    {
        //if the character is blank space then continue
        if(exp[i] == ' ')continue;
         
        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.

        //if (exp[i+1] != ')
        //{
                //string num += 'exp[i]
        //}
        else if (isdigit(exp[i]))
        {
            double result = 0;
            double dec = 1;
            // lấy phần thực
            while (exp[i] != '.' &&  exp[i] != ' ' && exp[i] != '\0'){
                result = result*10 + (exp[i] -'0');
                i = i + 1;
            }

            if (exp[i] == '.'){
                i++;
                while(exp[i] != ' ' && exp[i] != '\0'){
                    dec /= 10;
                    result += (exp[i] - '0')*dec;
                    i++;
                }
            }
            //push the element in the stack      
            push(stack,result);
        } 
         
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            double val1 = pop(stack);
            double val2 = pop(stack);
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2 / val1); break;
            //case '^': push(stack, pow(val2,val1)); break;
            }
        }
    }
    return pop(stack);
}

//PREFIX EVALUATION
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
    string exp;
    getline(cin, exp);
    if (isdigit(exp[0])) cout << "Postfix evaluation: " << evaluatePostfix(exp);
    else cout << "Prefix evaluation: " << evaluatePrefix(exp);
    return 0;
}