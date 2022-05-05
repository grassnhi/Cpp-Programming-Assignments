#include <iostream>
#include <string>
using namespace std;

int main() {
  string food = "Chicken";
  string &meal = food;

  cout << &food << "\n";
  cout << &meal << "\n";

  cout << food << "\n";
  cout << meal << "\n";

  return 0;
}