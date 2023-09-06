#include <fstream>      // std::ofstream
using namespace std;

int main() {
    //ofstream ofs("out.txt", ofstream::out);
    ofstream ofs("test.txt", ofstream::app);
                            //open mode: append -> adding content
    
    ofs << "You are so kind.\n";

    ofs.close();
    return 0;
}