#include <fstream>      // std::ofstream
using namespace std;

int main() {
    ofstream MyFile("test.txt", ofstream::app);
        //ofstream ofs("test.txt", ofstream::app);

    MyFile << "You are my best friend.\n";
        //ofs << "Hello!\n";

    MyFile.close();
        //ofs.close();

    return 0;
}