#include <iostream>  
using namespace std;

int main() {
    int i, j;
    
    for (i = 5, j = 10; i + j < 20; i++, j++) {
		cout << "i + j = " << (i + j) << '\n';
    }
    
    //initialization and modification can contain multiple statements separated by commas.

    return 0;
}