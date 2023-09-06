#include <iostream>
#include <stack>
#include <string>

bool is_balanced(const std::string &expression) {
  std::stack<char> stack;
  for (char c : expression) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (stack.empty()) {
        return false;
      }
      char top = stack.top();
      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
      stack.pop();
    }
  }
  return stack.empty();
}

int main() {
  std::string expression;
  std::cout << "Enter an expression with brackets: ";
  std::cin >> expression;
  if (is_balanced(expression)) {
    std::cout << "The expression has balanced brackets." << std::endl;
  } else {
    std::cout << "The expression does not have balanced brackets." << std::endl;
  }
  return 0;
}
