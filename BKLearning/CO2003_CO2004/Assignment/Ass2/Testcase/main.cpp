#include "main.h"
#include "result.cpp"
//#include "restaurant.cpp"

int main(int argc, char* argv[]) {
    outfile.open("got\\got44.txt"); 
    string fileName = "input\\input44.txt";
    //string fileName = "test.txt";  
    simulate(fileName);
    outfile.close();

    return 0;
}
