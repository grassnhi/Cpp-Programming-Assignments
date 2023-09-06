#include <fstream>
#include <iostream>

int main() {
  std::ofstream outfile;
  outfile.open("example.txt");

  if (outfile.is_open()) {
    outfile << "This is line 1." << std::endl;
    outfile << "This is line 2." << std::endl;
    outfile.close();
    std::cout << "File written successfully!" << std::endl;
  }
  else {
    std::cout << "Unable to open file." << std::endl;
  }

  return 0;
}
