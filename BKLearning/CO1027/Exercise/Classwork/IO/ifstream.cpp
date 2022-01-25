// print the content of a text file.
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
using namespace std;
int main() {
    //declare
        ifstream ifs; 

    // open file
        ifs.open("text.txt", ifstream::in); 
                            //open mode: input -> open for reading
    
    //read file
        char c = ifs.get();
        while (ifs.good()) { 
        cout << c;
        c = ifs.get();
        }

    //close file
        ifs.close();
        return 0;
}