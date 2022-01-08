#include <iostream>
using namespace std;

#define PI 3.1415  // no comma
        // declaring a constant named PI
        // usually declared at the beginning of the program

const int SCR_WIDTH = 1920; //global

int main(){
    const int SCR_HEIGHT = 1080;  //local

    cout << "PI = " << PI << endl;

    cout << "Screen width = " << SCR_WIDTH << endl;
    cout << "Screen height = " << SCR_HEIGHT << endl;

    return 0;
}