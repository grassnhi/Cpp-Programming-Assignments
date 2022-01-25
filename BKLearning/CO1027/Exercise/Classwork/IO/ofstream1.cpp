#include <fstream>      // std::ofstream
using namespace std;

int main() {
    //create and write file
                // variable
        ofstream ofs("out.txt", ofstream::out);
        //data type             //open mode: output -> open for writting
                    // filename
    
    // write file
        ofs << "Hello!\n";

    ofs.close();
    return 0;
}