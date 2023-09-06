#include <fstream>      // std::ofstream
using namespace std;

int main() {
    ofstream MyFile("test.txt");
        //ofstream ofs("test.txt", ofstream::out);

    MyFile << "Hello Nhi!\n";
        //ofs << "Hello!\n";

    MyFile.close();
        //ofs.close();

    return 0;
}